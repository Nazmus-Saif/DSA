// #include <iostream>
// using namespace std;

// class A{
//     int x = 5;
//     public:
//     void show(){
//         cout<<"Value of x is: "<<x<<endl;
//     }
// };

// class B: public A{
//     int y = 10;
//     public:
//     void show(){
//         cout<<"Value of y is: "<<y<<endl;
//     }
// };

// int main(){
//     A *a;
//     B b;
//     a = &b;
//     a->show();
//     b.show();

//     A a1;
//     B b2;
//     a1 = b2;
//     a1.show();

//     // as we store the address of b object to a still now class A value will be print 
//     // because the value is not override for not using virtual keyword
//     // if we using virtual keyword then the value will be updated
// }





#include <iostream>
using namespace std;

class A{
    int x = 5;
    public:
    virtual void show(){
        cout<<"Value of x is: "<<x<<endl;
    }
};

class B: public A{
    int y = 10;
    public:
    void show(){
        cout<<"Value of y is: "<<y<<endl;
    }
};

int main(){
    A *a;
    B b;
    a = &b;
    a->show();
    A a1; 
    a1.show();
    B b1;
    b1.show();
}

// virtual void execute() = 0;

/* This syntax specifies that the function is pure virtual. A pure virtual function does not provide an implementation
in the base class and must be overridden in any derived class. The = 0 part makes the class containing this function
abstract, meaning you cannot instantiate objects of this class directly. */