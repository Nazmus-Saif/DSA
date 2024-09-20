/* #include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        if (top == nullptr) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is Empty" << endl;
        } else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void printStack() {
        if (top == nullptr) {
            cout << "Stack is Empty" << endl;
        } else {
            cout << "Stack Elements: ";
            Node* current = top;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Print Stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.printStack();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
} */



#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
node* head = NULL;

void push();
void pop();
void printstack();

int main(){
    push();
    push();
    push();
    pop();
}

void push(){
    int value;
    cout << "Enter value: ";
    cin >> value;

    node* newnode = new node;
    if (head == NULL){
        newnode -> data = value;
        newnode -> next = NULL;
        head = newnode;
    }else{
        newnode -> data = value;
        newnode -> next = head;
        head = newnode;
    }
    printstack();
}

void pop(){
    head = head-> next;
    printstack();
}

void printstack(){
    node* temp;
    temp = head;
    if(temp == NULL){
        cout << "Stack is Empty!";
    }
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}