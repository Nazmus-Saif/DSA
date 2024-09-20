#include <iostream>
using namespace std;

class Sample {
private:
    int* data;
public:
    // Constructor
    Sample(int value) {
        data = new int; // dynamically allocate memory for the pointer in run time
        *data = value;  // then assigns the value to it
    }
    
    // Copy Constructor
    Sample(const Sample &obj) {
        data = new int;
        *data = *(obj.data);
    }
    
    // Destructor
    ~Sample() {
        delete data;  // as the value is stored in heap, we need to delete it
    }

    // If the pointer is pointing to memory that was dynamically allocated using new or malloc, then it's pointing to memory in the heap.
    // If the pointer is pointing to a local variable within a function, it's pointing to memory in the stack.

    void display() {
        cout << "Value: " << *data << endl;
    }
};

int main() {
    Sample obj1(10); // Normal constructor
    Sample obj2 = obj1; // Copy constructor

    obj1.display();
    obj2.display();

    return 0;
}
