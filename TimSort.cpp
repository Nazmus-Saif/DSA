#include <iostream>
#include <thread>
using namespace std;

const int RUN = 32;

int min(int a, int b){
    if (a < b)
        return a;
    else
        return b;
}

void insertionSort(int array[], int start, int end){
    // In insertion sort we consider the first element as a sorted sub array
    // We use 2 loops 
    // One loop for iterating the unsorted subarray and Other is for iteraing the sorted subarray
    // And we peek one element from the unsorted subarray keep this in TEMP and compare this value with each value in sorted subarray

    for (int i = (start + 1); i <= end; i++){
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

void timSort(int array[], int size){
    // Sort individual subarrays of size of RUN
    for (int i = 0; i < size; i += RUN){
        insertionSort(array, i, min((i + RUN - 1),(size - 1)));
    }
    // Start merging from size RUN
    for (int Size = RUN; Size < size; Size = 2 * Size){
        for (int beg = 0; beg < size; beg += 2 * Size){
            int mid = beg + Size - 1;
            int end = min((beg += 2 * Size - 1), (size - 1));
            if (mid < end) 
                merge(array, beg, mid, end);
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

    timSort(array, size);

    cout << "\nAfter Sort:" << endl;
    printArray(array, size);

    return 0;
}