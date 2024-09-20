#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("File not found");
    } else {
        printf("File found\n");
        
        // Check for end-of-file
        if (feof(fp)) {
            printf("End of file reached\n");
        }
        
        // Check for error
        if (ferror(fp)) {
            printf("Error reading file\n");
        }
        
        fclose(fp);
    }
    return 0;
}
