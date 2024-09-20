#include <stdio.h>

int main(){
    int x = 10, y = 5, z = 7, w = 2;
    int max = (x > y) ? ((x > z) ? ((x > w) ? x : w) : ((z > w) ? z : w)) : ((y > z) ? ((y > w) ? y : w) : ((z > w) ? z : w));
    printf("%d", max);
}