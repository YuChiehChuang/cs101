#include <stdio.h>

int setMyBit(int* a, int b){
    *a = (1<<b) | *a;
    return *a;
}
int clearMyBit(int* a, int b){
    *a = ( (1<<b) - 1) & *a;
    return *a;
}
int inverseMyBit(int* a, int b){
    *a = (1<<b) ^ *a;
    return *a;
}
int main()
{
    int a = 1;
    int b = 3;
    int t = a;
    printf("setMyBit(%d, %d) = %d\n", t, b, setMyBit(&a, b));
    t = a;
    printf("clearMyBit(%d, %d) = %d\n", t, b, clearMyBit(&a, b));
    t = a;
    printf("inverseMyBit(%d, %d) = %d\n", t, b, inverseMyBit(&a, b));
    t = a;
    return 0;
}
