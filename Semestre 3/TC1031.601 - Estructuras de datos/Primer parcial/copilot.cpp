#include <iostream>

using namespace std;

unsigned long Fibonacci(int n){
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The Fibonacci of " << n << " is " << Fibonacci(n) << endl;
    return 0;
}
