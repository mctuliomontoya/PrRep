/* 
Grafo: Sus Representaciones y sus Recorridos.
Se representa un grafo mediante una lista de adyacencia
y una matriz de adyacencia. Después se llevan a cabo
los recorridos BFS (Breadth first search) y DFS (Depth first search).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

class Grafo {
    private:
        vector<int> vecNodos;
    public:
        void addEdgeAdjList(vector<vector <int> > &listAdj, int m, int adyacente);
        void addEdgeAdjMat(vector<vector <bool> > &matAdj, int vertice, int adyacente);
        void imprimeListaAdj(vector<vector <int> > &listAdj);    
        // void imprimeMatrizAdj(vector<vector <bool> > &matAdj);   
        void loadGraph(int n, int m, vector<vector <bool> > &matAdj, vector<vector <int> > &listAdj);
    	void agregarNodos(int n);
        void agregaArco(int origen, int destino);
        void borrarNodo(int n);
        void borrarArco(int origen, int destino);
        void buscarNodo(int n);
        void recorrerGrafo();
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

void Grafo::loadGraph(int n, int m, vector<vector <bool> > &matAdj, vector<vector <int> > &listAdj){
    // Matriz de adyacencia
    for(int i = 0; i < n; i++){
        vector<bool> vecInside(n, false);
        matAdj.push_back(vecInside);
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

int main(){
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



    // BFS
    // cout << "BFS" << endl;
    // cout << "Ingrese el nodo inicial del grafo: ";
    // cin >> datoInicial;
    // objGrafo.BFS(listAdj, datoInicial);

    // // DFS
    // cout << "DFS" << endl;
    // cout << "Ingrese el nodo inicial del grafo: ";
    // cin >> datoInicial;
    // objGrafo.DFS(matAdj, datoInicial);
    return 0;
}
