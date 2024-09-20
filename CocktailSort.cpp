#include <iostream>
using namespace std;

void cocktailSort(int array[], int size){
    int start = 0;
    int end = size - 1;
    int swapped = 1;

    while (swapped){
        swapped = 0;

        for (int i = start; i < end; ++i){
            if (array[i] > array[i + 1]){
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
        
        swapped = 0;

        --end;

        for (int i = end; i >= start; --i){
            if (array[i] > array[i + 1]){
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }

        ++start;
    }
}

void printArray(int array[], int size){
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
}

int main(){
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Before Sort:" << endl;
    printArray(array, size);

    cocktailSort(array, size);

    cout << "\nAfter Sort:" << endl;
    printArray(array, size);

    return 0;
}