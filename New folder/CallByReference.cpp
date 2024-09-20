#include <iostream>
using namespace std;

void  scan_input(int *num, int min, int max){
    do{
        scanf("%d", num);
    }while(*num<min || *num>max);

}

int main(){
    int num;
    cout << "Enter a num between 1 to 10: " << endl;
    scan_input(&num, 1, 10);
}