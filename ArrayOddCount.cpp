#include <iostream>
using namespace std;

int countOdd(int array[], int n){
    int count = 0;

    for(int i = 0; i < n; i++){
        if(array[i] % 2 != 0){
            count++;
        }
    }
    return count;
}

int main(){
    int array[] = {1, 2, 3, 4, 5};
    cout << "Total odd is: "<< countOdd(array, 6) << endl;

    return 0;
}