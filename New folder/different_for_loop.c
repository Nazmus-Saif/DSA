#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
    // int i, j;
    // printf("Enter i j : ");
    // scanf("%d %d", &i, &j);
    
    // for(i,j; i,j; i--,j--){
    //     printf("%d\n", i*j);
    // }
    char ch;
    // for(ch = getc(stdin); ch != 's'; ch = getc(stdin));
    for(ch = getch(); ch != 's'; ch = getch()); // when key is pressed it not shown in console
     //for(ch = getche(); ch != 's'; ch = getche()); // getche() not go to new line
    //for(ch = getchar(); ch != 's'; ch = getchar()); // semicolon means this loop has no body
    printf("s found");
    return 0;
}