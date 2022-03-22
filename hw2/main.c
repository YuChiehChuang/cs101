#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define counterFile "counter.bin"
#define operatorFile "operator_id.bin"
#define recordFile "records.bin"
#define maxLottoNum 7
#define maxLottoNumSet 5

typedef struct lotto_record {
    int lotto_no;  //�s��(counter)
    float lotto_receipt;  //����(�ռ�*50*1.1)
    int emp_id;  //id(input)
    char lotto_date[16];  //���
    char lotto_time[16];  //�ɶ�
} lotto_record_t;
lotto_record_t record;

typedef struct emp_record {  //ID��0�~�n���� 
	int emp_id;
	char emp_name[50];
	int emp_salary;
} emp_record_t;
emp_record_t empRecord;

int frecord(int counter, int operator_id, int numSet) {
	time_t curtime = time(0);
    record.lotto_no = counter;
    record.lotto_receipt = ((counter*50) + (numSet*50) * 1.1);
    record.emp_id = operator_id;
    strftime(record.lotto_date, 100, "%Y%m%d", localtime(&curtime));  //���
    strftime(record.lotto_time, 100, "%H:%M:%S", localtime(&curtime));  //�ɶ�
    FILE* fre = fopen(recordFile, "ab");
    fwrite(&record, sizeof(record), 1, fre);
    fclose(fre);
}

void init_file() {  //�P�_���Lcounter.bin
	int writeArray[1] = {0};
	FILE* fp = fopen(counterFile, "r");  //�����}(��Ū)
	if(fp == NULL) {  //�Y�L���ɮ�
		FILE* tmpfp = fopen(counterFile, "wb+");  //�}�@�ӷs�� 
		fwrite(writeArray, sizeof(int), 1, tmpfp);  //�g�i�h"No.0" 
		fclose(tmpfp);
	} else {  //�Y�� 
		fclose(fp);  //���������A��������
	}
}

int get_counter() {  //Ū��counter.bin(�g�JreadArray[0]) 
	int readArray[1];
	FILE* tmpfp = fopen(counterFile, "rb");  //��Ū
	fread(readArray, sizeof(int), 1, tmpfp);  //�NŪ��counter.bin(tmpfp)�����G�g�JcounterArray
	fclose(tmpfp);
	return readArray[0];
}

int num_in_numset(int num, int numSet[], int Len) {  //�ˬd�O�_���� 
	int ret = 0;
	for(int i = 0 ; i < Len ; i++) {
		if(num == numSet[i]) {
			ret = 1;
			break;  //���Xfor�j�� 
		}
	}
	return ret;  //1:True  0:False 
}

void print_lotto_row(FILE* tmpfp, int n) {
	int numSet[maxLottoNum];
	
	//generate lotto row ���͸��X(�ü�)  
	fprintf(tmpfp, "[%d] : ", n);
	for(int i = 0 ; i < maxLottoNum-1 ; ) {  //���q�Ʀr  
		int num = rand() % 69 + 1;
		if(num_in_numset(num, numSet, maxLottoNum-1)) {  //(�U�@�Ө禡)
			continue;  //���ƴN�~��for�j�� 
		} else {
			numSet[i] = num;  //��i�}�C
			i++;  //�U�@��
		}
	}
	for(int i = 0 ; i < 1 ; ) {  //�S�O�Ʀr
		int num = rand() % 10 + 1;
		if(num_in_numset(num, numSet, maxLottoNum-1)) {
			continue;
		} else {
			numSet[maxLottoNum-1] = num;
			i++;
		}
	}
	
	//sorting lotto row �Ƨ�
	for(int i = 0 ; i < maxLottoNum-1 ; ++i) {
		for(int j = 0 ; j < i ; ++j) {
			if(numSet[j] > numSet[i]) {
				int temp = numSet[j];
				numSet[j] = numSet[i];
				numSet[i] = temp;
			}
		}
	}
	
	//output lotto row �L���X
	for(int i = 0 ; i < maxLottoNum ; i++) {  
		fprintf(tmpfp, "%02d ", numSet[i]);
	}
	fprintf(tmpfp, "\n");
}

