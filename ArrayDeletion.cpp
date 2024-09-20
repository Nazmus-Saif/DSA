/* #include <iostream>
using namespace std;

int main(){
    int array[10] = {1, 2, 3, 4, 5};
    int position, current_size = 0;

    while (array[current_size] < 10 && array[current_size] !=0)
        current_size++;

    cout << "Enter Positon: ";
    cin >> position;

    for (int i = position; i < current_size; i++){
        array[i] = array[i+1];
    }
    current_size--;

    cout<< "After Deletion" <<endl;
    for (int i = 0; i < current_size; i++){
        cout<< array[i]<<endl;
    }
} */

// Lets see how this works

/* i = position

array[i] = array[i+1]

i = 2 (supose) means 2 index value will be deleted

so, array[2] = array[2+1] or array[3] means array 2 will be replaced by array 3 value this is how its work */


#include <iostream>
using namespace std;

int main(){
    int array[10] = {1, 2, 3, 4, 5};
    int value, current_size = 0;

    while (array[current_size] < 10 && array[current_size] !=0)
        current_size++;

    cout << "Enter Value: ";
    cin >> value;

    for (int i = 0; i < current_size; i++){
        if (array[i] == value){
            for (int j = i; i < current_size; i++){
                array[i] = array[i+1];
            }
            current_size--;
            break; // exit the loop after deleting
        }
    }

    cout << "After Deleting: " << endl;
    for (int i = 0; i < current_size; i++)
        cout << array[i] << endl;
    
    return 0;
}