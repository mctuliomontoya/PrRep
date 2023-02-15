#include <iostream>

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
  public:
  	BST();
  	BST(int d);
    bool search(int valor);
  	void insertarNodo(int dato);
    void borrarNodo(int valor);
    void preOrden(NodeT *p);
    void inOrden(NodeT *p);
    void postOrden(NodeT *p);
    void insertarRecursivo(int valor, NodeT *p);
    void read();
    void print();
};
BST::BST(){
  root = nullptr;
}
BST::BST(int d){
  root = new NodeT(d);
}
bool BST::search(int valor){
    NodeT *p = root;
  while(p != nullptr){
    if (p->getData() == valor)
      return true;
    else
      p = (p->getData() > valor ? p->getLeft() : p->getRight());
  }
  return false;
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

void BST::borrarNodo(int valor){
  NodeT *p = root;
  NodeT *q = nullptr;
  while(p != nullptr && p->getData() != valor){
    q = p;
    p = (p->getData() > valor ? p->getLeft() : p->getRight());
  }
  if (p == nullptr)
    cout << "El valor no existe" << endl;
  else
    if (p->getLeft() == nullptr && p->getRight() == nullptr){
      if (q == nullptr)
        root = nullptr;
      else
        if (q->getLeft() == p)
          q->setLeft(nullptr);
        else
          q->setRight(nullptr);
      delete p;
    }
    else
      if (p->getLeft() == nullptr || p->getRight() == nullptr){
        NodeT *f;
        if (p->getLeft() != nullptr)
          f = p->getLeft();
        else
          f = p->getRight();
        if (q == nullptr)
          root = f;
        else
          if (q->getLeft() == p)
            q->setLeft(f);
          else
            q->setRight(f);
        delete p;
      }
      else{
        NodeT *f = p->getRight();
        if (f->getLeft() == nullptr){
          f->setLeft(p->getLeft());
          if (q == nullptr)
            root = f;
          else
            if (q->getLeft() == p)
              q->setLeft(f);
            else
              q->setRight(f);
          delete p;
        }
        else{
          NodeT *g = f;
          while(f->getLeft() != nullptr){
            g = f;
            f = f->getLeft();
          }
          g->setLeft(f->getRight());
          f->setLeft(p->getLeft());
          f->setRight(p->getRight());
          if (q == nullptr)
            root = f;
          else
            if (q->getLeft() == p)
              q->setLeft(f);
            else
              q->setRight(f);
          delete p;
        }
      }
}
void BST::preOrden(NodeT *p){
  if (p != nullptr){
    cout << p->getData() << " ";
    preOrden(p->getLeft());
    preOrden(p->getRight());
  }
}
void BST::inOrden(NodeT *p){
  if (p != nullptr){
    inOrden(p->getLeft());
    cout << p->getData() << " ";
    inOrden(p->getRight());
  }
}
void BST::postOrden(NodeT *p){
  if (p != nullptr){
    postOrden(p->getLeft());
    postOrden(p->getRight());
    cout << p->getData() << " ";
  }
}
void BST::insertarRecursivo(int valor, NodeT *p){
  if (p == nullptr)
    p = new NodeT(valor);
  else
    if (p->getData() > valor)
      insertarRecursivo(valor, p->getLeft());
    else
      insertarRecursivo(valor, p->getRight());
}
void BST::read(){
  int n, dato;
  cout << "Cuantos datos desea ingresar? ";
  cin >> n;
  for (int i = 0; i < n; i++){
    cout << "Ingrese el dato " << i + 1 << ": ";
    cin >> dato;
    insertarNodo(dato);
  }
}
void BST::print(){
  cout << "PreOrden: ";
  preOrden(root);
  cout << endl;
  cout << "InOrden: ";
  inOrden(root);
  cout << endl;
  cout << "PostOrden: ";
  postOrden(root);
  cout << endl;
}

int main(){
  BST arbol;
  arbol.read();
  arbol.print();
  int valor;
  cout << "Ingrese el valor a buscar: ";
  cin >> valor;
  if (arbol.search(valor))
    cout << "El valor existe" << endl;
  else
    cout << "El valor no existe" << endl;
  cout << "Ingrese el valor a borrar: ";
  cin >> valor;
  arbol.borrarNodo(valor);
  arbol.print();
  return 0;
}