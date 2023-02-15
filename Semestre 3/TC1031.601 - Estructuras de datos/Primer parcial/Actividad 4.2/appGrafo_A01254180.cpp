/*
Grafo: Sus Representaciones y sus Recorridos.
Se representa un grafo mediante una lista de adyacencia
y una matriz de adyacencia. Después se llevan a cabo
los recorridos BFS (Breadth first search) y DFS (Depth first search).
*/
#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

class Grafo {
    private:
        vector<int> vecNodos;
        vector<vector<bool>> matAdja;
        vector<vector<int>> listAdj;
    public:
        void addEdgeAdjList(int m, int adyacente);
        void imprimeListaAdj();
        void addEdgeAdjMat(int vertice, int adyacente);
        void imprimeAdjMat();
    	void agregarNodos(int n);
        void loadGraph(int cantVertices, int cantArcos);
        void DFS(int inicio);
        void dfsRecursivo(int actual, vector<bool> &visitado);
        void BFS(int inicio);
        int findNodo(int valor);
        bool isTree();
        bool isTreeRecursivo(int actual, vector<bool> &visitado, int padre);
        void topologicalSort();
        void topologicalSortRecursivo(int actual, vector<bool> &visitado, stack<int> &pila);
};

// Agregar nodos al grafo
void Grafo::agregarNodos(int n){
	int valorNodo;
    vector<bool> linea;
    for(int i = 0; i < n; i++){
        cout << "Dame el valor del nodo " << i << ": ";
        cin >> valorNodo;
        vecNodos.push_back(valorNodo);
        linea.push_back(false);
    }
    for(int x = 0; x < n; x++){
        matAdja.push_back(linea);
    }
}

// Encontrar el nodo en el vector de nodos
int Grafo::findNodo(int valor){ 
    int lugar = 0;
    while(lugar < vecNodos.size()){
        if(vecNodos[lugar] == valor){
            return lugar;
        }
        lugar++;
    }
    return -1;
}

// Agregar arcos a la lista de adyacencia
void Grafo::addEdgeAdjList(int vertice, int adyacente) {
    int posVerNodo = findNodo(vertice);
    int posAdjNodo = findNodo(adyacente);
    // Si el nodo no existe, se agrega
    if(listAdj.size()==0){
        vector<int> vecLista; 
        vector<int> vecListaAdj;
    	
        listAdj.push_back(vecLista);

        listAdj[0].push_back(posVerNodo);
        listAdj[0].push_back(posAdjNodo);

        listAdj.push_back(vecListaAdj);

        listAdj[1].push_back(posAdjNodo);
        listAdj[1].push_back(posVerNodo);

    } else { // Si el nodo ya existe, se agrega el adyacente
        int cont = 0;
        while(cont + 1 <= listAdj.size()){
            // Si el nodo ya existe, se agrega el adyacente
            if(vecNodos[listAdj[cont][0]] == vertice){
                listAdj[cont].push_back(posAdjNodo);
                break;
            }else if(cont + 1 == listAdj.size()){
                // Si el nodo no existe, se agrega
                vector<int> vecVertice;
                vecVertice.push_back(posVerNodo);
                vecVertice.push_back(posAdjNodo);
                listAdj.push_back(vecVertice);
                break;
            }
            cont++;
			}
        cont = 0;
        while(cont + 1 <= listAdj.size()){
            // Si existe el adyacente,  meto el vertice como su adyacente.
            if(vecNodos[listAdj[cont][0]] == adyacente){
                listAdj[cont].push_back(posVerNodo);
                break;
            }else if(cont + 1 == listAdj.size()){
                // Si no existe, creo el vector para el adyacente y meto su vértice.
                vector<int> vecAdj;
                vecAdj.push_back(posAdjNodo);
                vecAdj.push_back(posVerNodo);
                listAdj.push_back(vecAdj);
                break;
            }
            cont++;
        }
    }
}

// Imprimir la lista de adyacencia.
void Grafo::imprimeListaAdj(){
    for(int i = 0; i < listAdj.size(); i++){
        cout << listAdj[i][0];
        for(int j = 1; j < listAdj[i].size(); j++){
            cout << "->" << listAdj[i][j];
        }
        cout << endl;
    }
}

