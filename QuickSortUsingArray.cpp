#include <iostream>
using namespace std;

void swap(int *a, int *b){ // we use pointer so that it changes the original value of the array
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array for QuickSort
int partition(int array[], int start, int end){
    int pivot = array[start]; // Choose the first element as the pivot
    int left = start + 1;     // Initialize the left pointer
    int right = end;          // Initialize the right pointer
    
    while (left <= right){    // Continue until left and right pointers cross
        while (left <= end && array[left] <= pivot){ // Move left pointer to the right
            left++;
        }
        while (right >= start && array[right] > pivot){ // Move right pointer to the left
            right--;
        }
        if (left < right){ // Swap elements if left is less than right
            swap(&array[left], &array[right]);
        }
    }
    swap(&array[start], &array[right]); // Swap pivot with the element at the right pointer
    return right; // Return the partition index
}

void quickSort(int array[], int start, int end){
    if (start < end){ // Base condition for recursion
        int boundary = partition(array, start, end); // Get the partition index
        quickSort(array, start, boundary - 1); // Recursively sort the left sub-array
        quickSort(array, boundary + 1, end);   // Recursively sort the right sub-array
    }
}

void printArray(int array[], int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    int array[] = {9, 8, 7, 10, 1, 5, 4, 3};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Original Array: " << endl;
    printArray(array, size);

    quickSort(array, 0, size - 1);

    cout << "After Sorting: " << endl;
    printArray(array, size);
    
    return 0;
}