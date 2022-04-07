#include<stdio.h>

//–じ硆腹 
void rec_dec(char* s) { 
	if((*s) != 0) {  //array临⊿Ч 
		printf("%c,", *s);  //*s ノ s[0] 蠢 
		return rec_dec(++s);  //++ 
	}
}

//猠ず娥 
void hanoi_tower (int n, char A, char B, char C) {
    FILE* fp = fopen("hanoi.txt", "a+");
	if(n) {
		hanoi_tower(n-1, A, C, B);
		fprintf(fp, "Move disk %d from %c to %c\n", n, A, C);
		hanoi_tower(n-1, B, A, C);
	}
	fclose(fp);
}

//猭 
int multiplication(int i, int j) {
	 printf("%d * %d = %2d ", i, j, i*j);
    if(j == 9) {  //琘计*9-->传︽i+1 
        if(i == 9) return 0;  //9*9-->挡 
        printf("\n");  //传︽ 
        i++;  //i+1 
        j = 0;  //j眖繷秨﹍(单单璶+1┮秨﹍=0) 
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
