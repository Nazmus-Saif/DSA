#include <iostream>
using namespace std;

int main(){

    int a = 10;
    // printf always print from left to right direction
    // printf always execute its taks from right to left direction
    // pre-increment always increase a first the asign the value to a
    printf("%d %d %d\n", a++, a++, a++); // 12 11 10 after first line currently a = 13
    printf("%d %d %d\n", ++a, ++a, ++a); // 16 16 16 as a pre increased 3 time so a = 16 now currently 
    printf("%d %d %d\n", a++, ++a, a++); // 18 19 16 after 3rd line currently a = 19
    printf("%d %d %d\n", ++a, a++, ++a); // 22 20 22 as a pre-increment 2 times so 

    int b = 10;
    printf("%d %d %d\n", ++b, ++b, ++b); // as b is increased 3 times in b same line so b increased first then print = 13 for all
    printf("%d\n", ++b); //  this print 14
    printf("%d %d\n", ++b, ++b); //  this print 16 for all
    printf("%d %d %d\n", ++b, ++b, ++b); //  this print 19 for all






    int aa = 1;
     b = ++aa + aa++; // ++a first increment then asing so a is now 2
                       // a++ first asign = 2 then increment so a is now 3 now this final increment value 3 is asign to
                       // pre-inrement ++a so this become now 3 that why 3 + 2 = 5
    printf("%d", b);

    int c = 1;
    b = c++ + ++c;
    printf("\n%d", b);

    int d = 1;
    b = ++d + d++ + ++d; // for more than one operation compiler process it like this (++d + d++) + ++d
    printf("\n%d", b);

    int e = 1;
    b = e++ + ++e + e++; // for more than one operation compiler process it like this (e++ + ++e) + e++
    printf("\n%d", b);

    int f = 1;
    b = ++f + ++f + f++; // for more than one operation compiler process it like this (++f + ++f) + f++
    printf("\n%d", b);

    int g = 1;
    b = g++ + ++g + ++g; // for more than one operation compiler process it like this (g++ + ++g) + g++
    printf("\n%d", b);

    int h = 1;
    b = h++ + h++ + ++h; // for more than one operation compiler process it like this (h++ + h++) + ++h
    printf("\n%d", b);

    int i = 1;
    b = ++i + i++ + i++; // for more than one operation compiler process it like this (++i + i++) + i++
    printf("\n%d", b);
}


/* if we write so many preincrement then it means that first increment all then asign the ans to all then use 
a = 5

++a, ++a, ++a, ++a, ++a, ++a

the above line is not like one by one increament 
it increaments its value until the last one then asign the value to all*/