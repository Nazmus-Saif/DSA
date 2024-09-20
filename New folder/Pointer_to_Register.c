#include <stdio.h>

int main(){
    register int i = 0;
    int *j;
    j = &i;
    printf("%p\n", j); // we cant print the address of a register variable as they stored in cpu memory not in a ram
}