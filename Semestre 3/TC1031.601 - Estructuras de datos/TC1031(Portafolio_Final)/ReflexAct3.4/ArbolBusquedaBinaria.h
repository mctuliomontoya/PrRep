#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class NodeT{
    private:
  	    int data;
  	    NodeT *left, *right; 
    public:
        NodeT();
        NodeT(int d);
        int getData(){return data;};
        NodeT *getLeft(){return left;};
        void setLeft(NodeT *n){left = n;};
        NodeT *getRight(){return right;};
        void setRight(NodeT *n){right = n;};
};	

NodeT::NodeT(){
    left = nullptr;
    right = nullptr;
}

NodeT::NodeT(int d){
    data = d;
    left = nullptr;
    right = nullptr;
}

class BST{
    private:
        NodeT *root;
        vector<int> stack;
    public:
        BST();
        BST(int d);
        void insertarNodo(int dato);
        void stackInorder(NodeT *p);
        int calcularComparaciones();
        void readArch(string arch);
        void inOrden(NodeT *p);
        void print();
};



BST::BST(){
    root = nullptr;
}

BST::BST(int d){
    root = new NodeT(d);
}

void BST::insertarNodo(int dato){
    NodeT *p = root;
    NodeT *q = nullptr;
    while(p != nullptr){
        q = p;
        p = (p->getData() > dato ? p->getLeft() : p->getRight());
    }
    if (q == nullptr)
        root = new NodeT(dato);
    else
        if (q->getData() > dato)
        q->setLeft(new NodeT(dato));
        else
        q->setRight(new NodeT(dato));
}

void BST::stackInorder(NodeT *node){
    if(node != nullptr){
        stackInorder(node->getLeft());
        stack.push_back(node->getData());
        stackInorder(node->getRight());
    }
}

int BST::calcularComparaciones(){
    stackInorder(root);
    vector<int> datos;
    if(stack.size() > 0){
        int puntero = 1;
        int suma = stack[0];
        while(puntero < stack.size()){
            suma += stack[puntero] - 1;
            datos.push_back(suma);
            puntero += 1;
        }
    }

    int comparaciones = 0;
    for(int i = 0; i < datos.size(); i++){
        comparaciones += datos[i];
    }

    return comparaciones;
}

void BST::readArch(string filename) { // read the array from a file
    int n, num;

    ifstream myFile(filename);
    if(myFile.is_open()) {
        myFile >> n;
        for(int i = 0; i < n; i++) {
        myFile >> num;
        insertarNodo(num);
        }
    myFile.close();
    }
}

void BST::print (){
    inOrden(root);
}

void BST::inOrden(NodeT *p){
    if(p != nullptr){
        inOrden(p->getLeft());
        cout<<p->getData()<<" ";
        inOrden(p->getRight());
    }
}