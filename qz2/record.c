#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define seeRecord "Report.txt"

typedef struct lotto_record {
    int lotto_no;  //�s��(counter)
    float lotto_receipt;  //����(�ռ�*50*1.1)
    int emp_id;  //id(input)
    char lotto_date[16];  //���
    char lotto_time[16];  //�ɶ�
} lotto_record_t;

void ftime() {  //�L��� 
	char date[16];
	time_t curtime = time(0);
    strftime(date, 100, "%Y%m%d", localtime(&curtime));  //���
}

void print_file(char date[]) {
	FILE* tmpfp = fopen(seeRecord, "w+");  
	fprintf(tmpfp, "========= lotto649 Report =========\n");
	fprintf(tmpfp, "- Date ----- Num. ------ Receipt -\n");
	fprintf(tmpfp, "");
	fprintf(tmpfp, "-----------------------------------\n");
	fprintf(tmpfp, "	   \n");
	fprintf(tmpfp, "======== %Y%m%d Printed =========\n", date);
	fclose(tmpfp);
}

int main() {
	
	return 0; 
} 
