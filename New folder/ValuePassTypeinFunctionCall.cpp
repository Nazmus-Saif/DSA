#include <iostream>
using namespace std;

void pointer(int *ptr){
    *ptr = 5;
    cout << *ptr << endl;
}

void change(int a){
    a = 10;
    cout << a << endl;
}

int main(){
    int n;
    cout << "Enter a Number: ";
    cin >> n;
    pointer(&n); // this will change the value of n because we are passing the address of n
    cout << n << endl;
    change(n); // this will change the value of n in the change function only
    cout << n << endl;
    
    return 0;
}