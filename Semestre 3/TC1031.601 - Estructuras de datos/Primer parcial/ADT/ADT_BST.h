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
    NodeT *getRoot(){return root;};
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
	NodeT *nuevo = new NodeT(dato);
  NodeT *p = root;

  if(p = nullptr){
    root = nuevo;
    return;
  }
  
  while(p != nullptr)
    p = (p->getData() > dato ? p->getLeft() : p->getRight());
  
	if(dato > p->getData()){
    p->setLeft(new NodeT(dato));
  }
  else if(dato < p->getData()){
    p->setRight(new NodeT(dato));
  }
  else{
  	cout<<"El dato ya existe."<<endl;
  }
}
void BST::preOrden(NodeT *p){
  if(p != nullptr){
    cout<<p->getData()<<" ";
    preOrden(p->getLeft());
    preOrden(p->getRight());
  }
}
void BST::read(){
  int dato;
  cout<<"Ingrese un dato: ";
  cin>>dato;
  while(dato != -1){
    insertarNodo(dato);
    cout<<"Ingrese un dato: ";
    cin>>dato;
  }
}
void BST::print(){
  cout<<"PreOrden: ";
  preOrden(root);
  cout<<endl;

  cout<<"InOrden: ";
  inOrden(root);
  cout<<endl;

  cout<<"PostOrden: ";
  postOrden(root);
  cout<<endl;
}
void BST::inOrden(NodeT *p){
  if(p != nullptr){
    inOrden(p->getLeft());
    cout<<p->getData()<<" ";
    inOrden(p->getRight());
  }
}
void BST::postOrden(NodeT *p){
  if(p != nullptr){
    postOrden(p->getLeft());
    postOrden(p->getRight());
    cout<<p->getData()<<" ";
  }
}

// void BST::insertarRecursivo(int valor, NodeT *p){
//   if(p == nullptr){
//     p = new NodeT(valor);
//     return;
//   }
//   else if(valor > p->getData()){
//     insertarRecursivo(valor, p->getLeft());
//   }
//   else if(valor < p->getData()){
//     insertarRecursivo(valor, p->getRight());
//   }
//   else{
//     cout<<"El dato ya existe y no puede ser insertado."<<endl;
//   }
// }

NodeT* insertarRecursivo (int valor, NodeT *p){
  if(p == nullptr){
    p = new NodeT(valor);
    return p;
  }
  else if(valor > p->getData()){
    p->setLeft(insertarRecursivo(valor, p->getLeft()));
  }
  else if(valor < p->getData()){
    p->setRight(insertarRecursivo(valor, p->getRight()));
  }
  else{
    cout<<"El dato ya existe y no puede ser insertado."<<endl;
  }
  cout << "Todos los valores fueron insertados correctamente." <<endl;
  return p;
}