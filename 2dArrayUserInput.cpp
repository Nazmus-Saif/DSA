#include <iostream>
using namespace std;

int main(){
    int row, column;
    cout << "Enter Row Data: ";
    cin >> row;
    cout << "Enter Column Data: ";
    cin >> column;
    int array[row][column];

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            cout << "Array[" << i << "]" << "[" << j << "]: ";
            cin >> array[i][j];
        }
    }

    cout << "\nArray is: " << endl;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}