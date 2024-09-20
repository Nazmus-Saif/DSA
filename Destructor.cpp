#include <iostream>
using namespace std;

class Destructor{
    private:
        int age;
    public:
        Destructor(){
            age = 0;
        }
        
        Destructor(int age){
            this->age = age;
        }

        // ~Destructor(){
        //     delete age;
        // }
        // since we have using a non pointer variable we dont need to delete it using dstructor because non ponter varaible automatically
        // delete after executing. pointer variable must be deleted or free manually.

        int printValue(){
            cout<<"Age is " << age<<endl;
        }
};

int main(){
    Destructor One;
    One.printValue();

    Destructor Two(10);
    Two.printValue();
}