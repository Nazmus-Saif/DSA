#include <iostream>
using namespace std;

struct {
    unsigned int isMale : 1;   // 1 bit for gender
    unsigned int age : 7;      // 7 bits for age
    unsigned int hasLicense : 1; // 1 bit for license status
} person;

int main() {
    person.isMale = 1;
    person.age = 25;
    person.hasLicense = 1;

    cout << "Is male: " << person.isMale << endl;
    cout << "Age: " << person.age << endl;
    cout << "Has license: " << person.hasLicense << endl;

    return 0;
}

// when we want to store short value which is not required full size data type like int 4byte = 32 bit we can use bit field 
// bit field is like a user defined data type size which we can set as our required when we need memory efficient