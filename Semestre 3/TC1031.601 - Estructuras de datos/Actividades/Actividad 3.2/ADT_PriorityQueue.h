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
        void swap(int *a, int *b);
        void read(string arch);
        void heapify(int n, int i);
};

void PriorityQueue::heapify(int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && datos[l] > datos[largest])
        largest = l;
    if (r < n && datos[r] > datos[largest])
        largest = r;
    if (largest != i) {
        swap(&datos[i], &datos[largest]);
        heapify(n, largest);
    }
}
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

void PriorityQueue::push(int valor){ //se hace push en prioridad de heap tree
    if (isFull()) {
        cout << "La cola esta llena" << endl;
    }
    else {
        if (frente == -1) {
            frente = 0;
        }
        final++;
        datos[final] = valor;
        int i = final;
        while (i > 0 && datos[i] > datos[(i-1)/2]) {
            swap(&datos[i], &datos[(i-1)/2]);
            i = (i-1)/2;
        }
    }

}

void PriorityQueue::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int PriorityQueue::pop() {
    if (isEmpty()) {
        cout << "La cola esta vacia" << endl;
        return -1;
    }
    else {
        int temp = datos[frente];
        datos[frente] = datos[final];
        final--;
        if (final == -1) {
            frente = -1;
        }
        else {
            heapify(final+1, frente);
        }
        return temp;
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

