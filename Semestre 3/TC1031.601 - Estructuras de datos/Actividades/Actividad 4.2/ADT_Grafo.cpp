/* 
Grafo: operaciones auxiliares
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

class Grafo {
    private:
        vector<int> vecNodos;
    public:
        void addEdgeAdjList(vector<vector <int> > &listAdj, int m, int adyacente);
        void addEdgeAdjMat(vector<vector <bool> > &matAdj, int vertice, int adyacente);
        void imprimeListaAdj(vector<vector <int> > &listAdj);    
        void imprimeMatrizAdj(vector<vector <bool> > &matAdj);   
        void loadGraph(int n, int m, vector<vector <bool> > &matAdj, vector<vector <int> > &listAdj);
    	void agregarNodos(int n);
        void agregaArco(int origen, int destino);
        void borrarNodo(int n);
        void borrarArco(int origen, int destino);
        void buscarNodo(int n);
        void BFS(vector<vector <int> > &listAdj, int n);
        void DFS(vector<vector <bool> > &matAdj, int n);
        void DFSRec(vector<vector <bool> > &matAdj, int n, vector<bool> &vecVisitados);
        void BFSRec(vector<vector <int> > &listAdj, int n, vector<bool> &vecVisitados);
        bool isTree(vector<vector <bool> > &matAdj);
        bool isCyclicUtil(vector<vector <bool> > &matAdj, int v, bool visited[], int parent);
        void topologicalSort(vector<vector <bool> > &matAdj);
        void topologicalSortUtil(vector<vector <bool> > &matAdj, int v, bool visited[], stack<int> &Stack);
        bool bipartiteGraph(vector<vector <bool> > &matAdj);


};

// Agregar nodos al grafo.
void Grafo::agregarNodos(int n){
	int valorNodo;
  for(int i = 0; i < n; i++){
  	cout << "Dame el valor del nodo: ";
    cin >> valorNodo;
    cout << endl;
    vecNodos.push_back(valorNodo); 
	}
}

// Agrega arcos
void Grafo::addEdgeAdjList(vector<vector <int> > &listAdj, int vertice, int adyacente) {
    if(listAdj.size()==0){
        vector<int> vecLista; 
        vector<int> vecListaAdj;
    	
        listAdj.push_back(vecLista);

        listAdj[0].push_back(vertice);
        listAdj[0].push_back(adyacente);

        listAdj.push_back(vecListaAdj);

        listAdj[1].push_back(adyacente);
        listAdj[1].push_back(vertice);

    } else{
        int cont = 0;
        while(cont + 1 <= listAdj.size()){
            // Si existe el vertice en la lista de adyacencia, meto el adyacente.
            if(listAdj[cont][0] == vertice){
                listAdj[cont].push_back(adyacente);
                break;
            }else if(cont + 1 == listAdj.size()){
                // Si no existe el vertice, creo el vector para el vertice y meto su adyacente.
                vector<int> vecVertice;
                vecVertice.push_back(vertice);
                vecVertice.push_back(adyacente);
                listAdj.push_back(vecVertice);
                break;
            }
            cont++;
			}
        cont = 0;
        while(cont + 1 <= listAdj.size()){
            // Si existe el adyacente,  meto el vertice como su adyacente.
            if(listAdj[cont][0] == adyacente){
                listAdj[cont].push_back(vertice);
                break;
            }else if(cont + 1 == listAdj.size()){
                // Si no existe, creo el vector para el adyacente y meto su vértice.
                vector<int> vecAdj;
                vecAdj.push_back(adyacente);
                vecAdj.push_back(vertice);
                listAdj.push_back(vecAdj);
                break;
            }
            cont++;
        }
    }
}

// Imprimir la lista de adyacencia.
void Grafo::imprimeListaAdj(vector<vector <int> > &listAdj){
    for(int i = 0; i < listAdj.size(); i++){
        cout << listAdj[i][0];
        for(int j = 1; j < listAdj[i].size(); j++){
            cout << "-->" << listAdj[i][j];
        }
        cout << endl << endl;
    }
}

// imprime la matriz de adyacencia
void Grafo::imprimeMatrizAdj(vector<vector <bool> > &matAdj) { // impime matriz adj con indicador de nodos
    cout << "  ";
    for(int i = 0; i < matAdj.size(); i++){
        cout << vecNodos[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < matAdj.size(); i++){
        cout << vecNodos[i] << "|";
        for(int j = 0; j < matAdj[i].size(); j++){
            cout << matAdj[i][j] << " ";
        }
        cout << endl;
    }
}

// Agrega arcos a matriz
void Grafo::addEdgeAdjMat(vector<vector <bool>> &matAdj, int vertice, int adyacente){
    int contVer = 0;
    while(contVer < vecNodos.size()){
        if(vecNodos[contVer] == vertice){
            int contAdj = 0;
            while(contAdj < vecNodos.size()){
                if(vecNodos[contAdj] == adyacente){
                    matAdj[contVer][contAdj] = true;
                    matAdj[contAdj][contVer] = true;
                    return;
                }
                contAdj++;
            }
        }
        contVer++;
    }
}

// Funcion para cargar grafo
void Grafo::loadGraph(int n, int m, vector<vector <bool> > &matAdj, vector<vector <int> > &listAdj){
    // Matriz de adyacencia
    for(int i = 0; i < n; i++){
        vector<bool> vecMat;
        for(int j = 0; j < n; j++){
            vecMat.push_back(false);
        }
        matAdj.push_back(vecMat);
    }

    cout << "Ingrese los arcos del grafo." << endl;
    int ver = 0; // Vertice
    int adya = 0; // Vertice Adayacente
    for(int i = 0; i < m; i++){
        cout << "Ingrese el vertice: ";
        cin >> ver;
        cout << endl;
        cout << "Ingrese el vertice adyacente: ";
        cin >> adya;
        cout << endl;
        // Busca en el vector de los nodos el valor del vertice con el que se busca hacer un arco.
        while((find(vecNodos.begin(), vecNodos.end(), ver) == vecNodos.end())|| (find(vecNodos.begin(), vecNodos.end(), adya) == vecNodos.end())){
            cout << "Has ingresado un valor que no es parte del grafo, intente de nuevo.";
            cout << "\nIngrese el vertice: ";
            cin >> ver;
            cout << endl;
            cout << "Ingrese el vertice adyacente: ";
            cin >> adya;
            cout << endl; 
        }
        addEdgeAdjMat(matAdj, ver, adya);
        // Lista de adyacencia
        addEdgeAdjList(listAdj, ver, adya);
    }
    
}

// Busqueda por anchura
void Grafo::BFS(vector<vector <int> > &listAdj, int vertice){
    // Creo un vector de booleanos para saber si un nodo ya fue visitado.
    vector<bool> vecVisitados(listAdj.size(), false);
    // Creo una cola para guardar los nodos a visitar.
    queue<int> cola;
    cola.push(vertice);

    while(!cola.empty()){
        int nodo = cola.front();
        cola.pop();
        if(!vecVisitados[nodo]){
            vecVisitados[nodo] = true;
            cout << listAdj[nodo][0] << " ";
            for(int i = 1; i < listAdj[nodo].size(); i++){
                cola.push(listAdj[nodo][i]);
            }
        }
    }
}

// Búsqueda por profundidad
void Grafo::DFS(vector<vector <bool> > &matAdj, int vertice){
    // Creo un vector de booleanos para saber si un nodo ya fue visitado.
    vector<bool> vecVisitados(matAdj.size(), false);
    // Creo una pila para guardar los nodos a visitar.
    stack<int> pila;
    pila.push(vertice);

    while(!pila.empty()){
        int nodo = pila.top();
        pila.pop();
        if(!vecVisitados[nodo]){
            vecVisitados[nodo] = true;
            cout << vecNodos[nodo] << " ";
            for(int i = 0; i < matAdj[nodo].size(); i++){
                if(matAdj[nodo][i]){
                    pila.push(i);
                }
            }
        }
    }
}

// DFS recursivo
void Grafo::DFSRec(vector<vector <bool> > &matAdj, int vertice, vector<bool> &vecVisitados){
    vecVisitados[vertice] = true;
    cout << vecNodos[vertice] << " ";
    for(int i = 0; i < matAdj[vertice].size(); i++){
        if(matAdj[vertice][i] && !vecVisitados[i]){
            DFSRec(matAdj, i, vecVisitados);
        }
    }
}

// BFS Recursivo
void Grafo::BFSRec(vector<vector <int> > &listAdj, int vertice, vector<bool> &vecVisitados){
    vecVisitados[vertice] = true;
    cout << listAdj[vertice][0] << " ";
    for(int i = 1; i < listAdj[vertice].size(); i++){
        if(!vecVisitados[listAdj[vertice][i]]){
            BFSRec(listAdj, listAdj[vertice][i], vecVisitados);
        }
    }
}

// Bool para saber si un grafo es arbol
bool Grafo::isTree(vector<vector <bool> > &matAdj) {
    // Marca todos los nodos como no visitados
    bool *visited = new bool[matAdj.size()];
    for (int i = 0; i < matAdj.size(); i++) {
        visited[i] = false;
    }

    if(isCyclicUtil(matAdj, 0, visited, -1)) {
        return false;
    }

    for (int u = 0; u < matAdj.size(); u++) {
        if (!visited[u]) {
            return false;
        }
    }

    return true;
}

// Función auxiliar par la función isTree
bool Grafo::isCyclicUtil(vector<vector <bool> > &matAdj, int v, bool visited[], int parent) { 
    // Marca el nodo como visitado
    visited[v] = true;

    // Recur para los vertices adyacentes del nodo
    for (int i = 0; i < matAdj.size(); i++) {
        if (matAdj[v][i]) {
            if (!visited[i]) {
                if (isCyclicUtil(matAdj, i, visited, v)) {
                    return true;
                }
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

// función para orden topológico
void Grafo::topologicalSort(vector<vector <bool> > &matAdj) {
    stack<int> Stack;

    // Marca todos los nodos como no visitados
    bool *visited = new bool[matAdj.size()];
    for (int i = 0; i < matAdj.size(); i++) {
        visited[i] = false;
    }

    // Llama a la función auxiliar recursiva
    for (int i = 0; i < matAdj.size(); i++) {
        if (visited[i] == false) {
            topologicalSortUtil(matAdj, i, visited, Stack);
        }
    }

    // Imprime el contenido del stack
    while (Stack.empty() == false) {
        cout << vecNodos[Stack.top()] << " ";
        Stack.pop();
    }

    delete visited;

}

// Función auxiliar para el orden topologico
void Grafo::topologicalSortUtil(vector<vector <bool> > &matAdj, int v, bool visited[], stack<int> &Stack) {
    // Marca el nodo actual como visitado
    visited[v] = true;

    for (int i = 0; i < matAdj.size(); i++) {
        if (matAdj[v][i]) {
            if (!visited[i]) {
                topologicalSortUtil(matAdj, i, visited, Stack);
            }
        }
    }

    Stack.push(v);
}

bool Grafo::bipartiteGraph(vector<vector <bool> > &matAdj) {
    /* 
    Crea un array de colores para guardar los colores asignados a los vertices. 
    El numero del vertice es utilizado como index del array, el valor -1 del array
    es utilizado para indeicar que no hay color asignado al vertice 'i'.
    */
    int *colorArr = new int[matAdj.size()];
    for (int i = 0; i < matAdj.size(); i++) {
        colorArr[i] = -1;
    }

    // Asigna el primer color al inicio
    colorArr[0] = 1;

    queue <int> q;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (matAdj[u][u]) {
            return false;
        }

        for (int v = 0; v < matAdj.size(); v++) {
            if (matAdj[u][v] && colorArr[v] == -1) {
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

            else if (matAdj[u][v] && colorArr[v] == colorArr[u]) {
                return false;
            }
        }
    }
    return true;
}

