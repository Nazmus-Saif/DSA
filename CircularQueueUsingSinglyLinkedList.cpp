#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = NULL; // Front of the queue
node* tail = NULL; // Rear of the queue

void enqueue();
void dequeue();
void display();

int main() {
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    display();
}

void enqueue() {
    int value;
    
    cout << "Enter Value: ";
    cin >> value;

    node* NewNode = new node();
    
    if (head == NULL) {
        NewNode->data = value;
        NewNode->next = NewNode;
        head = tail = NewNode;
        tail->next = head; // Circular link for the first node
    } else {
        NewNode -> data = value;
        NewNode -> next = tail;
        tail->next = NewNode;
        tail = NewNode;
        tail->next = head; // Update tail to point back to head
    }
    display();
}

void display() {
    node* temp = head;
    if (temp == NULL) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    cout << "Queue Data: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head); // Loop until we reach back to the head
    cout << endl;
}

void dequeue() {
    if (head == NULL) {
        cout << "Queue is Empty! Cannot dequeue." << endl;
        return;
    }
    
    node* temp = head;
    head = head->next;
    delete temp;
    tail->next = head; // Update tail to point to the new head

    if (head == NULL) {
        tail = NULL;
    }
    display();
}