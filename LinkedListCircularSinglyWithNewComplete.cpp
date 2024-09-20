#include <iostream>

using namespace std;

struct Node
{
    Node* Next;
    int Data;
};

Node* Head = nullptr;
Node* Temp = nullptr;

void Insert_In_Head();
void Insert_In_End();
void Insert_In_Any_Position();
void Delete_In_Head();
void Delete_In_Any_Position();
void Delete_In_Tail();
void Search_Element();
void Display();

int main(){
    int NodeNumber, i;
    cout << "Enter The Node Number : ";
    cin >> NodeNumber;

    for (i = 0; i < NodeNumber; i++){
        Node* NewNode = new Node();
        NewNode->Next = nullptr;
        cout << "\nEnter Data For Node " << i << " : ";
        cin >> NewNode->Data;

        if (i == 0){
            Head = NewNode;
            Temp = Head;
        }else{
            Temp->Next = NewNode;
            Temp = NewNode;
        }
    }
    Temp->Next = Head; // Making it circular
    Display();

    while (true){
        int Choice;
        cout << "\nEnter Choice : ";
        cin >> Choice;

        switch (Choice){
        case 1:
            Insert_In_Head();
            break;
        case 2:
            Insert_In_End();
            break;
        case 3:
            Insert_In_Any_Position();
            break;
        case 4:
            Delete_In_Head();
            break;
        case 5:
            Delete_In_Tail();
            break;
        case 6:
            Delete_In_Any_Position();
            break;
        case 7:
            Search_Element();
            break;
        case 8:
            return 0;
        default:
            cout << "Enter Choice Between 1 to 8";
        }
    }
}

void Insert_In_Head(){
    Node* NewNode = new Node();
    cout << "Enter Data : ";
    cin >> NewNode->Data;

    if (Head == nullptr){
        Head = NewNode;
        Head->Next = Head; // Making it circular
    }else{
        Temp = Head;
        while (Temp->Next != Head) { // Making it circular
            Temp = Temp->Next;
        }
        Temp->Next = NewNode; // Making it circular
        NewNode->Next = Head;
        Head = NewNode;
    }

    Display();
}

void Insert_In_End(){
    Node* NewNode = new Node();
    cout << "\nEnter Data : ";
    cin >> NewNode->Data;

    if (Head == nullptr){
        Head = NewNode;
        Head->Next = Head; // Making it circular
    }else{
        Temp = Head;
        while (Temp->Next != Head){ // Making it circular
            Temp = Temp->Next;
        }
        Temp->Next = NewNode;
        NewNode->Next = Head; // Making it circular
    }

    Display();
}

void Insert_In_Any_Position(){
    int Position, i = 0;
    Temp = Head;

    cout << "\nEnter Position : ";
    cin >> Position;

    if (Position >= 0){
        while (i < Position - 1 && Temp->Next != Head){ // Making it circular
            Temp = Temp->Next;
            i++;
        }

        if (Position == 0){
            Insert_In_Head();
            return;
        }else if (Temp->Next != Head || Position == i + 1){ // Making it circular
            Node* NewNode = new Node();
            cout << "\nEnter Data : ";
            cin >> NewNode->Data;
            NewNode->Next = Temp->Next;
            Temp->Next = NewNode;
        }else{
            cout << "\n\n The Position You Entered is Invalid Because There Are Less Than " << Position << " Elements\n";
        }
    }else{
        cout << "\nNegative Value Is Not Possible";
    }
    Display();
}

void Display(){
    if (Head == nullptr) {
        cout << "\nList is empty\n";
        return;
    }
    Temp = Head;
    cout << "\nOur Circular Linked list : \n\n";
    cout << "Current\t\t\tData\tNext\n";
    while (Temp != Head){ // Making it circular
        cout << Temp << "\t\t" << Temp->Data << "\t" << Temp->Next << endl;
        Temp = Temp->Next;
    }
}

void Delete_In_Head(){
    if (Head == nullptr){
        cout << "\nList is empty\n";
        return;
    }
    if (Head->Next == Head){
        delete Head;
        Head = nullptr;
    }else{
        Temp = Head;
        while (Temp->Next != Head){ // Making it circular
            Temp = Temp->Next;
        }
        Node* ToDelete = Head;
        Head = Head->Next;
        Temp->Next = Head; // Making it circular
        delete ToDelete;
    }
    Display();
}

void Delete_In_Any_Position(){
    int Position, i = 0;
    if (Head == nullptr){
        cout << "\nList is empty\n";
        return;
    }
    cout << "\nEnter Position : ";
    cin >> Position;

    if (Position >= 0){
        if (Position == 0){
            Delete_In_Head();
            return;
        }else{
            Temp = Head;
            while (i < Position - 1 && Temp->Next != Head){ // Making it circular
                Temp = Temp->Next;
                i++;
            }

            if (Temp->Next != Head){ // Making it circular
                Node* ToDelete = Temp->Next;
                Temp->Next = ToDelete->Next;
                delete ToDelete;
            }else{
                cout << "\n\n The Position You Entered is Invalid Because There Are Less Than " << Position << " Elements\n";
            }
        }
    }else{
        cout << "\nNegative Value Is Not Possible";
    }
    Display();
}

void Delete_In_Tail()
{
    if (Head == nullptr){
        cout << "\nList is empty\n";
        return;
    }
    if (Head->Next == Head){
        delete Head;
        Head = nullptr;
    }else{
        Temp = Head;
        while (Temp->Next->Next != Head){ // Making it circular
            Temp = Temp->Next;
        }
        delete Temp->Next;
        Temp->Next = Head; // Making it circular
    }
    Display();
}

void Search_Element(){
    int Value;
    bool found = false;
    cout << "Enter Value: ";
    cin >> Value;

    if (Head == nullptr){
        cout << "\nList is empty\n";
        return;
    }

    Temp = Head;
    do { // Making it circular
        if(Value == Temp->Data){
            cout << "Value " << Value << " found at location " << Temp << endl;
            found = true;
        }
        Temp = Temp->Next;
    } while (Temp != Head); // Making it circular

    if (!found) {
        cout << "Value " << Value << " not found in the list.\n";
    }
}