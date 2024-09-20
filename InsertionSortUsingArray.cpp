#include <iostream>
using namespace std;

void insertionSort(int array[], int size){
    // In insertion sort we consider the first element as a sorted sub array
    // We use 2 loops 
    // One loop for iterating the unsorted subarray and Other is for iteraing the sorted subarray
    // And we peek one element from the unsorted subarray keep this in TEMP and compare this value with each value in sorted subarray

    for (int i = 1; i < size; i++){
        int temp = array[i]; // holds the value of unsorted subarray one by one
        int j = i - 1; // iterates in sorted subarray 
        // i starts from 1 and j starts from 0

        // another condition for compare and sort
        while (j >= 0 && temp < array[j]){ // array[j] = value in sorted subarray and temp is value in unsorted subarray
            array[j + 1] = array[j]; // shit or replace the j value with j+1 value (to right)
            // now if there are more than 1 element in sorted array then we have to compare with that also for use we decrease the value of j
            j--;
        } // this loop will going to j current value to j = 0
        // now assign the value of temp to sorted array
        array[j + 1] = temp;
    }
}

void printArray(int array[], int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
}

int main(){
    int array[] = {9, 8, 7, 10, 1, 5, 4, 3};
    int size = sizeof(array) / sizeof(array[0]); // calculate the size of the array

    cout << "Original Array: " << endl;
    printArray(array, size);

    insertionSort(array, size);

    cout << "\nAfter Sorting: " << endl;
    printArray(array, size);
    return 0;
}