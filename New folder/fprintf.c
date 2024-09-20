#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("first_file.txt", "a");  // Open the file in append mode
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    fprintf(fp, "Hello World");    // Write "Hello World" to the file
    fputs("Hellow", fp);           // Write "Hellow" to the file
    fclose(fp);                    // Close the file
    return 0;
}
