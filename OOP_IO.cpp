/* // custom INSERTER <<

#include <iostream>
using namespace std;
class myclass{
    private:
        int x, y;
    public:
        myclass(int x, int y){
            this->x=x;
            this->y=y;
        }
        //friend ostream &operator<<(ostream &out, myclass ob) = declare the function to overload << operator
        friend ostream &operator<<(ostream &out, myclass ob){ 
            out<<"x: "<<ob.x<<", y: "<<ob.y<<endl;
            return out;
        }
        // friend: This keyword allows the function to access the private members of the class.
        // ostream &operator<<(ostream &out, const myclass &ob): This declares the function signature for overloading the 
        // << operator. It takes an ostream reference and a constant reference to a myclass object.
};

// ostream &operator<<(ostream &out, myclass ob){ 
//     out<<"x: "<<ob.x<<", y: "<<ob.y<<endl;
//     return out;
// } we can also define the function in here outside the class

int main(){
    myclass ob(120, 140);
    operator<<(cout, ob); // function call
    // ostream &out - represent count
    // myclass ob   - represent ob
    // or we can write 
    cout<<ob;
    return 0;
} */




/*// custom EXTRACTOR
#include <iostream>
using namespace std;

class myclass {
private:
    int x, y;
public:
    myclass(int x, int y) {
        this->x = x;
        this->y = y;
    }

    friend istream &operator>>(istream &in, myclass &ob) {
        int tempX, tempY;
        cout << "Enter x: ";
        in >> tempX;
        cout << "Enter y: ";
        in >> tempY;
        cout << "You entered x: " << tempX << " and y: " << tempY << endl;
        return in;
    }
    // if we use following function then it will update the ob.x & ob.y value with the provided value in object creation ob(120, 140)
    // friend istream &operator>>(istream &in, myclass &ob) {
    //     cout << "Enter x: ";
    //     in >> ob.x;
    //     cout << "Enter y: ";
    //     in >> ob.y;
    //     cout << "You entered x: " << ob.x << " and y: " << ob.y << endl;
    //     return in;
    // }

    friend ostream &operator<<(ostream &out, const myclass &ob) {
        out << "Stored values: x = " << ob.x << ", y = " << ob.y;
        return out;
    }
};

int main() {
    myclass ob(120, 140);
    cin >> ob;
    cout << ob << endl;
    return 0;
}*/





/*void ifstream:: open(const char*filename, openmode = ios::in)  // read mode from file
void ofstream:: open(const char*filename, openmode = ios::out | ios::trunc) // write mode to file
void fstream:: open(const char*filename, openmode = ios::in | ios::out) // read or write from or to file*/

/*ifstream(const char*filename, openmode = ios::in)  // directly assign the value to the constructor
ofstream(const char*filename, openmode = ios::out | ios::trunc) // directly assign the value to the constructor
fstream(const char*filename, openmode = ios::in | ios::out) // directly assign the value to the constructor*/


// ofstream

/* #include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream myfile;
    myfile.open("myfile.txt");
    myfile<<"my name is saif";
    myfile.close();
    return 0;
} */

// ifstream

/* #include<iostream>
#include<fstream>
using namespace std;

int main(){
    char ch;
    ifstream myfile("myfile.txt");
    if(myfile.is_open()){
        // while(!myfile.eof()){
        //     myfile>>ch;
        //     cout<<ch;
        // }
        // the above while loop do not read the space from file data
        while(myfile.get(ch)){ // myfile.get(ch) is used to read each character from the file, including spaces and newlines.
            cout<<ch;
        }
        myfile.close();
    }
    else
    cout<<"Unable to open file";
    return 0;
} */


/* // Binary write &put(char ch)

#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(){
    char string[15] = "I am Saif";
    ofstream write("myfile.txt", ios::out|ios::binary);
    if(!write.is_open()){
        cout<<"File does not exist"<<endl;
        exit(1);
    }
    for(int i = 0; string[i] != '\0'; i++){
        write.put(string[i]);
    }
    write.close();
    return 0;
} */


/* // Binary read &get(char ch)

#include<iostream>
#include<fstream>
using namespace std;

int main(){
    char ch;
    ifstream read("myfile.txt", ios::in|ios::binary);
    if(!read.is_open()){
        cout<<"File does not exist"<<endl;
        exit(1);
    }
    while(!read.eof()){
        read.get(ch); // get() function get only one character at a time
        cout<<ch;
    }
    read.close();
    return 0;
} */

// unformated binary - write to file and copy from one to another

#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <cstring>
using namespace std;
int main(){
    char str1[100]="I love Bangladesh", str2[100];
    fstream mystring("myfile.txt", ios::out|ios::in|ios::binary);
    if(!mystring.is_open()){
        cout<<"Cannot open file"<<endl; 
        exit(1);
    }
    mystring.write(str1, strlen(str1)+1); // +1 to include the null character
    mystring.seekg(0, ios::beg); // seekg is used with ifstream or fstream to move the input (get) pointer to a specific location within a file.
    mystring.read(str2, strlen(str1)+1);
    // or in one line mystring.seekg(0, ios::beg).read(str2, strlen(str1)+1);
    cout<<str2<<endl;
    int file_size = mystring.tellg(); // tellg() get the current position of the pointer (which is the size of the file)
    cout<<file_size<<endl;
    mystring.close();
    return 0;
}