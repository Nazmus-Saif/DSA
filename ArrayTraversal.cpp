#include <iostream>
using namespace std;

int main(){
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "\nElements of Array: \n" << endl;
    for (int i = 0; i < 10; i++){
        cout << "array[" << i << "]: " << array[i] << endl;
    }

    return 0;
}

// this is array traversal means loop increment its value to access the value of the array one after another