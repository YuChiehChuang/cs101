#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define counterFile "counter.bin"
#define operatorFile "operator_id.bin"
#define maxLottoNum 7
#define maxLottoNumSet 5

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

void set_operatorID(int operator_id) {
	int opArray[1];
	opArray[0] = operator_id;
	FILE* tmpfp = fopen(operatorFile, "wb");
	fwrite(opArray, sizeof(int), 1, tmpfp);
	fclose(tmpfp);
}

void do_lotto_main(int counter) {  //�}�Y 
	char lottoFile[32];  //�O���ɦW 
	int numSet = 0;  //�R�X�� 
	int operator_id;  //ID
	snprintf(lottoFile, 32, "lotto[%05d].txt", counter);  //��᭱���ɮצW�ƻs��lottoFile 
	printf("�w����{�����ֳz�m�ʶR���x\n");
	printf("�п�J�ާ@�H��ID : ");
	scanf("%d", &operator_id);
	printf("�аݱz�n�ʶR�X��(1~5) : ");
	scanf("%d", &numSet);
	print_lottofile(numSet, counter, lottoFile, operator_id);
	set_operatorID(operator_id);
	printf("�w���z�ʶR�� %d �ռֳz�զX��X�� %s\n", numSet, lottoFile);
}





void set_counter(int counter) {  //�O��counter++ 
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
	set_counter(counter);  //�O��counter++ 
	return 0; 
} 
