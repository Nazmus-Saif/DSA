#include <iostream>
using namespace std;

struct node {
    int data;
    int priority; // for priority
    node* next;
};

node* head = NULL; // Front of the queue

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
    int value, priority; // for priority
    
    cout << "Enter Value: ";
    cin >> value;
    cout << "Enter Priority: ";
    cin >> priority;

    node* NewNode = new node();
    NewNode->data = value;
    NewNode->priority = priority; // add priority value
    NewNode->next = NULL;
    
    if (head == NULL || head->priority > priority) { // priority condition
        if (head != NULL){
            NewNode->next = head;
        }
        head = NewNode;
    } else {
        node* temp = head;
        while (temp->next != NULL && temp->next->priority <= priority) { // priority condition
            temp = temp->next;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;
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
    while (temp != NULL) {
        cout << "(" << temp->data << ", " << temp->priority << ") ";
        temp = temp->next;
    }
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
    display();
}