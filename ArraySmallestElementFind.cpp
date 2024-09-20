#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize the minimum element to the first element of the array
    int minElement = arr[0];

    // Traverse the array to find the smallest element
    for (int i = 1; i < n; i++) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    cout << "The smallest element in the array is: " << minElement << endl;

    return 0;
}

/* The program initializes minElement to the first element of the array, which is 7.

First Iteration (i=1):

Current element: 5
Compare 5 with minElement (7):
Since 5 < 7, update minElement to 5. 

Second Iteration (i=2):

Current element: 3
Compare 3 with minElement (5):
Since 3 < 5, update minElement to 3.

Third Iteration (i=3):

Current element: 1
Compare 1 with minElement (3):
Since 1 < 3, update minElement to 1.

Fourth Iteration (i=4):

Current element: 6
Compare 6 with minElement (1):
Since 6 > 1, no change to minElement.

Fifth Iteration (i=5):

Current element: 8
Compare 8 with minElement (1):
Since 8 > 1, no change to minElement.*/
