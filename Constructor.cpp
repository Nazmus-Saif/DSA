#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    int year;
public:
    // Default Constructor
    Car() {
        model = "Unknown";
        year = 0;
        cout << "Default constructor called." << endl;
    }

    // Parameterized Constructor
    Car(string model, int year) {
        this->model = model;
        this->year = year;
        cout << "Parameterized constructor called." << endl;
    }

    // Copy Constructor
    Car(const Car &car) {
        model = car.model;
        year = car.year;
        cout << "Copy constructor called." << endl;
    }

    // Method to display car details
    void displayDetails() {
        cout << "Car Model: " << model << endl;
        cout << "Manufacture Year: " << year << endl;
    }
};

int main() {
    // Creating an object using the default constructor
    Car car1;
    car1.displayDetails();

    // Creating an object using the parameterized constructor
    Car car2("Toyota Corolla", 2020);
    car2.displayDetails();

    // Creating an object using the copy constructor
    Car car3(car2);
    car3.displayDetails();

    return 0;
}