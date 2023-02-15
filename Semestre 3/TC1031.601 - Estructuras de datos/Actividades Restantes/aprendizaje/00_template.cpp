#include <iostream>

using namespace std; 

template <typename T> // template <typename T> is the same as template <class T> in C++

T myMax (T x, T y) { // template function
    return (x > y) ? x : y; // return the max value
} // end of template function

int main() {
    cout << myMax<int>(5, 10) << endl; // call myMax with ints
    cout << myMax<double>(5.5, 10.5) << endl; // call myMax with doubles
    cout << myMax<char>('a', 'b') << endl; // call myMax with chars
}