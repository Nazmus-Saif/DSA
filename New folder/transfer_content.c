#include <stdio.h>

int main() {
    FILE *fp1;
    FILE *fp2;
    fp1 = fopen("first_file.txt", "r");
    fp2 = fopen("second_file.txt", "w");
    fp2 = fopen("second_file.txt", "a");
    
    if (fp1 == NULL || fp2 == NULL) {
        printf("File not found or cannot be created.\n");
        return 1;
    }

    int c;

    // Read characters from fp1 and write them to fp2
    while ((c = fgetc(fp1)) != EOF) {
        fputc(c, fp2);
        printf("%c", c); // Print each character read from fp1
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
