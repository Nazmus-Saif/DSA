#include <stdio.h> 
int main(){  
int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int *p;
p = a;
printf("\n%d %d %d", (*p)++, *p++, *++p);
/* (*p)++ means first execute *p then increment 
    *p++  means first execute this (p++) then *
    *++p  means first execute ++p then * */
printf("\n %d", *--p+5); // first --p will be execute then *(--p) then add the value with 5
printf("\n %d", *p-3); // first *p is execute then minus 3
printf("\n %d", *p+*p); // add the current 2 address value
printf("\n%d %d %d %d", *p, *(p+1), *(p+2), *(p+3));
/* *(p+1) means increment the pointer address then find the value of that address */
*p = 50; // here we change the value of 0th element of array a
printf("\n%d %d %d", *p, *(p+1), *(p+2));
printf("\n%d %d %d", *a, *(a+1), *(a+2));
printf("\n%d %d %d", a[0], a[1], a[2]);

return 0;
}

/* #include <stdio.h>

int main(){
    int *ptr;
    int n;
    scanf("%d", &n);
    if(n==5){
        int a = 5;
        ptr = &a;
        printf("\n%d", *ptr);
    }
   printf("\n%d", *ptr); // this *ptr may be give garbej value at some point because the scope of a is within its block

} */