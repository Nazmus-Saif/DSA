#include <iostream>
using namespace std;

int main() {
    char string[50] = "My name is Nazmus Saif";
    char after_space[50];
    int j = 0;
    int found_space = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ' ') {
            found_space++;
        }
        if (found_space) {
            after_space[j] = string[i];
            j++;
        }
    }
    cout << found_space << endl;
    after_space[j] = '\0'; // Null terminate the new string

    cout << after_space << endl;

    return 0;
}