void print_lottofile(int numSet, int counter, char lottoFile[], int operator_id) {
	time_t curtime;
	time(&curtime);
	
	FILE* tmpfp = fopen(lottoFile, "w+");  //lottoFile[32]
	fprintf(tmpfp, "========= lotto649 =========\n");
	fprintf(tmpfp, "========+ No.%05d +========\n", counter);
	fprintf(tmpfp, "= %.*s =\n", 24, ctime(&curtime));  //�L�ثe�ɶ��A����g24��
	
	for(int i = 0 ; i < maxLottoNumSet ; i++) {  //�L�������� 
		if(i < numSet) {
			print_lotto_row(tmpfp, i+1);
		} else {
			fprintf(tmpfp, "[%d] : -- -- -- -- -- -- --\n", i+1);
		}
	}
	
	fprintf(tmpfp, "========* Op.%05d *========\n", operator_id);
	fprintf(tmpfp, "========= csie@CGU =========\n");
	fclose(tmpfp);
}

int femp(int operator_id, char operator_name[], int operator_salary) {
	empRecord.emp_id = operator_id;
	for(int i = 0 ; i < 50 ; i++) {
		empRecord.emp_name[i] = operator_name[i];
	}
	empRecord.emp_salary = operator_salary;
	FILE* fp = fopen(operatorFile, "ab");
	fwrite(&empRecord, sizeof(empRecord), 1, fp);
	fclose(fp);
	return 0;
}

int ID = 0;  //�O��operator_id 

void set_operatorID(int operator_id) {
	int opArray[1];
	opArray[0] = operator_id;
	ID = opArray[0];
	FILE* tmpfp = fopen(operatorFile, "wb");
	fwrite(opArray, sizeof(int), 1, tmpfp);
	fclose(tmpfp);
}

int quan = 0;  //�O��numSet 

void do_lotto_main(int counter) {  //�}�Y 
	char lottoFile[32];  //�O���ɦW 
	int numSet = 0;  //�R�X��
	int operator_id;  //ID
	char operator_name[50];
	int operator_salary;
	snprintf(lottoFile, 32, "lotto[%05d].txt", counter);  //��᭱���ɮצW�ƻs��lottoFile
	printf("�w����{�����ֳz�m�ʶR���x\n");
	printf("�п�J�ާ@�H��ID : ");
	scanf("%d", &operator_id);
	if(operator_id != 0){  //ID����0�� 
		printf("�аݱz�n�ʶR�X��(1~5) : ");
		scanf("%d", &numSet);
		quan = numSet;
		print_lottofile(numSet, counter, lottoFile, operator_id);
		set_operatorID(operator_id);
		printf("�w���z�ʶR�� %d �ռֳz�զX��X�� %s\n", numSet, lottoFile);
	} else {
		printf("�п�J�n�s�W�ާ@�H��ID(1-99) : \n");
		scanf("%d", &operator_id);
		printf("�п�J�n�s�W�ާ@�H��Name : \n");
		scanf("%s", &operator_name);
		printf("�п�J�n�s�W�ާ@�H��Salary : \n");
		scanf("%d", &operator_salary);
		printf("��J����\n");
		femp(operator_id, operator_name, operator_salary);
	}
	
}

void set_counter(int counter) {  ////�O��counter++ 
	int writeArray[1];
	writeArray[0] = counter;
	FILE* tmpfp = fopen(counterFile, "wb");
	fwrite(writeArray, sizeof(int), 1, tmpfp);
	fclose(tmpfp);
}

int main() {
	int counter;
	init_file();  //��l�ưO����
	counter = get_counter();  //Ū���O���� 
	do_lotto_main(++counter);  //�������j��
	int operator_id = ID;
    int numSet = quan;
    frecord(counter, ID, quan);
	set_counter(counter);  //�O��counter++
	return 0; 
} 