#include <iostream>
using namespace std;

struct node {
    node* prev;
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
        NewNode->next = NewNode->prev = NewNode; // Circular linkage for the first node
        head = tail = NewNode;
    } else {
        NewNode->data = value;
        NewNode->next = head; // New node points to head
        NewNode->prev = tail; // New node's previous points to current tail
        tail->next = NewNode; // Update current tail's next to point to new node
        tail = NewNode; // Update tail to the new node
        head->prev = tail; // Update head's previous to point back to new tail
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
    if (head == tail) { // Only one element in the queue
        head = tail;
    } else {
        head = head->next; // Move head to the next node
        head->prev = tail; // Update new head's previous to point to tail
        tail->next = head; // Update tail's next to point to new head
    }
    delete temp;
    
    display();
}
