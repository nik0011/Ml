#include <iostream>
using namespace std;

int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonacciIterative(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, fib = 0;
    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter the number of Fibonacci numbers to calculate: ";
    cin >> n;
    
    cout << "Fibonacci (Recursive): " << fibonacciRecursive(n) << endl;
    cout << "Fibonacci (Iterative): " << fibonacciIterative(n) << endl;
    
    return 0;
}
