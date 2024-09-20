// Pass By Value

#include<iostream>
using namespace std;

void func1(int x) {
    x = 10;  // Changes the copy, not the original variable
    cout<<x<<endl;
}

int main() {
    int a = 5;
    func1(a);
    // 'a' remains unchanged (still 5) after calling func
    cout<<a<<endl;
}


// Pass By Reference

#include<iostream>
using namespace std;

void func2(int &x) {
    x = 10;  // Changes the original variable 'a' passed to func
    cout<<x<<endl;
}

int main() {
    int a = 5;
    func2(a);
    // 'a' is now 10 after calling func
    cout<<a<<endl;
}


// Pass By Pointer

#include<iostream>
using namespace std;

void func(int *ptr) {
    *ptr = 10;  // Changes the original variable through the pointer
    cout<<*ptr<<endl;
}

int main() {
    int a = 5;
    func(&a);  // Pass the address of 'a' to func
    // 'a' is now 10 after calling func
    cout<<a<<endl;
}