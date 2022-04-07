#include<stdio.h>

//�C�Ӧr����[�r�� 
void rec_dec(char* s) { 
	if((*s) != 0) {  //array�٨S�� 
		printf("%c,", *s);  //*s �i�H�� s[0] �N�� 
		return rec_dec(++s);  //��++ 
	}
}

//�e���� 
void hanoi_tower (int n, char A, char B, char C) {
    FILE* fp = fopen("hanoi.txt", "a+");
	if(n) {
		hanoi_tower(n-1, A, C, B);
		fprintf(fp, "Move disk %d from %c to %c\n", n, A, C);
		hanoi_tower(n-1, B, A, C);
	}
	fclose(fp);
}

//�E�E���k�� 
int multiplication(int i, int j) {
	 printf("%d * %d = %2d ", i, j, i*j);
    if(j == 9) {  //�Y��*9��-->����Bi+1 
        if(i == 9) return 0;  //9*9�F-->���� 
        printf("\n");  //���� 
        i++;  //i+1 
        j = 0;  //j�q�Y�}�l(�]�����n+1�A�ҥH�@�}�l��=0) 
        return multiplication(i ,j+1);
    }
    multiplication(i ,j+1);
    return 0;
}

int main() {
	char s[] = "1234567890";
	rec_dec(s);
	printf("func#1----------\n");
	hanoi_tower(16, 'A', 'B', 'C');
	printf("func#2----------\n");
	multiplication(1,1);
	printf("func#3----------\n");
	return 0;
} 
