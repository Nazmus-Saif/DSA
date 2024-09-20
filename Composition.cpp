// #include <iostream>
// using namespace std;

// class Engine {
// public:
//     Engine(int horsepower) : horsepower(horsepower) {}

//     void start() {
//         cout << "Engine with " << horsepower << " horsepower starts." << endl;
//     }

// private:
//     int horsepower;
// };

// class Car {
// public:
//     Car(Engine* engine) : engine(engine) {}

//     void drive() {
//         engine->start();
//         cout << "Car is driving." << endl;
//     }

// private:
//     Engine* engine;
// };

// int main() {
//     // Create an Engine instance
//     Engine myEngine(200);

//     // Create a Car instance with the Engine instance
//     Car myCar(&myEngine);

//     // Drive the car
//     myCar.drive();

//     return 0;
// }


// // in compositon one class use another class object functions etc.


#include <iostream>
using namespace std;

// Engine class definition
class Engine {
public:
    void start() {
        // Engine starting logic
        std::cout << "Engine started." << std::endl;
    }
    void stop() {
        // Engine stopping logic
        std::cout << "Engine stopped." << std::endl;
    }
};

// Wheel class definition
class Wheel {
    int size;
public:
    Wheel(int s) : size(s) {}
    void roll() {
        std::cout << "Wheel of size " << size << " rolling." << std::endl;
    }
};

// Car class definition
class Car {
    Engine engine;
    Wheel frontLeft;
    Wheel frontRight;
    Wheel rearLeft;
    Wheel rearRight;
public:
    Car(int wheelSize)
        : frontLeft(wheelSize), frontRight(wheelSize), rearLeft(wheelSize), rearRight(wheelSize) {}

    void start() {
        engine.start();
        frontLeft.roll();
        frontRight.roll();
        rearLeft.roll();
        rearRight.roll();
    }

    void stop() {
        engine.stop();
    }
};

// Main function to test the composition
int main() {
    Car myCar(17);  // All wheels are of size 17
    myCar.start();
    myCar.stop();
    return 0;
}
