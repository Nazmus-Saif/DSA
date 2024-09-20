#include <stdio.h>

void mystrcpy(char *to, char *from){
    while(*from){
        *to++ = *from++;
        *to = '\0';
    }
}

int main(){
    char str[10];
    mystrcpy(str, "Hellow");
    printf("String is: %s\n", str);
}