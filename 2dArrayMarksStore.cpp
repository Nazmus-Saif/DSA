#include <iostream>
using namespace std;

int main() {
    int students, marks;

    cout << "Enter How Many Students: ";
    cin >> students;
    cout << "Enter How Many Marks: ";
    cin >> marks;

    // Declare array after initializing students and marks
    int array[students][marks];

    // Input marks
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < marks; j++) {
            cout << "Enter marks for student " << i + 1 << " subject " << j + 1 << ": ";
            cin >> array[i][j];
        }
    }

    // Output marks
    cout << "Entered Marks:\n";
    for (int i = 0; i < students; i++) {
        cout << "Marks for student " << i + 1 << ": ";
        for (int j = 0; j < marks; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}