#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int data;
    struct node* next;
};

int main(){
    node* newNode = new node();
    // new allocates memory and call the constructor to initialize it.
    // new returns bad allocations if failed.
    // new can be overloaded in class.
 
    if(newNode == NULL){
        cout << "Memory Allocation Failed!" << endl;
    }

    newNode -> data = 10;
    newNode -> next = NULL;

    cout << "Linked list contains 1 data: " << newNode -> data << endl;

    delete newNode;

    return 0;
}