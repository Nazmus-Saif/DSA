#include <iostream>
#include <cmath>
using namespace std;

/* void shellSort(int array[], int size){
    for (int interval = size / 2; interval > 0; interval /= 2){ // this will decrease the interval by divide the interval 2 means each time it will be half
        for (int i = interval; i < size; i++){
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
                array[j] = array[j - interval];
            array[j] = temp;
        }
    }
} */

int updatedGap(int interval){
    interval = floor(interval / 2);
    if (interval < 1)
        return 1;
    return interval;
}

void shellSort(int array[], int size){
    int interval = size;
    int swapped = 1;

    while (interval !=  1 || swapped == 1){
        interval = updatedGap(interval);
        swapped = 0;
        for (int i = 0; i < (size - interval); i++){
            if (array[i] > array[i + interval]){
                int temp = array[i];
                array[i] = array[i + interval];
                array[i + interval] = temp;
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
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Before Sort:" << endl;
    printArray(array, size);

    shellSort(array, size);
    
    cout << "\nAfter Sort:" << endl;
    printArray(array, size);

    return 0;
}