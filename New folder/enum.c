#include <stdio.h>

enum week {my , name , is, saif}; // declaration

enum permission{
    EXECUTE = 1, // 001
    WRITE = 2,   // 010
    READ = 4     // 100
           // total 111 = 7 in decimal (1+2+7)
};

int main(){
    enum week today = is;
    printf("%d\n", is); // it print the indexing

    int permission = EXECUTE | WRITE | READ; // bit wise or
    printf("%d", permission);
}

// enum is a user define data type
// enum return a integer value 
// when we want to count we use enum
// wen can declare enum in global scop as well as local scope
// in macros like #define PI 3.1416 we have to define the value but in enum compiler sutomatically asign the value by compiler
// if we declare the first variable like my = 5 then the second value will be previous + 1
// if we declare multiple enum in a same scope then duplicate values are not allowed in different scope it is allowed
// only integers value are allowed no floating values are allowed
// WHEN WE NEED A SET OF POSSIBLE VALUES THEN WE USE ENUM like there are 7 days in a week
// in switch case we can use this enum instead of writing case 0 case 1 we can write case a case b 0 replace by a 1 replace by b which is more readable in some cases