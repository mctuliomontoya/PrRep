#ifndef clase_ADT_ordenamiento_h
#define clase_ADT_ordenamiento_h

#include "clase_ADT_array.h"

void bubbleSort(int datos[], int tam){
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

#endif