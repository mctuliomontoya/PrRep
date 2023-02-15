#include <iostream>
#include <fstream>

using namespace std;

class NodeT {
private:
	int data;
	NodeT *left, *right;
public:	
	NodeT();
	NodeT(int d);
	int getData() { return data; };
	NodeT *getLeft() { return left; };
	void setLeft(NodeT *n) { left = n; };
	NodeT *getRight() { return right; };
	void setRight(NodeT *n) { right = n; };
};

class BST {
	private:
		NodeT *root;
	public:
		BST() {
			root = NULL;
		}
		BST(int d) {
			root = new NodeT(d);
		}
		void insertarNodo(int dato) {
			NodeT *nuevo = new NodeT(dato);
			NodeT *p = root;
			if (p == NULL) {
				root = nuevo;
				return;
			}
			while (p != NULL) {
				if (p->getData() == dato) {
					cout << "El dato ya existe" << endl;
					return;
				}
				else if (p->getData() > dato) {
					if (p->getLeft() == NULL) {
						p->setLeft(nuevo);
						return;
					}
					else {
						p = p->getLeft();
					}
				}
				else {
					if (p->getRight() == NULL) {
						p->setRight(nuevo);
						return;
					}
					else {
						p = p->getRight();
					}
				}
			}
		}
		bool search(int valor) {
			NodeT *p = root;
			while (p != NULL) {
				if (p->getData() == valor)
					return true;
				else
					p = (p->getData() > valor ? p->getLeft() : p->getRight());
			}
			return false;
		}
};