int main()  {
    Grafo objGrafo;
    vector<vector <int> > listAdj;
    vector <vector <bool> > matAdj; 
    int n = 0; // vertices
    int m = 0; // arcos
    int datoInicial = 0;
    cout << "Ingrese el numero de vertices: ";
    cin >> n;
    cout << endl;
    cout << "Ingrese el numero de arcos: ";
    cin >> m;
    cout << endl;


    objGrafo.agregarNodos(n);
    objGrafo.loadGraph(n, m,matAdj,listAdj);
    cout << endl;
    cout << "Lista de Adyacencia" << endl;
    objGrafo.imprimeListaAdj(listAdj);
    cout << endl;
    cout << "Matriz de Adyacencia" << endl;
    objGrafo.imprimeMatrizAdj(matAdj);
    cout << endl;
/*
    METODOS DE RECORRIDO - ACTIVIDAD 4.1

    cout << "BFS Recursivo" << endl;
    cout << "Ingrese el vertice inicial: ";
    cin >> datoInicial;
    cout << endl;
    vector<bool> vecVisitados(listAdj.size(), false);
    objGrafo.BFSRec(listAdj, datoInicial, vecVisitados);

    cout << endl;
    cout << "DFS Recursivo" << endl;
    cout << "Ingrese el vertice inicial: ";
    cin >> datoInicial;
    cout << endl;
    vector<bool> vecVisitados2(matAdj.size(), false);
    objGrafo.DFSRec(matAdj, datoInicial, vecVisitados2);
*/    

 
    if (objGrafo.isTree(matAdj) == true){
        cout << endl;
        cout << "El grafo es un arbol" << endl;
    }else{
        cout << endl;
        cout << "El grafo no es un arbol" << endl;
    }

    cout << endl;
    cout << "Orden Topologico:" << endl;
    objGrafo.topologicalSort(matAdj);

    if (objGrafo.bipartiteGraph(matAdj) == true){
        cout << endl;
        cout << "\nEl grafo es bipartido" << endl;
    }else{
        cout << endl;
        cout << "\nEl grafo no es bipartido" << endl;

    }
    
    return 0;

}

