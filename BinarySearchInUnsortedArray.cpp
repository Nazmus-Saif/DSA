#include <iostream>
using namespace std;

int main()
{
    int *a, n, i;
    cout << "Enter the size of the array: ";
    cin >> n;

    a = new int[n]; // Dynamic memory allocation for the array

    cout << "\nEnter the elements of the array:\n\n";
    for (i = 0; i < n; i++)
    {
        cout << "Array[" << i << "] = ";
        cin >> a[i];
    }

    cout << "\nWithout sorting: ";
    for (i = 0; i < n; i++)
    {
        cout << "\t" << a[i];
    }
    cout << "\n";
    
    int j, k, temp;
    for (j = 0; j < n - 1; j++)
    {
        for (k = 0; k < n - 1; k++)
        {
            if (a[k] > a[k + 1])
            {
                temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
            }
        }
    }

    cout << "\nAfter sorting: ";
    for (i = 0; i < n; i++)
    {
        cout << "\t" << a[i];
    }
    cout << "\n";

    int v;
    cout << "\nEnter the value to find: ";
    cin >> v;

    int l = 0, r = n - 1, mid;
    bool found = false;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] == v)
        {
            cout << "\nData is found at location " << mid << "\n";
            found = true;
            break;
        }
        else if (a[mid] < v) // v is on the right side
            l = mid + 1;
        else // v is on the left side
            r = mid - 1;
    }
    if (!found)
    {
        cout << "\nData does not exist in this array\n";
    }

    delete[] a; // Free the dynamically allocated memory
    return 0;
}