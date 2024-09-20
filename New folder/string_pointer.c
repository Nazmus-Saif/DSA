#include <stdio.h>
#include <string.h>

void swap(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void print_permutations(char **strings, int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%s ", strings[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            swap(&strings[start], &strings[i]);
            print_permutations(strings, start + 1, end);
            swap(&strings[start], &strings[i]);
        }
    }
}

int main() {
    char *str1 = "one";
    char *str2 = "two";
    char *str3 = "three";

    char *strings[] = {str1, str2, str3};

    printf("All permutations:\n");
    print_permutations(strings, 0, 2);

    return 0;
}
