#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

node* head = NULL; // Front of the deque
node* tail = NULL; // Rear of the deque

void insertAtHead();
void insertAtTail();
void deleteAtHead();
void deleteAtTail();
void display();

int main() {
    insertAtHead();
    insertAtTail();
    deleteAtHead();
    deleteAtTail();
    display();
    return 0;
}

void insertAtHead() {
    int value;
    cout << "Enter Value to insert at head: ";
    cin >> value;

    node* newNode = new node();
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }
    display();
}

void insertAtTail() {
    int value;
    cout << "Enter Value to insert at tail: ";
    cin >> value;

    node* newNode = new node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    display();
}

void deleteAtHead() {
    if (head == NULL) {
        cout << "Deque is Empty! Cannot delete at head." << endl;
        return;
    }

    node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }

    delete temp;
    display();
}

void deleteAtTail() {
    if (tail == NULL) {
        cout << "Deque is Empty! Cannot delete at tail." << endl;
        return;
    }

    node* temp = tail;
    tail = tail->prev;

    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }

    delete temp;
    display();
}

void display() {
    node* temp = head;
    if (temp == NULL) {
        cout << "Deque is Empty!" << endl;
        return;
    }

    cout << "DQueue Data: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}