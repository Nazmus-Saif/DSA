#include <stdio.h>
#include <string.h>

int main(){
    char str1[50] = "Hello";
    char str2[50];
    int i, j = 0;
    for (i = strlen(str1) - 1; i >= 0; i--){
        str2[j] = str1[i];
        j++;
    }
    str2[j] = '\0';
    printf("%s\n", str2);
}