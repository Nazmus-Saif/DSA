#include <stdio.h>
#include <time.h>

int main(){
    register int i;
    int j;
    clock_t start, end;

    start = clock();
    for (i = 0; i < 10000; i++){
        printf("%d", i);
    }
    end = clock();
    printf("\n");
    printf("\nExecution Time of Register Loop: %d\n", end-start);
    printf("\n");

    start = clock();
    for (j = 0; j < 10000; j++){
        printf("%d", j);
    }
    end = clock();
    printf("\n");
    printf("\nExecution Time of Non Register Loop: %d\n", end-start);
    printf("\n");
    return 0;
}