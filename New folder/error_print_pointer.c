// #include <stdio.h>

// int main(){
//     char *P[] = {"Input exceeds field width", "Out of range", "Printer not turned on", "Paper out", "Disk full", "Disk write error"};
//     printf("%s\n", P[0]);
// }

#include <stdio.h>
#include <string.h>

int main() {
    char *responses[] = {"Yes", "No", "Maybe. Rephrase the question"};
    char question[100];
    int length, index;

    printf("Ask a question: ");
    fgets(question, sizeof(question), stdin);

    // Calculate the length of the question
    length = strlen(question);

    // Compute index using the formula
    index = length % 3;

    printf("Response: %s\n", responses[index]);

    return 0;
}
