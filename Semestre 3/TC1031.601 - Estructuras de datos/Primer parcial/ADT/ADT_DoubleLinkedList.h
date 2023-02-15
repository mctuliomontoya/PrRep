#include <iostream>

using namespace std;


class NodoListaDoble { // Nodo de la lista doble
	public:
		int info;
		NodoListaDoble *next;
		NodoListaDoble *prev;

		NodoListaDoble(int dato){
			info = dato;
			next = nullptr;
			prev = nullptr;
		}
};
class DoubleLinkedList { // Lista doblemente enlazada
	private:
		NodoListaDoble *primero;
		NodoListaDoble *ultimo;
	public:
		void ListaDoble() {
			primero = nullptr;
			ultimo = nullptr;
		}

		NodoListaDoble *buscar(int dato){ // Busca un elemento en la lista
			NodoListaDoble *actual; // Apuntador a nodo
			actual = primero;
			while(actual != nullptr){
				if(actual->info == dato)
					return actual;
				else
					actual = actual->next;
			}
			return nullptr;
		}
		void insertarInicio(int dato){ // Inserta un elemento al inicio de la lista
			NodoListaDoble *nuevoNodo = new NodoListaDoble(dato);
			nuevoNodo -> next = primero;
			nuevoNodo -> prev = nullptr;
			if (primero != nullptr)
				primero -> prev = nuevoNodo;
			primero = nuevoNodo;
			if (ultimo == nullptr)
				ultimo = primero;
		}

		void insertarFinal(int dato) { // Inserta un elemento al final de la lista
			NodoListaDoble *nuevoNodo = new NodoListaDoble(dato);
			nuevoNodo -> next = nullptr;
			nuevoNodo -> prev = ultimo;
			if (ultimo != nullptr)
				ultimo -> next = nuevoNodo;
			ultimo = nuevoNodo;
			if (primero == nullptr)
				primero = ultimo;
		} 

		void insertarDespues(int dato, int k){ // Inserta un elemento despues de un elemento k
			NodoListaDoble *nuevoNodo = new NodoListaDoble(dato);
			NodoListaDoble *actual;
			actual = primero;
			while (actual ->info !=k)
				actual = actual -> next;
			nuevoNodo -> next = actual -> next;
			nuevoNodo -> prev = actual;
			if (actual -> next != nullptr)
				actual -> next -> prev = nuevoNodo;
			actual -> next = nuevoNodo;
		}

		void insertarAntes(int dato, int k){ // Inserta un elemento antes de un elemento k
			NodoListaDoble *nuevoNodo = new NodoListaDoble(dato);
			NodoListaDoble *actual;
			actual = primero;
			while (actual ->info !=k)
				actual = actual -> next;
			nuevoNodo -> next = actual;
			nuevoNodo -> prev = actual -> prev;
			if (actual -> prev != nullptr)
				actual -> prev -> next = nuevoNodo;
			actual -> prev = nuevoNodo;
		}
		bool eliminarFinal(){ // Elimina el ultimo elemento de la lista
			NodoListaDoble *actual, *penultimo;
			actual = primero;
			if(primero == nullptr)
				return false;
			while(actual ->next != nullptr)
				actual = actual->next;
			penultimo = actual->prev;
			penultimo->next = nullptr;
			delete(actual);
			return false;
		}
		void borrar(){ // Elimina todos los elementos de la lista
			NodoListaDoble *siguiente;
			while(primero != nullptr){
				siguiente = primero->next;
				delete(primero);
				primero = siguiente;
			}
		}

		void read (){ // Imprime los elementos de la lista
			NodoListaDoble *actual;
			actual = primero;
			while(actual != nullptr){
				cout << actual->info << " ";
				actual = actual->next;
			}
			cout << endl;
		}
}; // Fin de la clase ListaDoble