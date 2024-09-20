#include <stdio.h>

int main(){
    void *ptr; // void pointer which is also called generic pointer => this pointer can hold any data type
    int a = 50;
    ptr = &a;
    float b = 5.5;
    ptr = &b;
    printf("%d", *(int *)ptr); // typecasting the void pointer to int pointer and dereferencing it to print the value of a
    // if we not typecasting it, it does not know the address size either 4byte or 1byte etc.
    printf("\n%f", *(float *)ptr);
}