#include <iostream>
#include <fstream>

using namespace std;

class LineaRegistro{
    private:
        string fecha;
        string hora;
        string entrada;
        string UBI;
    public: 
        LineaRegistro();
        LineaRegistro(string f, string h, string e, string u);
        string getFecha(){return fecha;};
        string getHora(){return hora;};
        string getEntrada(){return entrada;};
        string getUBI(){return UBI;};
        void setFecha(string f){fecha = f;};
        void setHora(string h){hora = h;};
        void setEntrada(string e){entrada = e;};
        void setUBI(string u){UBI = u;};
};

class NodoLista {
    public:
        LineaRegistro registro;
        NodoLista *next;

        NodoLista(LineaRegistro linea){
            registro = linea;
            next = nullptr;
        }
};

class LinkedList {
    private:
        NodoLista *primero;
    public:
        void Lista() {
            primero = nullptr;
        }

        NodoLista *search(NodoLista *primero, string ubi) {
            NodoLista *aux = primero;
            while (aux != nullptr) {
                if (aux->registro.getUBI() == ubi) {
                    return aux;
                }
                aux = aux->next;
            }
            return nullptr;
        }
};
