#include <iostream>
#include <string>
using namespace std;

class Student{
private:
    string Name;
    int Age;
public:
    Student(string name, int age){
        this->Name = name;
        this->Age = age;
    }
    void printDetails(){
        cout<< "Name is: "<< Name << endl;
        cout<< "Age is: "<< Age;
    }
};

int main(){
    Student Saif("Nazmus Saif", 24);
    Saif.printDetails();
}