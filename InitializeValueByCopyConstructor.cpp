#include <iostream>
using namespace std;

class A {
private:
    int value;

public:
    // Default constructor
    A(int v = 0) : value(v) {
        cout << "Default constructor is called" << endl;
        cout<<value<<endl;
    }

    // Copy constructor
    A(const A& obj) {
        value = obj.value;
        //value = 100; // this will change the value of variable respect to this constructor
        cout << "Copy constructor is called" << endl;
        cout<<value<<endl;
    }

    // Getter for value
    int getValue() const {
        return value;
    }
};

int main() {
    A obj1(10);    // Default constructor
    A obj2 = obj1; // Copy constructor

    cout << "obj1 value: " << obj1.getValue() << endl;
    cout << "obj2 value: " << obj2.getValue() << endl;

    return 0;
}
