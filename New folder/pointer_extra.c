#include <stdio.h>

int sum(int *a, int *b){
    return *a + *b;
}

int main(){
    int a=5, b=5;
    int *p = &a;
    int *q = &b;
    printf("%d", sum(&a, &b));// this is right    
    printf("%d", sum(p, q));// this is right
    printf("%d", sum(&p, &q));// this is wrong because we are passing address of pointer and sum cant sum an address without typecasing &p &q
    printf("%d", sum(a, b));// this is wrong because we are passsing values of a and b but sum receive address of a and b

}