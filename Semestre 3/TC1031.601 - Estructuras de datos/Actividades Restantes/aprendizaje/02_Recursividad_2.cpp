#include <iostream>

using namespace std;

unsigned long fibonacci(int n){
    if(n == 0 || n == 1)
        return 1;
    else
        return fibonacci (n - 1) + fibonacci ( n - 2);
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The fibonacci of " << n << " is " << fibonacci(n) << endl;
    return 0;
}