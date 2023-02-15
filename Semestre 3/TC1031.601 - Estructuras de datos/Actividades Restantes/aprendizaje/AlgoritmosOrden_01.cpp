// Marco T
// Profesor: Baldomero Olvera Villanueva
// Clase: TC1031.601
// Fecha: 25 de Agosto 2022

#include <iostream>
#include <cstdlib>


using namespace std;

// Ordenamiento - Selection Sort  -  O(n^2)
void selectionSort(int datos[], int tam) {
    int menor, paso;
    for (int i = 0; i < tam-2; i++) {
        menor = i;
        for (int j = i + 1; tam -1; j++) {
            if (datos[j] < datos[menor]) {
                menor = j;
            }
        }
        //Hacer el intercambio (swap)
        paso = datos[i];
        datos[i] = datos[menor];
        datos[menor] = paso;
    }

}

// Ordenamiento - Bubble Sort con bandera -  O(n^2)
void bubbleSort(int datos[], int tam) { 
    bool bandera;
    for (int i = 0; i < tam-1; i++) {
        bandera = false;
        for (int j = 0; j < tam-1; j++) {
            if (datos[j] > datos[j+1]) {
                bandera = true;
                int aux = datos[j];
                datos[j] = datos[j+1];
                datos[j+1] = aux;
            }
        }
        if (!bandera) {
            cout << i << endl;
            break;
        }
    }
}

// Ordenamiento - Bubble Sort sin bandera -  O(n^2)
void bubbleSort2(int datos[], int tam) { 
    for (int i = 0; i < tam-1; i++) {
        for (int j = 0; j < tam-1; j++) {
            if (datos[j] > datos[j+1]) {
                int aux = datos[j];
                datos[j] = datos[j+1];
                datos[j+1] = aux;
            }
        }
    }
}

// Ordenamiento - Insertion Sort -  O(n^2)
