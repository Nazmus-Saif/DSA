#include <stdio.h>

int main(){
    char sentence[50] = "My name is Nazmus Saif";
    int character_count[256] = {0}; // this will store the count of all the characters, initialized count with 0 & 256 inlcude all the ascii characters
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        character_count[(int)sentence[i]]++; // this will increment the count of the character and save the ascii value of the character
    }
    for (int i = 0; i < 256; i++)
    {
        if (character_count[i] != 0 && i != ' ') // this will print the count of all the characters, if the count is not 0 and the space
        {
            printf("%c : %d\n", i, character_count[i]); // we use %c to print the character which is saved in ascii form
        }
    }
    return 0;
}