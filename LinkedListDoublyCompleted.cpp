#include <iostream>
using namespace std;

struct Node {
    Node* Prev;
    Node* Next;
    int Data;
};

Node *Head, *Tail, *Temp;

void Insert_In_Head();
void Insert_In_Any_Position();
void Insert_In_End();
void Delete_In_Head();
void Delete_In_Any_Position();
void Delete_In_End();
void Display();
void Reverse_Display();

int main() {
    int NodeNumber;
    cout << "How Many Nodes do You Want to Insert: ";
    cin >> NodeNumber;
    for (int i = 0; i < NodeNumber; i++) {
        Node* NewNode = new Node();
        NewNode->Prev = nullptr;
        cout << "\nEnter Data for Node " << i << ": ";
        cin >> NewNode->Data;
        NewNode->Next = nullptr;
        if (i == 0) {
            Head = Tail = NewNode;
        } else {
            Tail->Next = NewNode;
            NewNode->Prev = Tail;
            Tail = NewNode;
        }
    }

    Display();
    while (true) {
        int Process;
        cout << "\n\nEnter 1 for Starting Options & 2 for Exit: ";
        cin >> Process;
        if (Process == 1) {
            cout << "\n\n\nDo You Want to Insert More? Then:\n";
            cout << "\nChose 1 for Insert in Head\nChose 2 for Insert in Any Position\nChose 3 for Insert in End\n\n";
            cout << "\n\nDo You Want to Delete? Then:\n";
            cout << "\nChose 4 for Deletion in Head\nChose 5 for Deletion in Any Position\nChose 6 for Deletion in End\n";
            cout << "\n\n\nOthers Choice:\n";
            cout << "\n\nChose 7 for Reverse Display\nChose 8 for Exit\n\n";
            cout << "\n\nEnter Choice: ";
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    Insert_In_Head();
                    Display();
                    break;
                case 2:
                    Insert_In_Any_Position();
                    Display();
                    break;
                case 3:
                    Insert_In_End();
                    Display();
                    break;
                case 4:
                    Delete_In_Head();
                    Display();
                    break;
                case 5:
                    Delete_In_Any_Position();
                    Display();
                    break;
                case 6:
                    Delete_In_End();
                    Display();
                    break;
                case 7:
                    Reverse_Display();
                    break;
                case 8:
                    return 0;
                default:
                    cout << "\n\nPlease Enter a Valid Choice";
            }
        } else if (Process == 2) {
            return 0;
        } else {
            cout << "\n\nPlease Enter a Valid Choice\n";
        }
    }
}

void Insert_In_Head() {
    Node* NewNode = new Node();
    cout << "\nEnter Value: ";
    cin >> NewNode->Data;
    cout << "\n";
    if (Head == nullptr) {
        NewNode->Next = nullptr;
        NewNode->Prev = nullptr;
        Head = NewNode;
    } else {
        NewNode->Prev = nullptr;
        NewNode->Next = Head;
        Head->Prev = NewNode;
        Head = NewNode;
    }
}

void Insert_In_Any_Position() {
    int Position;
    Temp = Head;
    cout << "\nEnter The Position: ";
    cin >> Position;
    if (Position >= 0) {
        int i = 0;
        while (i < Position - 1 && Temp != nullptr) {
            Temp = Temp->Next;
            i++;
        }
        if (Position == 0) {
            Insert_In_Head();
        } else if (Temp == Tail) {
            Insert_In_End();
        } else if (Temp != nullptr) {
            Node* NewNode = new Node();
            cout << "\nEnter Value: ";
            cin >> NewNode->Data;
            NewNode->Prev = Temp;
            NewNode->Next = Temp->Next;
            Temp->Next = NewNode;
            NewNode->Next->Prev = NewNode;
        } else {
            cout << "\n\nThe Position You Entered is Invalid Because There Are Less Than " << Position << " Elements\n";
        }
    } else {
        cout << "\n\nNegative Position is Not Allowed\n";
    }
}

void Insert_In_End() {
    Node* NewNode = new Node();
    cout << "\nEnter Value: ";
    cin >> NewNode->Data;
    cout << "\n";
    Temp = Head;
    if (Temp == nullptr) {
        NewNode->Next = nullptr;
        NewNode->Prev = nullptr;
        Temp = NewNode;
    } else {
        while (Temp->Next != nullptr) {
            Temp = Temp->Next;
        }
        Temp->Next = NewNode;
        NewNode->Prev = Temp;
        NewNode->Next = nullptr;
    }
}

void Delete_In_Head() {
    if (Head->Next == nullptr) {
        Head = nullptr;
    } else {
        Temp = Head;
        Head = Head->Next;
        Head->Prev = nullptr;
    }
}

void Delete_In_Any_Position() {
    int Position;
    Temp = Head;
    cout << "\nEnter The Position: ";
    cin >> Position;
    if (Position >= 0) {
        int i = 0;
        while (i < Position && Temp != nullptr) {
            Temp = Temp->Next;
            i++;
        }
        if (Position == 0) {
            Delete_In_Head();
        } else if (Temp == Tail) {
            Delete_In_End();
        } else if (Temp != nullptr) {
            Temp->Prev->Next = Temp->Next;
            Temp->Next->Prev = Temp->Prev;
        } else {
            cout << "\n\nThe Position You Entered is Invalid Because There Are Less Than " << Position << " Elements\n";
        }
    } else {
        cout << "\n\nNegative Position is Not Allowed\n";
    }
}

void Delete_In_End() {
    if (Head == nullptr) {
        cout << "\n\nNo Data for Delete\n";
    } else if (Head->Next == nullptr) {
        Head = nullptr;
    } else {
        Temp = Head;
        while (Temp->Next != nullptr) {
            Temp = Temp->Next;
        }
        Temp->Prev->Next = nullptr;
    }
}

void Display() {
    cout << "\n\nOur Doubly Linked List Is:\n\nCurrent         Prev         Data       Next\n";
    Temp = Head;
    while (Temp != nullptr) {
        cout << "\n" << Temp << "\t\t" << Temp->Prev << "\t\t" << Temp->Data << "\t" << Temp->Next;
        Temp = Temp->Next;
    }
    cout << "\n\n";
}

void Reverse_Display() {
    cout << "\n\nOur Doubly Linked List Is:\n\nCurrent         Prev         Data       Next\n";
    while (Tail != nullptr) {
        cout << "\n" << Tail << "\t\t" << Tail->Next << "\t\t" << Tail->Data << "\t" << Tail->Prev;
        Tail = Tail->Prev;
    }
    cout << "\n\n";
}