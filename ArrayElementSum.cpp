#include <iostream>
using namespace std;

int main(){
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int array[n];
    //int *array; // array declaration

    for(int i = 0; i < n; i++){
        cout << "Array[" << i << "]: ";
        cin >> array[i];
    }

    // for(int i = 0; i < n; i++){
    //     array[i] = array[i] + array[i]; // this will sum each element with their own
    // }
    cout << "Array is: " << endl;
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }

    int sum = 0;

    for(int i = 0; i < n; i++){
        sum = sum + array[i];
    }
    cout << "The sum of array is: " << sum << endl;

    return 0;
}