// #include <stdio.h>

// int main(int argc, char *argv[])
// {
//     int i = 0;

//     // go through each string in argv
//     // why am I skipping argv[0]?
//     for (i = 1; i < argc; i++) {
//         printf("arg %d: %s\n", i, argv[i]);
//     }

//     // let's make our own array of strings
//     char *states[] = {
//         "California", "Oregon",
//         "Washington", "Texas"
//     };

//     int num_states = 4;

//     for (i = 0; i < num_states; i++) {
//         printf("state %d: %s\n", i, states[i]);
//     }

//     return 0;
// }

// // $ ./a.out one two three four
// // arg 1: one
// // arg 2: two
// // arg 3: three
// // arg 4: four
// // state 0: California
// // state 1: Oregon
// // state 2: Washington
// // state 3: Texas

// // $ ./a.out
// // arg 1: (null

// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char *argv[]) {
//     double pounds;

//     if (argc != 2) {
//         printf("Usage: %s <ounces>\n", argv[0]);
//         printf("Try Again\n");
//         exit(1);
//     }

//     pounds = atof(argv[1]) / 16.0;
//     printf("%f pounds\n", pounds);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(int argc, char *argv[]) {
//     if (argc != 4) {
//         printf("Usage: %s <operation> <num1> <num2>\n", argv[0]);
//         // by dafult the first arg argv[0] is the name of the program so we have to assing value by after next 0
//         return 1;
//     }

//     float num1 = atof(argv[2]);
//     float num2 = atof(argv[3]);

//     if (strcmp(argv[1], "add") == 0) {
//         float total = num1 + num2;
//         printf("The sum of %.2f and %.2f is: %.2f\n", num1, num2, total);
//     }
//     else if (strcmp(argv[1], "sub") == 0) {
//         float total = num1 - num2;
//         printf("The difference of %.2f and %.2f is: %.2f\n", num1, num2, total);
//     }
//     else if (strcmp(argv[1], "mul") == 0) {
//         float total = num1 * num2;
//         printf("The product of %.2f and %.2f is: %.2f\n", num1, num2, total);
//     }
//     else if (strcmp(argv[1], "div") == 0) {
//         if (num2 == 0) {
//             printf("Cannot divide by zero\n");
//             return 1;
//         }
//         float total = num1 / num2;
//         printf("The division of %.2f and %.2f is: %.2f\n", num1, num2, total);
//     }
//     else {
//         printf("Invalid operation\n");
//         return 1;
//     }

//     return 0;
// }







#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void performOperation(char* operation, float num1, float num2) {
    if (strcmp(operation, "add") == 0) {
        printf("The sum of %.2f and %.2f is: %.2f\n", num1, num2, num1 + num2);
    }
    else if (strcmp(operation, "sub") == 0) {
        printf("The difference of %.2f and %.2f is: %.2f\n", num1, num2, num1 - num2);
    }
    else if (strcmp(operation, "mul") == 0) {
        printf("The product of %.2f and %.2f is: %.2f\n", num1, num2, num1 * num2);
    }
    else if (strcmp(operation, "div") == 0) {
        if (num2 == 0) {
            printf("Cannot divide by zero\n");
            return;
        }
        printf("The division of %.2f and %.2f is: %.2f\n", num1, num2, num1 / num2);
    }
    else {
        printf("Invalid operation\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <operation> <num1> <num2>\n", argv[0]);
        return 1;
    }

    float num1 = atof(argv[2]);
    float num2 = atof(argv[3]);

    performOperation(argv[1], num1, num2);

    return 0;
}
