#include <iostream>
using namespace std;

int Fib(int n) {
    if (n == 0 || n == 1)
        return n;
    else
        return (Fib(n - 1) + Fib(n - 2));
}

int main() {
    int n, i, sum = 0;
    cout << "Enter Number : ";
    cin >> n;
    
    cout << "\nFibonacci Series : ";
    for (i = 0; i <= n; i++) {
        cout << Fib(i) << " ";
        sum = Fib(i) + sum;
    }
    
    cout << "\n\n" << n << "th Position Value is : " << Fib(n);
    cout << "\n\nSum of Fibonacci Series : " << sum << endl;
    
    return 0;
}