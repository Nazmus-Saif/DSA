#include<iostream>
#include<fstream>
using namespace std;

void checkstatus(ifstream &myfile){
    if(myfile.is_open())
        cout << "File is open" << endl;
    else
        cout << "File is closed" << endl;

    cout << "good(): " << myfile.good() << endl; // it returns bool type result means 0 or 1
    cout << "eof(): " << myfile.eof() << endl;
    cout << "fail(): " << myfile.fail() << endl;
    cout << "bad(): " << myfile.bad() << endl;

    cout << "goodbit: " << (myfile.rdstate() == ios::goodbit) << endl; // rdstate(): Returns the current state of the stream
    cout << "eofbit: " << (myfile.rdstate() & ios::eofbit) << endl; // it returns 0 or 1
    cout << "failbit: " << (myfile.rdstate() & ios::failbit) << endl;
    cout << "badbit: " << (myfile.rdstate() & ios::badbit) << endl;
}

int main(){
    char ch;
    ifstream myfile("myfile.txt");
    
    if(!myfile.is_open()){
        cout << "File does not exist" << endl;
        exit(1); // Exit if the file cannot be opened
    }

    checkstatus(myfile); // Check file status once after opening

    while(myfile.get(ch)){
        cout << ch;
        checkstatus(myfile); // Check file status after reading each character
    }

    cout << endl;
    myfile.close();

    return 0;
}
