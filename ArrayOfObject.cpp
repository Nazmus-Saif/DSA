#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    // Car(string b) : brand(b) {}
    Car(string b) {
        this->brand = b;
    }
    void display() {
        cout << "Brand: " << brand << endl;
    }
};

int main() {
    Car cars[3] = { Car("Toyota"), Car("Ford"), Car("Honda") };
    for (int i = 0; i < 3; ++i) {
        cars[i].display();
    }
    return 0;
}
