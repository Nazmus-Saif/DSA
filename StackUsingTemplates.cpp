#include <iostream>
using namespace std;

template <class t1> // class template
class Stack {
    private:
        t1 array[10];
        int top;
    public:
        Stack(){
            top = -1;
            for(int i = 0; i < 10; i++){
                array[i] = 0;
            }
        }
        void push(t1 data){
            if(top == 9){
                cout << "Stack is Full" << endl;
            }
            else{
                array[++top] = data;
            }
        }
        void pop(){
            if(top == -1){
                cout << "Stack is Empty" << endl;
                cout << top << endl;
            }
            else{
                top--;
            }
        }
        void printStack(){
            if(top == -1){
                cout << "Stack is Empty" << endl;
            }
            else{
                cout << "Stack Elements: ";
                for(int i = 0; i <= top; i++){
                    cout << array[i] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    // Stack<int> s, t;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // s.printStack();
    // s.pop();
    // s.printStack();

    // t.push(100);
    // t.push(200);
    // t.push(300);
    // t.push(400);
    // t.push(500);
    // t.printStack();
    // t.pop();
    // t.printStack();
    Stack<char> s, t;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');
    s.printStack();
    s.pop();
    s.printStack();

    t.push('a');
    t.push('b');
    t.push('c');
    t.push('d');
    t.push('e');
    t.printStack();
    t.pop();
    t.printStack();
    return 0;
}


// template <class t1> t1 add(t1 a, t1 b) // function template
// template <class t1> void add(t1 a, t1 b) // function template

// template <class t1, class t2, .....> return_type  function_name (paramater type parameter_name......)