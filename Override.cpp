#include<iostream>
using namespace std;

class a{
    public:
        void alo();
};

class b: public a{
    public:
        void alo(){
            cout<<"successfully override the base class";
        }
};