#include <iostream>
using namespace std;

int main(){
    int array[10] = {1, 2, 3, 4, 5};
    int current_size = 0;

    while(array[current_size] < 10 && array[current_size] != 0)
        current_size++;

    for (int i = current_size-1; i >= 0; i--)
        cout << array[i] << endl;

    return 0;
}