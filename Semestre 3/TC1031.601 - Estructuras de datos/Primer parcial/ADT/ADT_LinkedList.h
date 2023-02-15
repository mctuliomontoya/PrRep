// Code made by: Marco Tulio Montoya - A01254155

#include <iostream>
#include <fstream>

using namespace std;

class NodoLista { // Nodo della lista
	public:
		int info;
		NodoLista *next;

		NodoLista(int dato){
			info = dato;
			next = nullptr;
		}
};

class LinkedList{ // Lista enlazada
	private:
		NodoLista *primero;
	public:
		void Lista() {
			primero = nullptr;
		}

		NodoLista *buscar(int dato){ // Busca un elemento en la lista
			NodoLista *actual; // Apuntador a nodo
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
			NodoLista *nuevoNodo = new NodoLista(dato);
			nuevoNodo -> next = primero;
				primero = nuevoNodo;
		}

		void read(string arch) {
			int n, num;
			ifstream myFile(arch);
			if(myFile.is_open()) {
				myFile >> n;
				for(int i = 0; i < n; i++) {
					myFile >> num;
					insertarFinal(num);
				}
			}
			else {
				cout << "No se pudo abrir el archivo" << endl;
			}
		}

		void insertarFinal(int dato) { // Inserta un elemento al final de la lista
			NodoLista *nuevoNodo = new NodoLista(dato);
			NodoLista *actual;
			actual = primero;
			if (primero == nullptr)
				primero = nuevoNodo;
			else {
				while(actual -> next != nullptr)
					actual = actual ->next;
			actual ->next = nuevoNodo;
			}
		}
		
		
		void insertarDespues(int dato, int k){ // Inserta un elemento despues de un elemento k
			NodoLista *nuevoNodo = new NodoLista(dato);
			NodoLista *actual;
			actual = primero;
			while (actual ->info !=k)
				actual = actual -> next;
			nuevoNodo->next = actual ->next;
			actual ->next = nuevoNodo;
		}

		bool eliminar (int dato){ // Elimina un elemento de la lista
			NodoLista *actual, *elimina;
			actual = primero;
			if (actual == nullptr)
				return false;
			if (actual->info == dato){
				primero = actual -> next;
				delete(actual);
				return true;
			}
			while((actual->next != nullptr)&& (actual->next) ->info != dato)
				actual = actual->next;
			if(actual->next == nullptr)
				return false;
			elimina = actual -> next;
			actual->next = elimina ->next;
			delete(elimina);
			return true;
		}

		bool eliminaInicio(){ // Elimina el primer elemento de la lista
			NodoLista*elimina;
			if(primero == nullptr)
				return false;
			else{
				elimina = primero;
				primero = primero->next;
				delete(elimina);
				return true;

			}
		}

		bool eliminaFinal(int dato){ // Elimina el ultimo elemento de la lista
			NodoLista *actual, *elimina;
			actual = primero;
			if (primero == nullptr)
				return false;
			if (actual ->next == nullptr){
				elimina = actual;
				primero = nullptr;

			}
			else{
				while((actual->next)->next != nullptr)
					actual = actual->next;
				elimina = actual->next;
				actual->next = nullptr;
			}
			delete(elimina);
			return true;
		}

		void borrar(){ // Borra la lista
			NodoLista *siguiente;
			while (primero != nullptr){
				siguiente = primero->next;
				delete(primero);
				primero = siguiente;
			}
		}

		void update(int dato, int k){ // Actualiza un elemento de la lista
			NodoLista *actual;
			actual = primero;
			while(actual->info != k)
				actual = actual->next;
			actual->info = dato;
		}

		void print(){ // Imprime la lista
			NodoLista *actual;
			actual = primero;
			while(actual != nullptr){
				cout << actual->info << " ";
				actual = actual->next;
			}
			cout << endl;
		}

		int getPrimero(){
			return primero->info;
		}

		bool listaVacia() { // Verifica si la lista esta vacia
			if (primero == nullptr)
				return true;
			else
				return false;
		}



}; // Fin de la clase Lista