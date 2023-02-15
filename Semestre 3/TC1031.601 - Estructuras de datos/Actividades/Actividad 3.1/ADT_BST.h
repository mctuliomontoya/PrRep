// ADT que implementa un BST 
//KULIQUITACATI KULIQUITAKATA
#include <iostream>
#include <fstream>

using namespace std;

class NodoArbolBinario{
public:
    int info;
    NodoArbolBinario *hijoIzquierdo;
    NodoArbolBinario *hijoDerecho;

    NodoArbolBinario(int dato){
        info = dato;
        hijoIzquierdo = nullptr;
        hijoDerecho   = nullptr;
    }
};

class BST{
    private:
        NodoArbolBinario *raiz;
        NodoArbolBinario* insertarRecursivo(NodoArbolBinario *p, int dato);
        void preordenRecursivo(NodoArbolBinario *p);
        void inordenRecursivo(NodoArbolBinario *p);
        void postordenRecursivo(NodoArbolBinario *p);
        void levelByLevelRecursivo(NodoArbolBinario *node, int level);
        int heightRecursiva(NodoArbolBinario *node);
        bool ancestorsRecursivo(NodoArbolBinario *node, int target);
        int whatLevelAmIRecursivo(NodoArbolBinario *node, int target, int level);
        void preorden();
        void inorden();
        void postorden();
        void levelByLevel();
  
    public:
        BST(){ // Constructor default
            raiz = nullptr;
        }
    
        void insertar(int dato);
        int height();
        void ancestors(int target);
        int whatlevelamI(int target);
        void visit(int num);
        void insertarElementos();
        void read(string arch);

        
};
void BST::read(string arch) {
    int n, num;
    ifstream myFile(arch);
    if(myFile.is_open()) {
        myFile >> n;
        for(int i = 0; i < n; i++) {
            myFile >> num;
            insertar(num);
        }
    }
    else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}
        
void BST::insertar(int dato){ // Inserta un elemento en el BST
    raiz = insertarRecursivo(raiz, dato);
}

NodoArbolBinario* BST::insertarRecursivo(NodoArbolBinario *p, int dato){ // Inserta un elemento en el BST
    if(p == nullptr)
        p = new NodoArbolBinario(dato);
    else if (dato < p->info)
        p->hijoIzquierdo = insertarRecursivo(p->hijoIzquierdo, dato);
    else if(dato > p->info)
        p->hijoDerecho = insertarRecursivo(p->hijoDerecho, dato);
    else
        cout << "El elemento ya existe y no se puede insertar" << endl;
    return p;
}

int BST::height(){ // Regresa la altura del BST
    return heightRecursiva(raiz);
  
}

int BST::heightRecursiva(NodoArbolBinario *node){ //devuelve la altura del arbol
    if(node == NULL){
        return 0;
    }
  	else{
    	int leftHeight = heightRecursiva(node->hijoIzquierdo);  
    	int rightHeight = heightRecursiva(node->hijoDerecho);
      	
		if(leftHeight > rightHeight){
            return (leftHeight + 1);
        }
        else {
            return(rightHeight + 1);
        }
    }
    
}

void BST::preorden(){    //visita raíz-subárbol izquierdo-subárbol derecho
    preordenRecursivo(raiz);
}

void BST::preordenRecursivo(NodoArbolBinario *p){ //visita raíz-subárbol izquierdo-subárbol derecho
    if(p != nullptr){
        cout << p->info << " ";
        preordenRecursivo(p->hijoIzquierdo);
        preordenRecursivo(p->hijoDerecho);
    }
}

void BST::inorden(){    //visita subárbol izquierdo-raíz-subárbol derecho
    inordenRecursivo(raiz);
}

void BST::inordenRecursivo(NodoArbolBinario *p){
    if(p != nullptr){
        inordenRecursivo(p->hijoIzquierdo);
        cout << p->info << " ";
        inordenRecursivo(p->hijoDerecho);
    }
}

void BST::levelByLevel(){
    
    int altura = height(); 
    // El nivel de la raiz es cero
    for(int i = 0; i < altura; i++){ 
        levelByLevelRecursivo(raiz, i); 
    }
}

void BST::levelByLevelRecursivo(NodoArbolBinario *node, int level){
    if(node == nullptr){
        return;
    }
    if(level == 0){
        cout << node->info << " ";
    }
    else if(level > 0){
    	levelByLevelRecursivo(node->hijoIzquierdo, level -1);
    	levelByLevelRecursivo(node->hijoDerecho, level -1);
  }
  
}


void BST::postorden(){    //visita subárbol izquierdo-subárbol derecho-raíz
    postordenRecursivo(raiz);
}

void BST::postordenRecursivo(NodoArbolBinario *p){
    if(p != nullptr){
        postordenRecursivo(p->hijoIzquierdo);
        postordenRecursivo(p->hijoDerecho);
        cout << p->info << " ";
    }
}

void BST::visit(int num){
    switch (num) {
        case 1:
            preorden();
            break;
        case 2:
            inorden();
            break;
        case 3:
            postorden();
            break;
        case 4:
            levelByLevel();
            break;
        default:
            break;
    }
}

void BST::ancestors(int target){
    ancestorsRecursivo(raiz, target);
}

bool BST::ancestorsRecursivo(NodoArbolBinario *node, int target){
    if(node == nullptr){
        return false;
    }
    if(node->info == target){
        return true;
    }
    if(ancestorsRecursivo(node->hijoIzquierdo, target) || ancestorsRecursivo(node->hijoDerecho, target)){
        cout << node->info << " ";
        return true;
    }
    return false;
}

int BST::whatlevelamI(int target){
    return whatLevelAmIRecursivo(raiz, target, 0);
}

int BST::whatLevelAmIRecursivo(NodoArbolBinario *node, int target, int level){
    if(node == nullptr){
        return -1;
    }
    if(node->info == target){
        return level;
    }
    int leftLevel = whatLevelAmIRecursivo(node->hijoIzquierdo, target, level + 1);
    if(leftLevel != -1){
        return leftLevel;
    }
    int rightLevel = whatLevelAmIRecursivo(node->hijoDerecho, target, level + 1);
    return rightLevel;
}

void BST::insertarElementos() {
    int n;
    cout << "Ingrese la cantidad de elementos que desea insertar: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        int dato;
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> dato;
        insertar(dato);
    }
    cout << "Todos los valores fueron insertados correctamente." <<endl;
}
