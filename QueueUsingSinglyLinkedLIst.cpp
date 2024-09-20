#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head = NULL; // Front of the queue
node* tail = NULL; // Rear of the queue

void enqueue();
void dequeue();
void display();

int main(){
    enqueue();
    enqueue();
    dequeue();
    display();
}

void enqueue(){
    int value;
    
    cout << "Enter Value: ";
    cin >> value;

    node* NewNode = new node();
    NewNode->data = value;
    NewNode->next = NULL;
    
    if (head == NULL){
        head = tail = NewNode;
    } else {
        tail->next = NewNode;
        tail = NewNode;
    }
    display();
}

void display(){
    node* temp = head;
    if(temp == NULL){
        cout << "Queue is Empty!" << endl;
        return;
    }

    cout << "Queue Data: ";
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void dequeue(){
    if (head == NULL) {
        cout << "Queue is Empty! Cannot dequeue." << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    if (head == NULL) { // If the queue is now empty, update the tail to NULL
        tail = NULL;
    }
    display();
}