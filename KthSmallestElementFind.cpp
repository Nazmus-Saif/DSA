#include <iostream>
#include <algorithm> // for sort
using namespace std;

int main() {
    int n, k;

    // Input: size of the array and kth position
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    // Input: elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Input: k for the kth smallest element
    cout << "Enter the value of k (1 <= k <= " << n << "): ";
    cin >> k;

    // Sort the array
    sort(arr, arr + n); // arr + n points the last element of the array

    // Output: kth smallest element
    cout << "The " << k << "th smallest element in the array is: " << arr[k - 1] << endl;

    return 0;
}

/* Input Reading: Reading the size of the array and its elements takes O(n) time, where n is the number of elements in the array.

Sorting: Sorting the array using std::sort has a time complexity of O(nlogn). This dominates the time complexity of the entire algorithm.

Finding kth smallest element: Accessing the k-th smallest element after sorting is O(1), because it's just a direct array access. */