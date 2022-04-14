#include <stdio.h>

void find_num(int* p, int num) {
	for(int i = 0; i < 10; i++) {
	  	if(*(p + i) == num) {
		   	printf("&n[%d]->%p, n[%d] = %d, ", i, p, i, *(p + i));
		   	printf("p->%p, *p = %d\n", p, *(p + i));
	  	}
	}
}
void sort(int** ap) {
	for(int i = 0; i < 10; i++) {
		for(int j = i + 1; j < 10; j++) {
			if(*ap[i] > *ap[j]) {
			    int* temp = ap[i];
			    ap[i] = ap[j];
			    ap[j] = temp;
		   	}
	  	}
	  	printf("&n[%d]->%p, n[%d] = %d, ", i, ap[i], i, *(ap[i]));
	  	printf("ap[%d]->%p, *ap[%d] = %d\n", i, ap[i], i, *(ap[i]));
 	}
}

int main(void) {
 	int n[10] = {6, 4, 7, 2, 0, 9, 8, 1, 5, 3};
 	int* p;
 	int* ap[10];
 	int num = 9;
 	p = n;
 	for(int i = 0, j = 0; i < 10; i++) {
  		ap[i] = &n[j++];
 	}
	printf("N0.1 -------------------\n");
 	find_num(p, num);
 	printf("N0.2 -------------------\n");
 	sort(ap);

 	return 0;
}
