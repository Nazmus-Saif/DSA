#include <stdio.h>
#include <stdarg.h>

void print_integers(int num, ...) {
    va_list args;
    va_start(args, num);
    for (int i = 0; i < num; ++i) {
        int value = va_arg(args, int);
        printf("%d ", value);
    }
    va_end(args);
    printf("\n");
}

int main() {
    print_integers(3, 1, 2, 3);  // Output: 1 2 3
    print_integers(5, 10, 20, 30, 40, 50);  // Output: 10 20 30 40 50
    return 0;
}
