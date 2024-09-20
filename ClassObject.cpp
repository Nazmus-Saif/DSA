#include <iostream>
using namespace std;

// Rectangle class definition
class Rectangle {
private:
    // Private data members
    double width;
    double height;

public:
    // Default constructor
    Rectangle() : width(0), height(0) {}

    // Parameterized constructor using initializer list
    Rectangle(double w, double h) : width(w), height(h) {}

    // // Constructor using assignment in the body
    // Rectangle(double w, double h) {
    //     this->width = w;
    //     this->height = h;
    // }

    // Member function to set dimensions
    void setDimensions(double w, double h) {
        width = w;
        height = h;
    }

    // Member function to get width
    double getWidth() const {
        return width;
    }

    // Member function to get height
    double getHeight() const {
        return height;
    }

    // Member function to calculate area
    double area() const {
        return width * height;
    }

    // Member function to print dimensions
    void printDimensions() const {
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

int main() {
    // Creating objects using different constructors
    Rectangle rect1;  // Default constructor
    Rectangle rect2(5.0, 3.0);  // Parameterized constructor

    // Using member functions
    rect1.setDimensions(4.0, 2.5);

    // Printing dimensions and area
    cout << "Rectangle 1:" << endl;
    rect1.printDimensions();
    cout << "Area: " << rect1.area() << endl;

    cout << "Rectangle 2:" << endl;
    rect2.printDimensions();
    cout << "Area: " << rect2.area() << endl;

    return 0;
}