#include <stdio.h>

int main() {
    FILE *fp;
    char ch[100];

    // Open the file for reading
    fp = fopen("myfile.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read a line from the file
    if (fgets(ch, sizeof(ch), fp) != NULL) {
        // Print the line read from the file
        printf("%s", ch);
    } else {
        // Handle error or end of file
        if (feof(fp)) {
            printf("End of file reached.\n");
        } else if (ferror(fp)) {
            perror("Error reading from file");
        }
    }

    FILE *fp1 = fopen("myfile.txt", "a");

    char text[100] = "\nmy name is saif";
    fprintf(fp1, text);

    // Close the file
    fclose(fp);
    fclose(fp1);

    return 0;
}