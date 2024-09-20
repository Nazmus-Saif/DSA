#include <iostream>

class OuterClass {
public:
    OuterClass() {
        std::cout << "OuterClass Constructor called.\n";
    }

    class InnerClass {
    public:
        InnerClass() {
            std::cout << "InnerClass Constructor called.\n";
        }
    };
};

int main() {
    OuterClass::InnerClass inner; // constructur is called when object is created

    return 0;
}
