#include <iostream>
using namespace std;

int main(){
    int array[10] = {1, 2, 3, 4, 5};
    int position, value, current_size = 0;

    //while (array[current_size] < 10 && array[current_size] >= 0) // this will print the full 10 memory sell and rest are empty
    
    while (current_size < 10 && array[current_size] <= 10 && array[current_size] != 0)
        current_size++; // get the current size of the array

    cout << "Current Size " << current_size << endl;
    
    cout << "Before Insertion: " << endl;
    for (int i = 0; i < current_size; i++)
        cout << array[i] << endl;

    cout << "Enter Value: ";
    cin >> value;

    cout << "Enter Position: ";
    cin >> position;

    /* for (int i = current_size - 1; i >= position; i--) { // this loop also works
    array[i + 1] = array[i];
    } */

    for (int i = current_size; i > position; i--)
        array[i] = array[i-1];

    array[position] = value;
    current_size++;

    cout << "After Insertion: " << endl;
    for (int i = 0; i < current_size; i++)
        cout << array[i] << endl;
    
    return 0;
}


/* #include <iostream>
using namespace std;

int main(){
    int array[10] = {1, 2, 3, 4, 5};
    int position, current_size = 0, value;

    while (current_size < 10 && array[current_size] <= 10 && array[current_size] != 0)
        current_size++;

    cout << "Enter Value: " << endl;
    cin >> value;

    cout << "Enter Positon: " << endl;
    cin >> position;

    array[position] = value;
    current_size++;

    cout<< "After Insertion:" <<endl;
    for (int i = 0; i < current_size - 1; i++){
        cout<< array[i]<<endl;
    }

    return 0;
} */