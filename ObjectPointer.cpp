#include <iostream>
using namespace std;

class Car {
private:
    string brand;
public:
    Car(string b) : brand(b) {}
    void display() {
        cout << "Brand: " << brand << endl;
    }
    string getName(){
        return brand;
    }
};

int main() {
    Car car1("BMW");
    car1.display();
    cout<<"Brand: "<<car1.getName()<<endl;

    Car* car2 = new Car("TOYOTA");
    car2->display();
    delete car2; // after using new keyword we have to delete this also.
}
