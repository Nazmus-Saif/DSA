#include <iostream>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a new node at the beginning of a linked list
void push(Node*& head, int newData) {
    Node* newNode = new Node(newData);
    newNode->next = head;
    head = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to perform insertion sort on a singly linked list
void insertionSort(Node*& head) {
    Node* sorted = nullptr; // Initialize sorted linked list
    Node* current = head;   // Traverse the given linked list
    
    while (current != nullptr) {
        Node* next = current->next; // Store the next node to be sorted
        
        // Insert current node into sorted linked list
        if (sorted == nullptr || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        
        current = next; // Move to next node in the original list
    }
    
    head = sorted; // Update head pointer to point to sorted linked list
}

int main() {
    Node* head = nullptr;
    
    // Example linked list: 5 -> 3 -> 4 -> 1 -> 2
    push(head, 2);
    push(head, 1);
    push(head, 4);
    push(head, 3);
    push(head, 5);
    
    cout << "Original linked list: ";
    printList(head);
    
    insertionSort(head);
    
    cout << "Sorted linked list: ";
    printList(head);
    
    return 0;
}