#include <iostream>
using namespace std;

int main() {
    int array[10] = {1, 2, 3, 4, 5};
    int old_value, new_value, current_size = 0;

    // Find current_size based on the existing logic
    while (current_size < 10 && array[current_size] <= 10 && array[current_size] != 0) {
        current_size++;
    }

    cout << "Enter Old Value: ";
    cin >> old_value;

    cout << "Enter New Value: ";
    cin >> new_value;

    bool found = false;
    for (int i = 0; i < current_size; i++) {
        if (old_value == array[i]) {
            array[i] = new_value;
            found = true;
        }
    }

    if (!found) {
        cout << "Value not found!" << endl;
    } else {
        cout << "After Updating: " << endl;
        for (int i = 0; i < current_size; i++) {
            cout << array[i] << endl;
        }
    }

    return 0;
}
