#include<stdio.h>

int main(){
    FILE *file = fopen("myfile.txt", "rb");
    if (file != NULL) {
    // Move the file pointer to the end of the file
    fseek(file, 0, SEEK_END);

    // Get the current position (which is the size of the file)
    long int size = ftell(file);
    printf("File size: %ld bytes\n", size);

    fclose(file);
}