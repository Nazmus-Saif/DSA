// in the following code i have made some function and put them into a function array pointer

#include <stdio.h>

int sum(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int mul(int a, int b){
    return a * b;
}

int div(int a, int b){
    if (b<0){
        return -1;
    }
    return a / b;
}

int (*operation[4]) (int a, int y) = {
    sum, sub, mul, div // this is not function call this is callback of function name
};

int main(){
    int a, b;
    int op;
    int result;
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    printf("Enter operation: ");
    scanf("%d", &op);
    result = (*operation[op])(a, b);
    printf("Result: %d\n", result);
}
