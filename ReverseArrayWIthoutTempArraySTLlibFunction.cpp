#include <stdio.h>
#include <string.h>

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
    
    printf("Original string: %s\n", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}


#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string str = "Saif";
    int length = str.length();
    int start = 0;
    int end = length - 1;

    while(start < end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
        
        // or swap function => swap(str[start++], str[end--]);
    }
    cout << str << endl;
}