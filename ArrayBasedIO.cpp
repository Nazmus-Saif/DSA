#include <iostream>
#include <sstream>
using namespace std;

int main() {
    ostringstream data;
    data << "Array like I/O uses stream just like normal I/O" << endl;
    
    // Convert the ostringstream to string to print its content
    string buffer = data.str();
    
    cout << buffer.size() << endl;
    cout << buffer;
    return 0;
}