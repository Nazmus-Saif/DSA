#include <iostream>
#include <cmath>
#include <thread>
using namespace std;

int updatedGap(int gap){
    gap = floor(gap / 1.3); // shrink factor = 1.3
    if (gap < 1)
        return 1;
    return gap;
}

void combSort(int array[], int size){
    int gap = size;
    int swapped = 1;

    while (gap !=  1 || swapped == 1){
        gap = updatedGap(gap);
        swapped = 0;
        for (int i = 0; i < (size - gap); i++){
            if (array[i] > array[i + gap]){
                int temp = array[i];
                array[i] = array[i + gap];
                array[i + gap] = temp;
                swapped = 1;
            }
        }
    }
}

void printArray(int array[], int size){
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
}

int main(){
    int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);

    /* cout << "Before Sort:" << endl;
    printArray(array, size);

    combSort(array, size);

    cout << "\nAfter Sort:" << endl;
    printArray(array, size); */

    thread th1 (combSort, array, size);
    th1.join();
    thread th2 (printArray, array, size);
    th2.join();

    return 0;
}