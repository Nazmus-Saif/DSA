#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int data;
    struct node* next;
};

int main(){
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    // malloc allocates memorybut does not initialize it, the initialize memeory contains garbeg value. So we have to manually set it
    // (means we have to manually assign value here.)
    // malloc returns NULL if failed.
    // malloc can't over loaded.

    if(newNode == NULL){
        cout << "Memory Allocation Failed!" << endl;
    }

    newNode -> data = 10;
    newNode -> next = NULL;

    cout << "Linked list contains 1 data: " << newNode -> data << endl;

    free(newNode);

    return 0;
}