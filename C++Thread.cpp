/* #include <iostream>
#include <thread>
using namespace std;

void do_something_in_thread(int number) {
    for (int i = 0; i < 10; ++i) {
        cout << "Thread " << number << ": " << i << endl;
    }
}

int main() {
    thread thread1(do_something_in_thread, 1);
    thread1.join();  // Wait for thread1 to finish
    return 0;
} */


// #include <iostream>
// #include <thread>
// #include <mutex>
// using namespace std;

// void add(int a, int b, int& result) {
//     result = a + b;
// }

// void subtract(int a, int b, int& result) {
//     result = a - b;
// }

// int main() {
//     int a = 10, b = 5;
//     int sum_result = 0, subtract_result = 0;

//     // Create threads for addition and subtraction
//     thread add_thread(add, a, b, ref(sum_result));
//     thread subtract_thread(subtract, a, b, ref(subtract_result));

//     /* Reasons to Use .join()
//        Synchronization: join() ensures that the main thread waits until the worker thread completes its task. Without join(), 
//        the main thread might continue its execution and possibly terminate the program before the worker thread finishes, 
//        leading to incomplete or inconsistent results.

//        Resource Management: Each thread in a program consumes system resources. By calling join(), you ensure that the thread 
//        has finished execution and its resources can be reclaimed by the system. If a thread is not joined or detached, 
//        it may lead to resource leaks.

//        Consistency: Using join()  ensures that the results computed by the threads are available and consistent when accessed 
//        by the main thread or other parts of the program. It prevents scenarios where the main thread might access partially 
//        computed or uninitialized data.*/

//     // Wait for both threads to finish
//     add_thread.join(); // The main thread will pause its execution until ADD_THREAD has finished executing its assigned task.
//     // After thread1 (ADD_THREAD) has completed and the main thread resumes, it will then call SUBTRACT_THREAD.join().
//     subtract_thread.join(); // The main thread will pause its execution until SUBTRACT_THREAD has finished executing its assigned task.
//     // After completing execution SUBTRACT_THREAD the main thread will resume again
//     cout << "Sum: " << sum_result << endl;
//     cout << "Difference: " << subtract_result << endl;

//     // main thread means the MAIN () FUNCTION
//     // by writing the .join() we join the thread with the main() function or main thread

//     return 0;
// }



// #include<iostream>
// #include<chrono>
// #include<thread>
// using namespace std;

// void print(int n){
//     while(n --> 0){
//         cout<<n<<endl;
//     }
//     this_thread::sleep_for(chrono::seconds(5));
// }

// void show(string s){
//     cout<<s<<endl;
// }

// int main(){
//     thread t1(print,10);
//     thread t2(show, "Hello");
//     t1.join();
//     t2.join(); // t2 not wait for 5 second delay of t1 it show its task and after 5 sec main() text will be print
//     // if we join() again a thread then we have to check either its joinable() or not othwerwise its failed to compile
//     if(t1.joinable()){ // this is needed when we are going to create a complex problem
//         t1.join();
//     }

//     // if we use t1.detach() then main () will maybe sometimes not wait for the thread
//     // we use a sleep in thread 1 if we use t1.detach() then sleep will not work
//     // detaching thread means we dont want to wait for the thread
//     cout<<"main()";
//     return 0;
// }


// Mutex - suppose there is one variable and more than 1 thread and each thread want to modify the same value which is called race
// situation in this case mutex is used to avoide this

/* #include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex mtx;
int n = 5;

void increment_shared_data() {
    // mtx.lock();
    n++;
    // mtx.unlock();
}

int main() {
    thread t1(increment_shared_data);
    thread t2(increment_shared_data);

    t1.join();
    t2.join();

    cout << "Final value of shared_data: " << n << endl;

    return 0;
} */


/* #include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int n = 5;

void increment_shared_data() {
    // std::lock_guard<std::mutex> lock(mtx); // Automatically locks and unlocks the mutex
    n++;
}

int main() {
    std::thread t1(increment_shared_data);
    std::thread t2(increment_shared_data);

    t1.join();
    t2.join();

    std::cout << "Final value of shared_data: " << n << std::endl;

    return 0;
} */

// in this case the output should be with mutex 7 without mutext may be 7 or 6

/* #include<iostream>
#include<thread>
using namespace std;

auto function = [](int n){ // lambda functions
    cout<<n<<endl;
};

int main(){
    thread th1(function, 10);
    th1.join();
    return 0;
} */


#include <iostream>
#include <thread>
using namespace std;

class A{
public:
    void operator()(int a, int b){
        cout << "Sum is: " << a+b << endl;
    }
};

int main(){
    thread th1(A(), 5, 5); // callable class object
    th1.join();
    return 0;
}