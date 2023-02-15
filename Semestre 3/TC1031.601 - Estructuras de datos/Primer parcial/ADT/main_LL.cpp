#include "ADT_LinkedList.h"

using namespace std;


int main() {
	NodoLista *mem, *mem2, *mem3, *mem4;
	LinkedList *lista = new LinkedList();

	for (int i = 1; i <= 10 ; i++) {
		lista -> insertarFinal(i);
	}

	cout << "---TEST CASE 1---\n\n";
    cout << "Lista inicial: ";
    lista -> print();

    mem = lista->buscar(3);
    cout << "El numero a buscar tiene la memoria " << mem << " y el valor " << mem->info << endl;

    cout << "Lista con nuevo elemento: ";
    lista ->insertarFinal(11);
    lista -> print();

    cout << "Se cambia 11 por 123: ";
    lista->update(123,11);
    lista->print();

    cout << "Se borra el 123: ";
    lista->eliminar(123);
    lista->print();
    cout << "\n-------------------\n";

 	LinkedList *lista2 = new LinkedList();

    cout << "---TEST CASE 2---\n\n";
    cout << "Lista inicial: ";
    lista2 -> print();

    mem = lista->buscar(3);
    cout << "El numero a buscar tiene la memoria " << mem2 << " y el valor " << mem2->info << endl;

    cout << "Lista con nuevo elemento: ";
    lista2 ->insertarFinal(11);
    lista2 -> print();

    cout << "Se cambia 11 por 123: ";
    lista2->update(123,11);
    lista2->print();

    cout << "Se borra el 123: ";
    lista2->eliminar(123);
    lista2->print();
    cout << "\n-------------------\n";

    LinkedList *lista3 = new LinkedList();
   	for (int i = 10; i >= 1 ; i--) {
		lista3 -> insertarFinal(i);
	}
 	mem = lista->buscar(3);

    cout << "---TEST CASE 3---\n\n";
    cout << "Lista inicial: ";
    lista3 -> print();

    mem3 = lista3->buscar(3);
    cout << "El numero a buscar tiene la memoria " << mem3 << " y el valor " << mem3->info << endl;

    cout << "Lista con nuevo elemento: ";
    lista3 ->insertarInicio(11);
    lista3 -> print();

    cout << "Se cambia 11 por 123: ";
    lista3->update(123,11);
    lista3->print();

    cout << "Se borra el 123: ";
    lista3->eliminar(123);
    lista3->print();
    cout << "\n-------------------\n";


    LinkedList *lista4 = new LinkedList();
   	for (int i = 110; i <= 123 ; i++) {
		lista4 -> insertarFinal(i);
	}

    cout << "---TEST CASE 4---\n\n";
    cout << "Lista inicial: ";
    lista4 -> print();

    mem4 = lista4->buscar(115);
    cout << "El numero a buscar tiene la memoria " << mem4 << " y el valor " << mem4->info << endl;

    cout << "Lista con nuevo elemento: ";
    lista4 ->insertarInicio(109);
    lista4 -> print();

    cout << "Se cambia 109 por 88: ";
    lista4->update(88,109);
    lista4->print();

    cout << "Se borra el 115: ";
    lista4->eliminar(115);
    lista4->print();
    cout << "\n-------------------\n";

	return 0;
}