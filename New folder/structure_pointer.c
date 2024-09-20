#include <stdio.h>

struct test
{
    int a, b;
};


int main(){
    struct test t;
    struct test *p;
    p = &t;
    p->a = 10;
    p->b = 20;
    printf("%d %d\n", p->a, p->b);
    return 0;
}