#include <iostream>
using namespace std;

class A {
public:
    A(int a, int b){
        cout<<"Sum is: "<<a+b<<endl;
    }
};

class B : public A {
public:
    B(int a, int b): A(a,b){
        cout<<"Sub is: "<<a-b<<endl;
    }
};

int main(){
    B b(5,5);
    A a(5,5);
}