#include <iostream>
using namespace std;

int main() {
    istream& input = cin;

    // Read a character from input
    char c;
    input.get(c);

    // Check if 'c' is a digit
    if (isdigit(c)) {
        cout << "First character is a digit.\n";
    } else {
        cout << "First character is not a digit.\n";

        // Put the character back into the input stream
        input.putback(c);
    }

    // Read the character again
    input.get(c);
    cout << "First character read: " << c << '\n';
    // if we not using the putback() then we can not read the character again without putback() we can read the character one time
    input.putback(c);
    input.get(c);
    cout << "Second character read: " << c << '\n';

    return 0;
}
