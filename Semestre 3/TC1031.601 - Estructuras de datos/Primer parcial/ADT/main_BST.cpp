#include "ADT_BST.h"

using namespace std;

int main() {
    BST *tree = new BST();
    tree->insertarNodo(5);
    tree->insertarNodo(3);

    tree->print();
}