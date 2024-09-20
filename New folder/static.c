// #include <stdio.h>

// void count() {
//     static int counter = 0; // Static variable initialization
//     counter++; // Increment the static variable
//     printf("Count: %d\n", counter); // Print the value of the static variable
// }

// int main() {
//     count(); // Call count() - prints Count: 1
//     count(); // Call count() again - prints Count: 2
//     count(); // Call count() again - prints Count: 3
//     return 0;
// }
// // as we use static keyword so it retian or maintain its last value of each function call thats why the 3 times count call print 1 2 3 not 1 every time

// #include <stdio.h>

// int function(){
//     static int count = 0;
//     count++;
//     printf("Count: %d\n", count);
//     if(count == 10)
//     return 1;
//     function();
// }

// int main(){
//     function();
// }
// in the above recursion every time it retain its last value of count and increment every time as we use static
// if we not use this it will print 1 every time


// but this retian the value will be wrok in function call only if we right inside in main then it will not


#include <stdio.h>

void sum_it(int value);

int main() {
    sum_it(3);
    sum_it(6);
    sum_it(4);

    return 0;
}

void sum_it(int value) {
    static int total = 0; // Static variable to maintain running total
    total += value;
    printf("%d\n", total);
}
