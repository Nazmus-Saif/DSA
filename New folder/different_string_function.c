#include <stdio.h>
#include <conio.h>

int main() {
    // Example using getchar() and putchar()
    // printf("Enter a character: ");
    // char ch = getchar(); // Reads a character from stdin
    // putchar(ch); // Writes the character to stdout

    // // Example using getc() and putc() with stdin and stdout
    // printf("\nEnter a character: ");
    // char ch2 = getc(stdin); // Reads a character from stdin
    // putc(ch2, stdout); // Writes the character to stdout

    // Example using getche()
    printf("\nEnter a character: ");
    char ch3 = getche(); // Reads a character from stdin and echoes it
    putchar('\n'); // Newline
    //putchar(ch3); // Writes the character to stdout

    // // Example using getch() (note: not portable)
    // printf("\nPress any key (without Enter): ");
    // char ch4 = getch(); // Reads a character from console without echoing
    // printf("\nYou pressed: ");
    // putchar(ch4); // Writes the character to stdout

    // // Example using fgetc() and fputc() with file streams
    // FILE *file1 = fopen("example.txt", "r");
    // if (file1) {
    //     printf("\nContents of file (fgetc/fputc):\n");
    //     int c;
    //     while ((c = fgetc(file1)) != EOF) {
    //         fputc(c, stdout);
    //     }
    //     fclose(file1);
    // }

    // // Example using fgets() and fputs() with file streams
    // FILE *file2 = fopen("example.txt", "r");
    // if (file2) {
    //     printf("\nContents of file (fgets/fputs):\n");
    //     char line[100];
    //     while (fgets(line, sizeof(line), file2) != NULL) {
    //         fputs(line, stdout);
    //     }
    //     fclose(file2);
    // }

    return 0;
}
