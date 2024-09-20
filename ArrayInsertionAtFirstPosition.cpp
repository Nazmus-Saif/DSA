#include <iostream>
using namespace std;

int main() {
    int array[10] = {1, 2, 3, 4, 5};
    int value = 99;
    int current_size = 5;

    if (current_size >= 10) {
        cout << "Array is full, cannot insert new element." << endl;
    } else {
        // Move all elements one position to the right
        // for (int i = current_position; i > 0; i--){
        //     array[i] = array[i-1];
        // }
        for (int i = current_size - 1; i >= 0; i--) { // this loop also works
            array[i + 1] = array[i];
        }

        array[0] = value;
        current_size++; // Increse the array size

        cout << "Array after insertion: ";
        for (int i = 0; i < current_size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    return 0;
}


// #include <iostream>
// using namespace std;

// int main() {
//     int array[10] = {1, 2, 3, 4, 5}; // The rest are 0
//     int value = 99;
//     int n = 0;

//     // Calculate the current number of elements in the array
//     while (n < 10 && array[n] != 0) {
//         n++;
//     }

//     if (n >= 10) {
//         cout << "Array is full, cannot insert new element." << endl;
//     } else {
//         // Move all elements one position to the right
//         for (int i = n; i > 0; i--) {
//             array[i] = array[i - 1];
//         }

//         array[0] = value;
//         n++; // Increase the array size

//         cout << "Array after insertion: ";
//         for (int i = 0; i < n; i++) {
//             cout << array[i] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }


/* Here's what happens during each iteration:

First iteration (i = 5):
array[5] = array[4] → {1, 2, 3, 4, 5, 5}
Second iteration (i = 4):
array[4] = array[3] → {1, 2, 3, 4, 4, 5}
Third iteration (i = 3):
array[3] = array[2] → {1, 2, 3, 3, 4, 5}
Fourth iteration (i = 2):
array[2] = array[1] → {1, 2, 2, 3, 4, 5}
Fifth iteration (i = 1):
array[1] = array[0] → {1, 1, 2, 3, 4, 5} 

as array[i] = array[i-1] at first we start one position forward from current which is array[5] in general it is 6
so 6 = 5
   5 = 4
   4 = 3
   3 = 2
   2 = 1
   1 = new value*/
