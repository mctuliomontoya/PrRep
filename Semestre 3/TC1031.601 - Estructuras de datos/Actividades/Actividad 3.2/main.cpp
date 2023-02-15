#include "ADT_PriorityQueue.h"

using namespace std;

int main() {
    PriorityQueue *cola = new PriorityQueue();
    string arch;
    int opcion, dato;

    cout << "Ingrese el nombre del archivo: ";
    cin >> arch;
    cola->read(arch);
    system("cls");

    do{
        cout << "Priority Queue: ";
        cola->print();

        cout << "\n1. Insertar elemento" << endl;
        cout << "2. Eliminar elemento" << endl;
        cout << "3. Mostrar frente" << endl;
        cout << "4. Mostrar si la fila esta vacia" << endl;
        cout << "5. Mostrar tamano de la fila" << endl;
        cout << "6. Salir" << endl;
        cin >> opcion;
        system("cls");

        switch (opcion) {
            case 1:
                cout << "Ingrese un numero: ";
                cin >> dato;
                cout << "La cola era: "<<endl;
                cola->print();
                cola->push(dato);
                cout << "\nLa cola es: "<< endl;
                cola->print();
                system("pause");
                system("cls");
                break;
            case 2:
                cout << "La cola era: "<<endl;
                cola->print();
                cout << "El elemento eliminado es: " << cola->pop() << endl;
                cout << "\nLa cola es: "<< endl;
                cola->print();
                system("pause");
                system("cls");
                break;
            case 3:
                cout << "La cola es: "<<endl;
                cola->print();
                cout << "El elemento del frente es: " << cola->front() << endl;
                system("pause");
                system("cls");
                break;
            case 4:
                if (cola->isEmpty()) {
                    cout << "La fila esta vacia" << endl;
                }
                else {
                    cout << "La fila no esta vacia" << endl;
                }
                system("pause");
                system("cls");
                break;
            case 5:
                cout << "La cola es: "<<endl;
                cola->print();
                cout << "El tamano de la fila es: " << cola->size() << endl;
                system("pause");
                system("cls");
                break;
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                system("pause");
                system("cls");
                break;
        }
    } while (opcion != 6);

    return 0;
}