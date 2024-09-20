#include <iostream>
using namespace std;

// Function to heapify a subtree rooted with node i which is an index in array[]
void heapify(int array[], int size, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < size && array[left] > array[largest])
        largest = left; // this will change the variable value of largest
 
    // If right child is larger than largest so far
    if (right < size && array[right] > array[largest])
        largest = right; // this will change the variable value of largest

    // If current largest is not equal to the largest asigned by i => means largest is updated
    if (largest != i) { 
        swap(array[i], array[largest]); // this will change the value in array

        // Recursively heapify the affected sub-tree
        heapify(array, size, largest);
    }
}

// Main function to do heap sort
void heapSort(int array[], int size) {
    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    // One by one extract an element from heap
    for (int i = size - 1; i > 0; i--) {
        // Move current root to end
        swap(array[0], array[i]);

        // Call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i)
        cout << array[i] << " ";
    cout << "\n";
}

int main() {
    int array[] = {4, 3, 7, 1, 8, 5};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Before Sort: " << endl;
    printArray(array, size);
    
    heapSort(array, size);

    cout << "Sorted array: " << endl;
    printArray(array, size);
}