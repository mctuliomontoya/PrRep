#include "clase_ADT_array.h"

#include <algorithm>
#include <chrono>

using namespace std::chrono;


void menu(Array &myArray) {
    int key, index;


    int opcion;
    myArray.read("input.txt");

    cout << "Selecciona la opcion a utilizar:" << endl;
    cout <<" [ 1 ] - Selection sort" << endl;
    cout <<" [ 2 ] - Bubble sort" << endl;
    cout <<" [ 3 ] - Merge sort" << endl;
    cout << " [ 4 ] - Sequencial search" << endl;
    cout << " [ 5 ] - Binary search" << endl;

    cin >> opcion;
    cout << "El array es: ";
    myArray.print();

    switch (opcion) {
        case 1:
            myArray.selectionSort();
            cout << "El array ordenado es: ";
            myArray.print();
            break;
        case 2:
            myArray.bubbleSort();
            cout << "El array ordenado es: ";
            myArray.print();
            break;
        case 3:
            myArray.mergeSort(0, myArray.getSize() - 1);
            cout << "El array ordenado es: ";
            myArray.print();
            break;
        case 4:
            cout << "Ingresa el numero a buscar: ";
            cin >> key;
            index = myArray.sequentialSearch(key);
            cout << "El numero a buscar esta en el index " << index <<endl;
            
            break;
        case 5:
			cout << "Ingresa el numero a buscar: ";
            cin >> key;
            index = myArray.binarySearch(key);
            cout << "El numero a buscar esta en el index " << index <<endl;
            break;
        default:
            break;
    }
}

int main() {

    int data;
    Array myArray;
    menu(myArray);
    return 0;
}
