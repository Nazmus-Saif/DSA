#include <stdio.h>

int main(){
    int a[50] = {1,2,3,40,5,6,7,8,9,10};
    int *i;
    i = a;
    printf("%d\n",*(i+3));
    printf("%d\n", a); // this will print the address of the array
    return 0;
}