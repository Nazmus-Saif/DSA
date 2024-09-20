/* In C++, the :: operator is called the scope resolution operator. It is used for several purposes related to scoping and 
accessing elements in namespaces, classes, and derived classes. Here are the main uses of the :: operator in C++:

Accessing Static Members:

You use ClassName::staticMember to access static members (variables or functions) of a class directly without needing an 
instance of the class.
 */
class MyClass {
public:
    static int staticVar;
};

// Accessing static member variable
int MyClass::staticVar = 10;



//Accessing Nested Classes:

//When you have nested classes, you use OuterClass::InnerClass to access the nested class InnerClass from OuterClass.

class OuterClass {
public:
    class InnerClass {
        // Inner class definition
    };
};

// Creating an instance of the nested class
OuterClass::InnerClass obj;