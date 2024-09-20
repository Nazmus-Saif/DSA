#include<iostream>
#include<fstream>
using namespace std;

int main() {
    char ch;
    ifstream read("myfile.txt");
    if (!read) {
        cout << "File not found";
    } else {
        while (read.get(ch)) {  // read.get(ch) returns false when EOF is reached
            cout << ch;  // Output the character read
            // Peek the next character
            char next = read.peek();
            if (next != EOF) {
                cout << " (\t\tPeeked: " << next << ")";  // Output the peeked character
            } else {
                cout << " (End of File)";
            }       
            cout << endl;  // Move to the next line
        }
    }
    read.close();  // Close the file
    return 0;
}
