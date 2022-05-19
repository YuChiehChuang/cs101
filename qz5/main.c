#include<stdio.h>
#include<stdlib.h>

int do_before_adding(int* i) {
	int num = *i;
	*i += 1;
	return num;
}

int do_after_adding(int* i) {
	*i += 1;
	int num = *i;
	return num;
}

void check_result(int x, int z, int t_x, int t_z) {
	if (x == t_x && z == t_z) {
		printf(" pass\n"); 
	} else {
		printf(" fail\n");
	}
}

void test_do_before_adding() {
	int x = 1;
	int z = 5 + do_before_adding(&x);
	int t_x = 1;
	int t_z = 5 + t_x++;
	printf("do_before_adding()\n");
	printf(" z=%d, x=%d\n", t_z, t_x);
	printf(" t_z=%d, t_x=%d\n", t_z, t_x);
	check_result(x, z, t_x, t_z);
}

void test_do_after_adding() {
	int x = 1;
	int z = 5 + do_after_adding(&x);
	int t_x = 1;
	int t_z = 5 + ++t_x;
	printf("do_after_adding()\n");
	printf(" z=%d, x=%d\n", t_z, t_x);
	printf(" t_z=%d, t_x=%d\n", t_z, t_x);
	check_result(x, z, t_x, t_z);
}

int main() {
	printf(" --- fun 1. ---");
	test_do_before_adding();
	printf(" --- fun 2. ---");
	test_do_after_adding();
	return 0;
}
