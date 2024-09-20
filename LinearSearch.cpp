#include <iostream>
using namespace std;

int main(){
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, value;

    cout << "Enter Value: ";
    cin >> value;

    for (int i = 0; i < 10; i++){
        if (value == array[i])
            cout << array[i] << " is found in position " << i << "." << endl;
    }

    return 0;
}

// Linear search - search each value one after another and check the equalilty of the given value if match then prints the result.