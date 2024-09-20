#include <iostream>
using namespace std;

const int SIZE = 100; // Maximum size of the queue

struct Element {
    int value;
    int priority;
};

Element queue[SIZE];
int front = -1, rear = -1;

void enqueue();
void dequeue();
void display();

int main() {
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    dequeue();
}

void enqueue() {
    if (rear == SIZE - 1) { // SIZE - 1 means last of the queue
        cout << "Queue Overflow!" << endl;
        return;
    }

    int value, priority;
    cout << "Enter Value: ";
    cin >> value;
    cout << "Enter Priority: ";
    cin >> priority;

    if (front == -1) front = 0; 

    // Find the correct position to insert the new element
    int i;
    for (i = rear; i >= front; i--) {
        if (queue[i].priority > priority) {
            queue[i + 1] = queue[i];
        } else {
            break; // this will break the loop
        }
    }
    queue[i + 1].value = value;
    queue[i + 1].priority = priority;
    rear++;
    display();
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty! Cannot dequeue." << endl;
        return;
    }
    front++; // increase the front so that it skips the current position and increases its position
    display();
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    cout << "Queue Data: ";
    for (int i = front; i <= rear; i++) {
        cout << "(" << queue[i].value << ", " << queue[i].priority << ") ";
    }
    cout << endl;
}