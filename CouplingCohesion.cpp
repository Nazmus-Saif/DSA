#include <iostream>
using namespace std;

class Engine {
public:
    void start() {
        cout<<"Engine Stars."<<endl;
    }
};

class Car {
    Engine engine;
public:
    void start() {
        engine.start();
    }
};
// the above code is for tight coupling