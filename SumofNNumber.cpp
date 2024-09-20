#include <iostream>
using namespace std;
 
int main(){
    int i, num, sum = 0;
    cout << "How many numbers: ";
    cin >> num;

    for (int i = 1; i <= num; i++){
        sum = sum + i;
    }

    cout << "Sum is: "<< sum << endl;

    return 0;
}