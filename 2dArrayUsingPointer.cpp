#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const char* p[][2] = {{"Red Delicious",     "red"},
                          {"Golden Delicious",  "yellow"},
                          {"Hnesap",            "red"},
                          {"Gala",              "reddish orange"},
                          {"Lodi",              "green"},
                          {"Mutsu",             "yellow"},
                          {"Cortland",          "red"},
                          {"Jonathan",          "red"}};

    int i;
    char apple[50];  // Increase size to accommodate longer apple names
    cout << "Enter name of apple: ";
    cin.getline(apple, 50);  // Use cin.getline instead of gets

    for (i = 0; *p[i][0]; i++) {
        // if (!strcmp(apple, p[i][0])) { == 0 and ! means same
        if (strcmp(apple, p[i][0]) == 0) {
            cout << apple << " is " << p[i][1] << endl;
            break;  // Break the loop once the match is found
        }
    }

    if (!*p[i][0]) {  // If no match was found, *p[i][0] would be false
        cout << "Apple not found in the list." << endl;
    }
    return 0;
}