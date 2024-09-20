#include <iostream>

// Base class
class Base {
public:
    // Virtual method that will be overridden
    virtual void displayValue() {
        std::cout << "Value from Base class" << std::endl;
    }
};

// Derived class
class Derived : public Base {
public:
    // Override the displayValue method
    void displayValue() {
        std::cout << "Value from Derived class" << std::endl;
    }
};

int main() {
    Base baseObj; // Creating an object of the base class

    // Using base class object directly
    baseObj.displayValue(); // Output: Value from Base class

    // Using derived class object directly
    Derived derivedObj;
    derivedObj.displayValue(); // Output: Value from Derived class

    // Using base class pointer to derived class object
    Base* basePtr = &derivedObj;
    basePtr->displayValue(); // Output: Value from Derived class

    return 0;
}