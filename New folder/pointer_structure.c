#include <stdio.h>

struct student
{
    int roll;
    char name[20];
    int marks;
};

// int main(){
//     struct student s1;
//     struct student *ptr;
//     ptr = &s1;
//     printf("Enter roll no.: ");
//     scanf("%d", &ptr->roll);
//     printf("Enter name: ");
//     scanf("%s", ptr->name);
//     printf("Enter marks: ");
//     scanf("%d", &ptr->marks);
//     printf("Roll no.: %d\n", ptr->roll);
//     printf("Name: %s\n", ptr->name);
//     printf("Marks: %d\n", ptr->marks);
// }

int main(){
    struct student batch1[5] = {'1', '2', '3'};
    struct student *ptr;
    ptr = batch1;
    printf("Enter roll no.: ");
    scanf("%d", &(ptr+1)->roll); // (ptr+1) this will store the value for index 2
    printf("Enter name: ");
    scanf("%s", ptr->name);
    printf("Enter marks: ");
    scanf("%d", &ptr->marks);
    printf("Roll no.: %d\n", (ptr+1)->roll);
    printf("Name: %s\n", ptr->name);
    printf("Marks: %d\n", ptr->marks);
}