#include "clase_ADT_array.h"

#include <algorithm>
#include <chrono>

using namespace std::chrono;

void menu(Array &a) {
    int opcion;
    cout << "Selecciona el metodo de ordenamiento a utilizar:" << endl;
    cout << "1. Selection sort" << endl;
    cout << "2. Bubble sort" << endl;
    cout << "3. Bubble sort con bandera" << endl;
    cout << "4. Insertion sort" << endl;
    cout << "5. Merge sort" << endl;
    cout << "6. Quick sort" << endl;
    cout << "7. Salir" << endl;
    cin >> opcion;

    switch (opcion) {
        case 1:
            a.read("input.txt");
            cout << "El array es: ";
            a.print();
            a.selectionSort();
            cout << "El array ordenado es: ";
            a.print();
            break;
        case 2:
            a.read("input.txt");
            cout << "El array es: ";
            a.print();
            a.bubbleSort();
            cout << "El array ordenado es: ";
            a.print();
        case 3:
            a.read("input.txt");
            cout << "El array es: ";
            a.print();
            a.bubbleSortBandera();
            cout << "El array ordenado es: ";
            a.print();
        case 4:
            a.read("input.txt");
            cout << "El array es: ";
            a.print();
            a.insertionSort();
            cout << "El array ordenado es: ";
            a.print();
            break;
        case 5:
            a.read("input.txt");
            cout << "El array es: ";
            a.print();
            a.mergeSort(0, a.getSize() - 1);
            cout << "El array ordenado es: ";
            a.print();
            break;
        case 6:
            a.read("input.txt");
            cout << "El array es: ";
            a.print();
            a.quickSort(0, a.getSize() - 1);
            cout << "El array ordenado es: ";
            a.print();
        case 7:
            cout << "Salir" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
    }


}

int main(){
    Array a; // create an object of class Array
    int data; 
    menu(a);
}