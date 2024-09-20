// extern_file2.c
#include <stdio.h>
#include <stdlib.h>

// Declaration of 'x' and 'myFunction'
extern int x;
extern void myFunction();

int main() {
    printf("x = %d\n", x); // Using 'x'
    myFunction(); // Calling 'myFunction'
    return 0;
}
