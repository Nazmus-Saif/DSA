#include <iostream>
using namespace std;

int main()
{
    int a[50], n, i;
    cout << "Enter The Size of Array: ";
    cin >> n;
    cout << "\nEnter The Element of Array:\n\n";
    for (i = 0; i < n; i++)
    {
        cout << "Array[" << i << "] = ";
        cin >> a[i];
    }

    // In normal Bubble Sort comparisons occur until the loop terminate itself even though the array is sort
    // Optimized Bubble Sort reduced the number of comparisons when it found no swap occur means the array is sorted
    int j, k, temp;
    bool swapped;
    for (j = 0; j < n - 1; j++)
    {
        swapped = false;
        for (k = 0; k < n - 1 - j; k++)
        {
            if (a[k] > a[k + 1])
            {
                temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (!swapped)
            break;
    }

    cout << "\nAfter Sorting The Array Is: ";
    for (i = 0; i < n; i++)
    {
        cout << "\t" << a[i];
    }

    // Find the kth smallest value from the array
    int Kth;
    cout << "\nEnter Kth Variable: ";
    cin >> Kth;

    if (Kth > 0 && Kth <= n)
    {
        cout << "\n" << Kth << " Number Smallest Value is " << a[Kth - 1] << endl;
    }
    else
    {
        cout << "\nInvalid Kth value entered." << endl;
    }

    return 0;
}