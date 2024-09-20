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
    Base baseObj;
    Derived derivedObj;

    // Call the method on the base class object
    baseObj.displayValue(); // Output: Value from Base class

    // Call the method on the derived class object
    derivedObj.displayValue(); // Output: Value from Derived class

    // Using a pointer to the base class to point to a derived class object
    Base* basePtr = &derivedObj;
    basePtr->displayValue(); // Output: Value from Derived class

    return 0;
}