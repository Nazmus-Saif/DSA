/* #include <iostream>
#include <thread>
#include <future>
using namespace std;

// Function to calculate factorial
unsigned long long factorial(unsigned int n) {
    unsigned long long fact = 1;
    for (unsigned int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {
    unsigned int num;
    cout << "Enter a number to find factorial: ";
    cin >> num;

    // Create a promise to store the result of the factorial calculation
    promise<unsigned long long> factorialPromise;
    future<unsigned long long> factorialFuture = factorialPromise.get_future();

    // Create a thread to calculate factorial
    thread factorialThread([&]() {
        unsigned long long result = factorial(num);
        factorialPromise.set_value(result);
    });

    // Join the thread to wait for its completion
    factorialThread.join();

    // Get the result from the future
    unsigned long long result = factorialFuture.get();
    cout << "Factorial of " << num << " is: " << result << std::endl;

    return 0;
} */


#include <iostream>
#include <thread>
using namespace std;

// Function to calculate factorial (non-void return type)
void factorial(unsigned int n, unsigned long long &fact) {
    for (unsigned int i = 1; i <= n; ++i) {
        fact *= i;
    }
}

int main() {
    unsigned int num = 5;
    unsigned long long fact = 1;
    // Creating a thread to calculate factorial
    thread factorialThread(factorial, num, ref(fact));
    
    // Joining the thread to wait for its completion
    factorialThread.join();
    
    cout << "Factorial of " << num << " is: " << fact << endl;
    
    return 0;
}




//        uses of promise and future //
/* Asynchronous system: In the second version of the code using std::promise and std::future, the factorial computation 
can happen concurrently in a separate thread. This allows the main program to continue running (perhaps accepting user 
input or performing other tasks) without waiting for the factorial computation to finish. Later, the program can use 
future.get() to retrieve the result once it's available, or it can continue with other tasks until the result is needed. */


//      without uses of promise and future //
// the code become synchronous system

// Asynchronous system means concurrently run items not dependent of others
// Synchronous system means one after means 2nd one is wait for after complete of 1st one