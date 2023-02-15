#include "tabla_hash.h"

using namespace std;

int main(){
    int arr[] = {14, 35, 56, 36};
    string val[] = {"M", "A", "O", "R", "EXCESS"};
    int N = sizeof(arr)/sizeof(arr[0]);
    Hash h(7);
    h.chaining(arr, N, val);
    return 0;
}