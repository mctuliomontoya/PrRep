#include <iostream>
#include <fstream>

using namespace std;

#define MAX 50


class PriorityQueue {
    private: 
        int datos[MAX];
        int frente, final;
    public:
        PriorityQueue() {
            frente = -1;
            final = -1;
        }
        void push(int valor);
        int pop();
        int front();
        int back();
        bool isEmpty();
        bool isFull();
        int size();
        void print();
        void read(string arch);
};

void PriorityQueue::read(string arch) {
    int n, num;
    ifstream myFile(arch);
    if(myFile.is_open()) {
        myFile >> n;
        for(int i = 0; i < n; i++) {
            myFile >> num;
            push(num);
        }
    }
    else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}

void PriorityQueue::push(int valor) {
    if (isFull()) {
        cout << "La cola esta llena" << endl;
    }
    else {
        if (isEmpty()) {
            frente = 0;
            final = 0;
            datos[final] = valor;
        }
        else {
            int i = final;
            while (i >= frente && valor > datos[i]) {
                datos[i+1] = datos[i];
                i--;
            }
            datos[i+1] = valor;
            final++;
        }
    }
}

int PriorityQueue::pop() {
    if (isEmpty()) {
        cout << "La cola esta vacia" << endl;
        return -1;
    }
    else {
        int valor = datos[frente];
        if (frente == final) {
            frente = final = -1;
        }
        else {
            frente++;
        }
        return valor;
    }
}

int PriorityQueue::back() {
    if (isEmpty()) {
        cout << "La cola esta vacia" << endl;
        return -1;
    }
    else {
        return datos[final];
    }
}

int PriorityQueue::front() {
    if (isEmpty()) {
        cout << "La cola esta vacia" << endl;
        return -1;
    }
    else {
        return datos[frente];
    }
}

bool PriorityQueue::isEmpty() {
    return (frente == -1);
}

bool PriorityQueue::isFull() {
    return (final == MAX-1);
}

int PriorityQueue::size() {
    if (isEmpty()) {
        return 0;
    }
    else {
        return (final - frente + 1);
    }
}

void PriorityQueue::print() {
    if (isEmpty()) {
        cout << "La cola esta vacia" << endl;
    }
    else {
        for (int i = frente; i <= final; i++) {
            cout << datos[i] << " ";
        }
        cout << endl;
    }
}
