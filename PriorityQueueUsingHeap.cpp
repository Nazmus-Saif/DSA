#include <iostream>
using namespace std;

const int SIZE = 100; // Maximum size of the queue

struct Element {
    int value;
    int priority;
};

Element queue[SIZE];
int rear = -1; // Rear pointer for the queue

void enqueue();
void dequeue();
void heapifyUp(int index);
void heapifyDown(int index);
void display();

int main() {
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    dequeue();
    dequeue();
}

void enqueue() {
    if (rear == SIZE - 1) { // Check for queue overflow
        cout << "Queue Overflow!" << endl;
        return;
    }

    int value, priority;
    cout << "Enter Value: ";
    cin >> value;
    cout << "Enter Priority: ";
    cin >> priority;

    rear++;
    queue[rear].value = value;
    queue[rear].priority = priority;

    // Heapify up to maintain heap property
    heapifyUp(rear);

    display();
}

void dequeue() {
    if (rear == -1) { // Check if queue is empty
        cout << "Queue is Empty! Cannot dequeue." << endl;
        return;
    }

    // Swap root with last element
    swap(queue[0], queue[rear]);
    rear--; // delete the smallest element

    // Heapify down from root to maintain heap property
    heapifyDown(0);

    display();
}

/* HeapifyUp and HeapifyDown are essential operations for maintaining the properties of a max-heap or min-heap. In a max-heap, 
HeapifyUp ensures that newly added elements move up the tree to maintain the property that each parent node is greater than or 
equal to its children, 
while HeapifyDown ensures that when the root is removed, the last element replaces it and moves down the
tree to restore the max-heap property. Conversely, in a min-heap, HeapifyUp moves the new element upwards to maintain the 
property that each parent node is less than or equal to its children, and HeapifyDown ensures that the root replacement moves 
downwards to maintain the min-heap property. These operations guarantee that the heap structure remains valid after insertions
and deletions, keeping the binary heap efficient for priority queue operations. */

// HeapifyUp: Maintains the heap property by moving the new element up the tree.
void heapifyUp(int index) { // Ensures the heap property is maintained when adding elements.
    int parent = (index - 1) / 2;
    while (index > 0 && queue[index].priority < queue[parent].priority) {  // less than (<) sign for min heap use > for max heap
        swap(queue[index], queue[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// HeapifyDown: Maintains the heap property by moving the new root element down the tree.
void heapifyDown(int index) { // Ensures the heap property is maintained when removing elements.
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index; // int largest = index; if max heap is used

    if (left <= rear && queue[left].priority < queue[smallest].priority) { // less than (<) sign for min heap use > for max heap
        smallest = left;
    }
    if (right <= rear && queue[right].priority < queue[smallest].priority) { // less than (<) sign for min heap use > for max heap
        smallest = right;
    }

    if (smallest != index) {
        swap(queue[index], queue[smallest]);
        heapifyDown(smallest);  // repeat the process if needed
    }
}

void display() {
    if (rear == -1) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    cout << "Queue Data: ";
    for (int i = 0; i <= rear; i++) {
        cout << "(" << queue[i].value << ", " << queue[i].priority << ") ";
    }
    cout << endl;
}