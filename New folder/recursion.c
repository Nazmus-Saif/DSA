// #include <stdio.h>

// void recursion(int a){
//     if (a < 10){
//         recursion(a+1); // it goes deper under a < 10 then print the a one by one that why it print from 9 to 0
//         printf("%d\t", a);
//         recursion(a+1); // it first print then called thats why it print from 0 to 9
//     }
// }

// int main(){
//     recursion(0);
// }

// string copy ussing recursion

// #include <stdio.h>

// void recursion(char *s, char *t){
//     while(*s != '\0'){
//         *s++ = *t++;
//         recursion(s, t);
//     }
// }

// int main(){
//     char string[10];
//     recursion(string, "Hello");
//     printf("%s", string);
// }

#include <stdio.h>

void f(void){
    printf("f()");
    for (int i=0; i<10; i++){
        f();
    } // in this recursion there is no starting parameter thats why it will become infite loop 
}

int main(){
    f();
}