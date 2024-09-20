#include <iostream>
using namespace std;

class A{
public:
    void sum(long a, long b){
        cout<<"int method is invoked"<<endl;
    }

    void sum(int a, long b){
        cout<<"long method is invoked"<<endl;
    }
};

int main(){
    A a;
    a.sum(10,20);
}