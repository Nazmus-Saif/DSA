#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char str[100];
    int i;
    //printf("Enter a string: ");
    // gets(str);
    // printf("\nLength of string : %d", strlen(str));
    // for (i = 0; str[i] != '\0'; i++) {
    //     str[i] = toupper(str[i]);
    // }
    // printf("\nString in upper case: %s", str);
    // for (i = 0; str[i] != '\0'; i++) {
    //     str[i] = tolower(str[i]);
    // }
    // printf("\nString in lower case: %s", str);
    // return 0;


    // using pointer

    char *p;
    p = str;
    printf("Enter a string: ");
    gets(p);
    printf("\nLength of string : %d", strlen(p));
    for (i = 0; p[i] != '\0'; i++) {
        p[i] = toupper(p[i]);
    }
    printf("\nString in upper case: %s", p);
    for (i = 0; p[i] != '\0'; i++) {
        p[i] = tolower(p[i]);
    }
    printf("\nString in lower case: %s", p);
    return 0;
}