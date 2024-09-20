#include <iostream>
using namespace std;

int getMax(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {  // Start loop from 1 instead of 0
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

void countingSort(int array[], int size, int exp) {
    int output[size];
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    // Change count[i] so that count[i] contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copy the output array to array[], so that array now contains sorted numbers according to the current digit
    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void radixSort(int array[], int size) {
    // Find the maximum number to know the number of digits
    int max = getMax(array, size);

    // Do counting sort for every digit. Note that exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(array, size, exp);
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main() {
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Max Number: " << getMax(array, size) << endl;

    cout << "Before Sort:" << endl;
    printArray(array, size);

    radixSort(array, size);

    cout << "After Sort:" << endl;
    printArray(array, size);

    return 0;
}