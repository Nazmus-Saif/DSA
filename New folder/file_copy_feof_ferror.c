#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *sourceFile, *destinationFile;
    char sourceFileName[100], destinationFileName[100];
    char ch;

    // // Input source file name
    // printf("Enter the source file name: ");
    // scanf("%s", sourceFileName);


    // // Input destination file name
    // printf("Enter the destination file name: ");
    // scanf("%s", destinationFileName); 
    if (argc != 3){
        printf("Try Again Latter");
        return 1;
    }

    strcpy(sourceFileName, argv[1]);
    strcpy(destinationFileName, argv[2]);

        // Open source file in read mode
    sourceFile = fopen(sourceFileName, "r");

    if (sourceFile == NULL) {
        printf("Unable to open source file.\n");
        return 1;
    }

    // Open destination file in write mode
    destinationFile = fopen(destinationFileName, "w");

    if (destinationFile == NULL) {
        printf("Unable to create destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy contents from source file to destination file
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }
    if(ferror(sourceFile) != 0) // if there is an error while reading the stream of the file the return 0
        printf("Error reading file.\n");
    if(feof(sourceFile) != 0) // if the end of the file is reached the return non 0 otherwise return 0
        printf("File End Reached.\n");

    printf("File copied successfully.\n");

    // Close files
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
