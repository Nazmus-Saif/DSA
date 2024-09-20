#include <iostream>
using namespace std;

void selectionSort(int array[], int size){
    for (int i = 0; i < size - 1; i++){
        int minIndex = i; // set the first element as a Minimum
        for (int j = i + 1; j < size; j++){
            if (array[j] < array[minIndex]){ // if the element is less than the current minimum, update the minimum index
                minIndex = j;
            }
        }
        // finally swap the element
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
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

    selectionSort(array, size);

    cout << "\nAfter Sorting: " << endl;
    printArray(array, size);
    return 0;
}