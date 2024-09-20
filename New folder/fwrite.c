#include <stdio.h>

int main() {
    // Initialize the array
    int array[20];
    for (int i = 0; i < 20; i++) {
        array[i] = i + 1;
    }

    // Write the array to a file using fwrite
    FILE *file = fopen("TEMP", "wb"); // Open the file for writing in binary mode
    if (file != NULL) {
        fwrite(array, sizeof(int), 20, file); // Write the entire array to the file
        fclose(file); // Close the file
        printf("Array saved to file TEMP\n");
    } else {
        printf("Error opening file for writing\n");
    }

    return 0;
}
