#include <iostream>
using namespace std;

int main(){
    char ch[100];
    char *p;
    p = ch;
    *(p + 2) = 'a';
    cout << *(p + 2) << endl;

    return 0;
}