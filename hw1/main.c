#include<stdio.h>
#include<stdlib.h>
#include<time.h>

FILE* fp;
int num[6] = {0};

void lotto(void){
	int var, isExist, n = 0;
	for(int i = 0 ; i < 6 ; i++) {
		num[i] = 0;
	}
	
	while(n < 5){  //���q�Ʀr*5(0~4)
		var = rand() % 69 + 1;   
		isExist = 0;   
		for(int i = 0 ; i <= n ; i++) {  //�w�g���Ʀr����l 
			if(num[i] == var){  //�w�g�L����l����üƭ��� 
				isExist = 1;  //���ܪ��A 
			}
		}
		if(isExist == 0) {  //�S���� 
			num[n] = var;  //�g�i�h��l 
			n++;  //���U�@�� 
		}	//�����ƴN�~��while(�ϥ�n�S��) 
	}
	num[5] = rand() % 10 + 1;
	for(int i = 0 ; i < 6 ; i++) {  //�^�ǰ}�C 
		fprintf(fp, "%02d ", num[i]);
	}
}

int main(){
	int n=2;
	srand(time(NULL));
	printf("�w����{�����ֳz�m�ʶR���x\n�аݱz�n�R�X�ռֳz�m:");
	scanf("%d", &n);
	printf("�w���z�ʶR��%d�ռֳz�զX��X��lotto.txt", n);
	
	fp = fopen("lotto.txt", "w+");
	
	fprintf(fp, "======== lotto649 =========\n");
	
	time_t curtime;
	time(&curtime);

	fprintf(fp, "=%s", ctime(&curtime));

	for(int i = 0 ; i < n ; i++) {
		fprintf(fp, "[%d] : " ,i+1);
		lotto();
		fprintf(fp, "\n");
	}
	for(int k = 0 ; k < (5-n) ; k++) {
		fprintf(fp, "[%d] : ", n+k+1);
		for(int j = 0 ; j < 6 ; j++) {
			fprintf(fp, "-- ");
		}
		fprintf(fp, "\n");
	}
	fprintf(fp, "======== csie@CGU =========\n");
	fclose(fp);
}
