#include<stdio.h>
#include<stdlib.h>

//第一題 
int* get_int_array(int n) {
	return (int*)calloc(n, sizeof(int));
}

void set_value(int* p, int v) {
	*p = v;
}

void print_array(int* p, int n) {
	int i;
	for (i = 0 ; i < n-1 ; i++) {
		printf("%d, ", *p+i);
	}
	printf("%d", *p+i);
}

//第二題
typedef struct array_list {
	int n;
	int (*get_ptr)(int);
	void (*set_ptr)(int*, int);
	void (*print_ptr)(int*, int);
} array_list_t;

//第三題


int main() {
	int n = 10;
	
	printf("No.1----------\n[");
	int* ip = get_int_array(n);
	for (int i = 0 ; i < n ; i++) {
		set_value(ip+i, i+1);
	}
	print_array(ip, n);
	printf("]\n");
	
	printf("No.2----------\n");
	array_list_t.get_ptr = ;
	array_list_t.set_ptr = ;
	array_list_t.print_ptr = ;
	
	printf("No.3----------\n");
	
	return 0;
}
