#include <iostream>
using namespace std;

const int SIZE = 100; // Maximum size of the queue
int queue[SIZE];
int front = -1, rear = -1;

void enqueue();
void dequeue();
void display();

int main(){
    enqueue();
    enqueue();
    dequeue();
}

void enqueue(){
    if (rear == SIZE - 1) { // SIZE - 1 means last of the queue
        cout << "Queue Overflow!" << endl;
        return;
    }

    int value;
    cout << "Enter Value: ";
    cin >> value;

    if (front == -1) front = 0;
    queue[++rear] = value;
    display();
}

void dequeue(){
    if (front == -1 || front > rear) {
        cout << "Queue is Empty! Cannot dequeue." << endl;
        return;
    }
    front++; // increase the front so that it skip the current and increase its position
    display();
}

void display(){
    if (front == -1 || front > rear) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    cout << "Queue Data: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}