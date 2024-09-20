#include <stdio.h>

// Function to swap the values of two variables
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate all permutations of an array
void permute(int arr[], int start, int end) {
    if (start == end) {
        printArray(arr, end + 1);
        return;
    }

    for (int i = start; i <= end; i++) {
        // Swapping elements at indices start and i 
        swap(&arr[start], &arr[i]);

        // Recursively generate permutations for the remaining elements
        permute(arr, start + 1, end);

        // Backtrack - restore the original array
        swap(&arr[start], &arr[i]);
    }
}

int main() {
    int arr[] = {10, 20, 30};
    int size = sizeof(arr) / sizeof(arr[0]); // calculate the size of the array

    printf("Permutations of the numbers 10, 20, and 30:\n");
    permute(arr, 0, size - 1);

    return 0;
}
