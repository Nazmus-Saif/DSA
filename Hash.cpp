#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> my_map;
    my_map["apple"] = 10;
    cout << my_map["apple"];
    return 0;
}