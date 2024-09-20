#include <iostream>
using namespace std;

// Function to merge two subarrays of array[].
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray +1 because array starts from 0
    int n2 = right - mid; // Size of right subarray

    // Temporary array for left and right subarray
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = array[left + i]; // left = 0 starts from 0 => left + i calculates the correct index in the original array for the left subarray
    for (int i = 0; i < n2; i++)
        R[i] = array[mid + 1 + i]; // right = mid + 1 starts from mid + 1 => mid + 1 + i calculates the correct index in the original array for the right subarray

    // Merge the temporary arrays back into array[left..right]
    int i = 0; // Initial index of first subarray left
    int j = 0; // Initial index of second subarray right
    int k = left; // k is the index for the original array where the merged elements are placed.
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(int array[], int left, int right) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    // Sort first and second halves
    mergeSort(array, left, mid); // Recursive call to divide until one element in array
    mergeSort(array, mid + 1, right); // Recursive call to divide unitl one element in array

    // Merge the sorted halves
    merge(array, left, mid, right);
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int array_size = sizeof(array) / sizeof(array[0]);

    cout << "Given array is \n";
    printArray(array, array_size);

    mergeSort(array, 0, array_size - 1);

    cout << "\nSorted array is \n";
    printArray(array, array_size);
    return 0;
}