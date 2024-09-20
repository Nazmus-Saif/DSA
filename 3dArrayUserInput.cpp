#include <iostream>
using namespace std;

int main(){
    int x,y,z;

    cout << "Enter Nubmer: ";
    cin >> x >> y >> z;

    int array[x][y][z], i, j, k;
    cout << endl;

    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            for(k = 0; k < z; k++){
                cout << "Array[" << i << "]" << "[" << j << "]" << "[" << k << "]" << endl;
                cin >> array[i][j][k];
            }
        }
    }
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            for(k = 0; k < z; k++){
                cout << array[i][j][k];
            }
            cout << endl;
        }
    }

    return 0;
}
