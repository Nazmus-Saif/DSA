#include <iostream>
#include <string>
using namespace std;

const int totalStudents = 3;   // Number of students
const int totalAttributes = 3; // Number of attributes (ID, name, grade)

void anotherExample(){
    const int rows = 3;
    const int cols = 4;
    int matrix[rows][cols] = {{1, 2, 3, 4},
                              {5, 6, 7, 8},
                              {9, 10, 11, 12}};

    // Nested loops to iterate over each element in the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
        cout << matrix[i][j] << " ";
        }
        cout << endl; // Move to the next row in the output
    }
}

int main() {
    // Declare a 2D array to store student information
    string students[totalStudents][totalAttributes] = {
        {"201400001", "Alice", "A"},
        {"201400002", "Bob", "B+"},
        {"201400003", "Charlie", "A-"}
    };

    for (int i = 0; i < totalStudents; i++) {
        cout << "ID: " << students[i][0] << ", Name: " << students[i][1] << ", Grade: " << students[i][2] << endl;
    }  

    // students[i][0]  in this we specify the postion like [i][0] of each column so that we dont have to use nested loop
    // but if we not specify then we have to use loops like following code

    anotherExample();

    return 0;
}