#include "ADT_BST.h"

using namespace std;

int main() {
    BST *arbol = new BST();
    string arch;

    cout << "Ingresa el nombre del archivo: ";
    cin >> arch;
    int opcion, dato;
    arbol->read(arch);
    
    system("cls");
    do{
        cout << "1. Insertar elemento" << endl;
        cout << "2. Insertar varios elementos" << endl;
        cout << "3. Altura del arbol" << endl;
        cout << "4. Ancestros de un elemento" << endl;
        cout << "5. Nivel de un elemento" << endl;
        cout << "6. Recorridos" << endl;
        cout << "7. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        // system("cls");
        switch (opcion) {
            case 1:
                system("cls");
                cout << "Ingrese un numero: ";
                cin >> dato;
                arbol->insertar(dato);
                break;
            case 2:
                arbol->insertarElementos();
                system("pause");
                system("cls");
                break;
            case 3:
                cout << "La altura del arbol es: " << arbol->height() << endl;
                system("pause");
                system("cls");
                break;
            case 4:
                cout << "Ingrese el elemento: ";
                cin >> dato;
                cout << "Los ancestros son: ";
                arbol->ancestors(dato);
                cout << endl;
                break;
            case 5:
                cout << "Ingrese el elemento: ";
                cin >> dato;
                cout << "El nivel del elemento es: " << arbol->whatlevelamI(dato) << endl;
                break;
            case 6:
                cout << "1. Preorden" << endl;
                cout << "2. Inorden" << endl;
                cout << "3. Postorden" << endl;
                cout << "4. Por niveles" << endl;
                cout << "Opcion: ";
                cin >> opcion;
                arbol->visit(opcion);
                cout << endl;
                break;
            case 7:
                cout << "Fin del programa" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }while(opcion != 7);
    return 0;
}
