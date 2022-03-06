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
	while(n < 5){  //普通數字*5(0~4)
		var = rand() % 69 + 1;   
		isExist = 0;   
		for(int i = 0 ; i <= n ; i++) {  //已經有數字的格子 
			if(num[i] == var){  //已經過的格子有跟亂數重複 
				isExist = 1;  //改變狀態 
			}
		}
		if(isExist == 0) {  //沒重複 
			num[n] = var;  //寫進去格子 
			n++;  //換下一行 
		}	//有重複就繼續while(反正n沒變) 
	}
	for (int i = 0; i < 5; ++i) {
	    for (int j = 0; j < i; ++j) {
		    if (num[j] > num[i]) {
			    int temp = num[j];
			    num[j] = num[i];
			    num[i] = temp;
		    }
	    }
	}
	num[5] = rand() % 10 + 1;
	for(int i = 0 ; i < 6 ; i++) {  //回傳陣列 
		fprintf(fp, "%02d ", num[i]);
	}
}
int main(){
	int n;
	srand(time(NULL));
	printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩:");
	scanf("%d", &n);
	printf("已為您購買的%d組樂透組合輸出至lotto.txt", n);
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
