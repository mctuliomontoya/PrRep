#include "ArbolBusquedaBinaria.h"

int main(){
    BST arbol;
    arbol.readArch("data.txt");
    cout << "Listas en inOrden: ";
    arbol.print();
    cout << endl << "Comparaciones minimas totales: " << arbol.calcularComparaciones();
    int valor;
    return 0;
}