// Agregar arcos a la matriz de adyacencia
void Grafo::addEdgeAdjMat(int vertice, int adyacente){
    int contVer = 0;
    while(contVer < vecNodos.size()){
        if(vecNodos[contVer] == vertice){
            int contAdj = 0;
            while(contAdj < vecNodos.size()){
                if(vecNodos[contAdj] == adyacente){
                    matAdja[contVer][contAdj] = true;
                    matAdja[contAdj][contVer] = true;
                    return;
                }
                contAdj++;
            }
        }
        contVer++;
    }
}

// Imprimir la matriz de adyacencia
void Grafo::imprimeAdjMat(){
    cout << "   ";
    for(int l = 0; l < matAdja.size(); l++){
        cout << vecNodos[l] << " ";
    }
    cout << endl << endl;
    for(int i = 0; i < matAdja.size(); i++){
        cout << vecNodos[i] << "  ";
        for(int x = 0; x < matAdja.size(); x++){
            if(matAdja[i][x] == true){
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

// Recorrer el grafo en profundidad
void Grafo::DFS(int inicio){
    vector<bool> visitado(vecNodos.size(), false);
    cout << "Recorrido DFS: ";
    dfsRecursivo(inicio, visitado);
}

// auxiliar para el recorrido en profundidad
void Grafo::dfsRecursivo(int actual, vector<bool> &visitado){
    cout << vecNodos[actual] << " ";
    visitado[actual] = true;
    for(int i = 0; i < matAdja[actual].size(); i++){
        if(matAdja[actual][i] == 1 && (!visitado[i])){
            dfsRecursivo(i, visitado);
        }
    }
}

// Recorrer el grafo en amplitud
void Grafo::BFS(int actual){
    vector<bool> visitado(vecNodos.size(), false);
    list<int> cola;

    visitado[actual] = true;
    cola.push_back(actual);

    cout << "Recorrido BFS: ";
    while(!cola.empty()){
        actual = cola.front();
        cout << vecNodos[actual] << " ";
        cola.pop_front();

        for(int pos = 0; pos < listAdj[actual].size(); pos++){
            if(!visitado[listAdj[actual][pos]]){
                visitado[listAdj[actual][pos]] = true;
                cola.push_back(listAdj[actual][pos]);
            }
        }
    }
}

// Buscar un nodo en la lista de adyacencia
void Grafo::loadGraph(int cantVertices, int cantArcos){
    agregarNodos(cantVertices);
    cout << "---";
    for(int v = 0; v < cantArcos; v++){
        int ver, adj;
        cout << endl;
        cout << "Ingrese el vertice " << v << ":   ";
        cin >> ver;
        cout << "Ingrese el adyacente " << v << ": ";
        cin >> adj;
        addEdgeAdjMat(ver, adj);
        addEdgeAdjList(ver, adj);
    }

    cout << "---" << endl;
    imprimeAdjMat();

    cout << "---" << endl;
    imprimeListaAdj();
}

bool Grafo::isTree(){
    vector<bool> visitado(vecNodos.size(), false);
    if(isTreeRecursivo(0, visitado, -1)){
        for(int i = 0; i < visitado.size(); i++){
            if(!visitado[i]){
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

bool Grafo::isTreeRecursivo(int actual, vector<bool> &visitado, int padre){
    visitado[actual] = true;
    for(int i = 0; i < matAdja[actual].size(); i++){
        if(matAdja[actual][i] == 1 && (!visitado[i])){
            if(!isTreeRecursivo(i, visitado, actual)){
                return false;
            }
        } else if(i != padre){
            return false;
        }
    }
    return true;
}

void Grafo::topologicalSort(){
    vector<bool> visitado(vecNodos.size(), false);
    stack<int> pila;

    for(int i = 0; i < vecNodos.size(); i++){
        if(!visitado[i]){
            topologicalSortRecursivo(i, visitado, pila);
        }
    }

    cout << "Orden topologico: ";
    while(!pila.empty()){
        cout << vecNodos[pila.top()] << " ";
        pila.pop();
    }
}

void Grafo::topologicalSortRecursivo(int actual, vector<bool> &visitado, stack<int> &pila){
    visitado[actual] = true;
    for(int i = 0; i < matAdja[actual].size(); i++){
        if(matAdja[actual][i] == 1 && (!visitado[i])){
            topologicalSortRecursivo(i, visitado, pila);
        }
    }
    pila.push(actual);
}

int main(){
    Grafo grafo;
    grafo.loadGraph(4, 3);


    cout << "---" << endl;
    if (grafo.isTree()){
        cout << "El grafo es un arbol" << endl;
    } else {
        cout << "El grafo no es un arbol" << endl;
    }

    return 0;
}