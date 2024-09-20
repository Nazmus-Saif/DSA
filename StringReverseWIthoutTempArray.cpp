#include <iostream>
#include <cstring>
using namespace std;

void reverseString(char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        // Swap the characters at start and end
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move the pointers towards each other
        start++;
        end--;
    }
}

int main() {
    char str[] = "Hello, World!";
    
    cout << "Original string: " << str << endl;

    reverseString(str);

    cout << "Reversed string: " << str << endl;

    return 0;
}