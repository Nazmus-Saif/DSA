#include <iostream>
using namespace std;

int main(){
    int max = 50;
    #if max > 50
        cout << "Correct" << endl;
    //#undef max
    #else
        cout << "Not 50" << endl;
    #endif
        cout << "Alo" << endl;
}