#include <stdio.h>

int main() {
    FILE *fp;
    long int previous_position, after_position;

    fp = fopen("first_file.txt", "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    previous_position = ftell(fp);
    if (previous_position == -1L) {
        perror("Error getting file position");
        return 1;
    }
    printf("Current position of the file pointer: %ld\n", previous_position);

    // Move the file pointer 5 bytes from the beginning of the file
    fseek(fp, 5, SEEK_SET);

    // Get the current position of the file pointer
    after_position = ftell(fp);
    if (after_position == -1L) {
        perror("Error getting file position");
        return 1;
    }

    printf("Current position of the file pointer: %ld\n", after_position);

    fclose(fp);
    return 0;
}


// array shifting

// #include <stdio.h>

// void shiftArray(int arr[], int size, int shift) {
//     int temp[size];
//     for (int i = 0; i < size; i++) {
//         temp[(i + shift) % size] = arr[i];
//     }
//     for (int i = 0; i < size; i++) {
//         arr[i] = temp[i];
//     }
// }

// int main() {
//     int arr[] = {1, 2, 3, 4, 5};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int shift = 2;

//     printf("Original array: ");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     shiftArray(arr, size, shift);

//     printf("Shifted array: ");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     return 0;
// }

