#include <iostream>
using namespace std;

int main(){
    int array[10] = {1, 2, 3, 4, 5};
    int value;
    int current_size = 0;

    // Calculate the current number of elements in the array
    while (current_size < 10 && array[current_size] <= 10 && array[current_size] != 0) {
        current_size++;
    }

    cout << current_size << endl;

    cout << "Enter Value: ";
    cin >> value;

    array[current_size] = value;
    current_size++;

    for (int i = 0; i < current_size; i++){
        cout << "array[" << i << "]: " << array[i] << endl;
    }

    return 0;
}


/* #include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> array = {1, 2, 3, 4, 5};
    int value;

    cout << "Enter Value: ";
    cin >> value;

    array.push_back(value); // Insert the new value at the end

    cout << "Array after insertion: ";
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
 */