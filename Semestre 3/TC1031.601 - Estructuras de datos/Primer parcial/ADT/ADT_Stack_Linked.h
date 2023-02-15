#include <iostream>
#include "ADT_LinkedList.h"

using namespace std;

class PilaLista{
    private:
        LinkedList espacioPila;
    public:
        void push(int dato) {
            espacioPila.insertarInicio(dato);
        }

        bool pop() {
            return espacioPila.eliminaInicio();
        }

        int getTop() {
            return espacioPila.getPrimero();
        }

        bool pilaVacia() {
            return espacioPila.listaVacia();
        }
};