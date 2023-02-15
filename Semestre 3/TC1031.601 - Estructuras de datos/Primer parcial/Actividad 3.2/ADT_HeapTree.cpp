#include <iostream>
#include <fstream>

using namespace std;

class NodeHeap {
    private:
        int dato;
        NodeHeap *left;
        NodeHeap *right;
    public:
        NodeHeap(int dato) {
            this->dato = dato;
            left = NULL;
            right = NULL;
        }
        int getDato() {
            return dato;
        }
        void setDato(int dato) {
            this->dato = dato;
        }
        NodeHeap* getLeft() {
            return left;
        }
        void setLeft(NodeHeap *left) {
            this->left = left;
        }
        NodeHeap* getRight() {
            return right;
        }
        void setRight(NodeHeap *right) {
            this->right = right;
        }
};

class HeapTree {
    private:
        NodeHeap *root;
        int size;
    public:
        HeapTree() {
            root = NULL;
            size = 0;
        }
        void push(int dato);
        int pop();
        int front();
        int back();
        bool isEmpty();
        bool isFull();
        int getSize();
        void print();
        void read(string arch);
};

void HeapTree::read(string arch) { 
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

void HeapTree::push(int dato) {
    if (isFull()) {
        cout << "El arbol esta lleno" << endl;
    }
    else {
        if (isEmpty()) {
            root = new NodeHeap(dato);
            size++;
        }
        else {
            NodeHeap *aux = root;
            while (aux->getLeft() != NULL && aux->getRight() != NULL) {
                if (aux->getLeft()->getDato() < aux->getRight()->getDato()) {
                    aux = aux->getLeft();
                }
                else {
                    aux = aux->getRight();
                }
            }
            if (aux->getLeft() == NULL) {
                aux->setLeft(new NodeHeap(dato));
            }
            else {
                aux->setRight(new NodeHeap(dato));
            }
            size++;
        }
    }
}

void HeapTree::print() {
    if (isEmpty()) {
        cout << "El arbol esta vacio" << endl;
    }
    else {
        NodeHeap *aux = root;
        while (aux->getLeft() != NULL && aux->getRight() != NULL) {
            cout << aux->getDato() << " ";
            if (aux->getLeft()->getDato() < aux->getRight()->getDato()) {
                aux = aux->getLeft();
            }
            else {
                aux = aux->getRight();
            }
        }
        cout << aux->getDato() << endl;
    }
}

int HeapTree::getSize() {
    return size;
}

bool HeapTree::isEmpty() {
    return size == 0;
}

bool HeapTree::isFull() {
    return size == 15;
}
int main() {
    HeapTree *tree = new HeapTree();
    tree->read("data.txt");
    tree->print();
}