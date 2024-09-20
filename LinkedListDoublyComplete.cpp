#include <iostream>
using namespace std;

struct Node{
    Node* Prev;
    int Data;
    Node* Next;
};

Node* Head = NULL;
Node* Temp = NULL;

void Display();
void Search_Element();
void Insert_At_First();
void Insert_At_End();
void Insert_At_Any_Position();
void Delete_At_Any_Position();

int main(){
    int NodeNumber;

    cout << "Enter NodeNumber: ";
    cin >> NodeNumber;

    for (int i = 0; i < NodeNumber; i++){
        Node* NewNode = new Node();
        NewNode -> Prev = NULL;
        NewNode -> Next = NULL;

        int Data;

        cout << "Enter data for node " << i << ": ";
        cin >> NewNode -> Data;

        if (i == 0){
            Head = Temp = NewNode;
        }else{
            Temp -> Next = NewNode;
            NewNode -> Prev = Temp;
            Temp = NewNode;
        }
    }
    Display();
    // Search_Element();
    // Insert_At_First();
    // Insert_At_End();
    Insert_At_Any_Position();
    Delete_At_Any_Position();
}

void Display(){
    Temp = Head;

    cout << "Linked List: ";
    while(Temp != NULL){
        cout << Temp -> Data << " ";
        Temp = Temp -> Next;
    }
    cout << endl;
}

void Search_Element(){
    int Value;

    cout << "Enter Value: ";
    cin >> Value;

    Temp = Head;
    while (Temp -> Next != NULL){
        Temp = Temp -> Next;
        if(Value == Temp -> Data){
            cout << "Value " << Value << " found at location " << Temp << endl;
        }else
            continue; // in which cell it not found the value then it skip that cell
    } 
}

void Insert_At_First(){
    Node* NewNode = new Node();

    cout << "Enter Data: ";
    cin >> NewNode -> Data;

    if (Head == NULL){
        Head = NewNode;
        Head -> Next = NULL;
        NewNode -> Prev = NULL;
    }else{
        NewNode -> Prev = NULL;
        NewNode -> Next = Head;
        Head -> Prev = NewNode;
        Head = NewNode;
    }
    Display();
}

/* void Insert_At_Any_Position(){
    int Position, i = 0;

    cout << "Enter Position: ";
    cin >> Position;

    while (i < Position - 1 && Temp != NULL){
        Temp = Temp -> Next;
        i++;
    }
    if (Position == 0){
        Insert_At_First();
    }else{
        Node* NewNode = new Node();
        cout << "Enter Data: ";
        cin >> NewNode -> Data;
        NewNode -> Prev = Temp;
        NewNode -> Next = Temp -> Next;
        Temp -> Next = NewNode;
        NewNode -> Next -> Prev = NewNode;
    }
    Display();
} */

void Insert_At_Any_Position()
{
    int i, Position;
    Temp = Head;
    cout << "Enter Position: ";
    cin >> Position;
    if (Position >= 0){
        while(i < Position - 1 && Temp != NULL){
            Temp = Temp -> Next;
            i++;
        }
        if(Position == 0){
            Insert_At_First();
        }else if(Temp != NULL){
            Node *NewNode = new Node();
            cout << "Enter Data: ";
            cin >> NewNode -> Data;
            NewNode -> Prev = Temp;
            NewNode-> Next = Temp -> Next;
            Temp -> Next = NewNode;
            NewNode -> Next -> Prev = NewNode;
        }else{
            printf("\n\n The Position You Entered is Invalid Because There Are Less Than %d Elements\n", Position);
        }
    }else{
        printf("\n\n Negative Position is Not Allowed\n");
    }
    Display();
}

void Insert_At_End(){
    Node* NewNode = new Node();

    cout << "Enter Data: ";
    cin >> NewNode -> Data;

    Temp = Head;

    if (Temp == NULL){
        NewNode -> Next = NULL;
        NewNode -> Prev = NULL;
        Head = NewNode;
    }else{
        while(Temp -> Next != NULL){
            Temp = Temp -> Next;
        }
        Temp -> Next = NewNode;
        NewNode -> Prev = Temp;
        NewNode -> Next = NULL;
        Temp = NewNode;
    }
    Display();
}

void Delete_At_Any_Position(){
    int Position, i = 0;
    Temp = Head;

    cout << "\nEnter Position : ";
    cin >> Position;

    if (Position >= 0){
        while (i < Position - 1 && Temp != nullptr){
            Temp = Temp->Next;
            i++;
        }
        if (Temp -> Next != nullptr){
            Node* NodeDelete = Temp -> Next;
            NodeDelete -> Next -> Prev = Temp;
            Temp -> Next = NodeDelete -> Next;
            delete NodeDelete;
        }else{
            cout << "\n\n The Position You Entered is Invalid Because There Are Less Than " << Position << " Elements\n";
        }
    }
    Display();
}