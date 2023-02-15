#include <iostream>
#include <string.h>
#include <map>

using namespace std;

class NodoLista{ // Nodo de la lista
	public:
		NodoLista *next;
        string fecha;
        string hora;
        string puntoEntrada;
        string UBI;
        
		NodoLista(string var_fecha, string var_hora, string var_puntoEntrada, string var_UBI){
			fecha = var_fecha;
            hora = var_hora;
            puntoEntrada = var_puntoEntrada;
            UBI = var_UBI;
			next = nullptr;
		}
};

NodoLista* SortedMerge(NodoLista* a, NodoLista* b){
    NodoLista* result = NULL;
 
    /* Casos base */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Comparar fechas */
    if (a->UBI <= b->UBI) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
 
void FrontBackSplit(NodoLista* source, NodoLista** frontRef, NodoLista** backRef){
    NodoLista* fast;
    NodoLista* slow;
    slow = source;
    fast = source->next;
 
    /* Avanzar 'fast' dos nodos, y avanzar 'slow' un nodo */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    /*  'slow' es antes del punto medio en la lista, asi que dividir en dos listas */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void MergeSort(NodoLista** headRef){
    NodoLista* head = *headRef;
    NodoLista* a;
    NodoLista* b;
 
    /* Caso base -- tamano 0 o 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
 
    /* Dividir en 'a' y 'b' sub-listas */
    FrontBackSplit(head, &a, &b);
 
    /* Ordenar las sub-listas */
    MergeSort(&a);
    MergeSort(&b);
 
    /* Unir las listas ordenadas */
    *headRef = SortedMerge(a, b);
}

/* Clase de lista enlazada*/
class LinkedList{ 
	private:
		NodoLista *primero;
        NodoLista *final;
	public:
		void Lista() {
			primero = nullptr;
            final = nullptr;
		}

        NodoLista *search(NodoLista dato){
            NodoLista *actual; // Apuntador a nodo actual
			actual = primero;
            while(actual != nullptr){
                if((actual->fecha == dato.fecha) && (actual->hora == dato.hora) && (actual->puntoEntrada == dato.puntoEntrada) && (actual->UBI == dato.UBI)){
                    return actual;
                } else {
                    actual = actual->next;
                }
            }
            return nullptr;
        }
        /* Inserta un elemento al inicio de la lista */
		void insertarInicio(string var_fecha, string var_hora, string var_puntoEntrada, string var_UBI){ 
			NodoLista *nuevoNodo = new NodoLista(var_fecha, var_hora, var_puntoEntrada, var_UBI);
			nuevoNodo -> next = primero;
			primero = nuevoNodo;
		}
        /* Inserta un elemento al final de la lista */
        void insertarFinal(string var_fecha, string var_hora, string var_puntoEntrada, string var_UBI){ 
			NodoLista *nuevoNodo = new NodoLista(var_fecha, var_hora, var_puntoEntrada, var_UBI);
			if(final == nullptr){
                primero = nuevoNodo;
                final = nuevoNodo;
            } else {
                final->next = nuevoNodo;
                final = nuevoNodo;
            }
		}
        /* Inserta un elemento en la lista ordenado por UBI */
		void print(){
			NodoLista *actual;
			actual = primero;
            int linea = 1;
			while(actual != nullptr){
				cout << linea <<  " - Fecha:" << actual->fecha  << " Hora:" << actual->hora << " Punto:" << actual->puntoEntrada << " UBI:" << actual->UBI<< endl;
				actual = actual->next;
                linea += 1;
			}
			cout << endl;
		}
    
        /* Ordena la lista por UBI */
        void mergeSort(){
            MergeSort(&primero);
        }

        /*Busca los registros con 3 digitos de una*/
        void searchUBI(string var_UBI){
			NodoLista *actual;
			actual = primero;
			int linea = 1;
			while(actual != nullptr){
				if(actual->UBI.substr(0,3) == var_UBI){
					cout << linea <<  " - Fecha:" << actual->fecha  << " Hora:" << actual->hora << " Punto:" << actual->puntoEntrada << " UBI:" << actual->UBI<< endl;
					linea += 1;
				}
				actual = actual->next;
			}
			cout << endl;
		}
        /* Cuenta los registros por mes*/
        void contadorMesesUBI(string var_UBI, int counter[]){
			map<string, int> mesPosicion;
            mesPosicion["01"] = 0;
            mesPosicion["02"] = 1;
            mesPosicion["03"] = 2;
            mesPosicion["04"] = 3;
            mesPosicion["05"] = 4;
            mesPosicion["06"] = 5;
            mesPosicion["07"] = 6;
            mesPosicion["08"] = 7;
            mesPosicion["09"] = 8;
            mesPosicion["10"] = 9;
            mesPosicion["11"] = 10;
            mesPosicion["12"] = 11;
            
            NodoLista *actual;
			actual = primero;
			while(actual != nullptr){
				if(actual->UBI.substr(0,3) == var_UBI){
                    int posicionArreglo = mesPosicion[actual->fecha.substr(3,2)]; // Substring de la fecha que indica el mes
					counter[posicionArreglo]++; // Añadimos uno al contador de ese mes
				}
				actual = actual->next;
			}
		}

}; // Fin de la clase Lista