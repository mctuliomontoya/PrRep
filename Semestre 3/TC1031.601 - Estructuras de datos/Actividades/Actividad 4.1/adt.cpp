/*
Grafo: Sus Representaciones y sus Recorridos.
Se representa un grafo mediante una lista de adyacencia
y una matriz de adyacencia. Después se llevan a cabo
los recorridos BFS (Breadth first search) y DFS (Depth first search).
*/
#include <iostream>
#include <vector>

using namespace std;

class Grafo {
    private:
        vector<int> vecNodos;
        vector<vector<bool>> matAdja;
    public:
        void addEdgeAdjList(vector<vector <int> > &listAdj, int m, int adyacente);
        void imprimeListaAdj(vector<vector <int> > &listAdj);
        void imprimeAdjMat();
        void addEdgeAdjMat(int vertice, int adyacente);
    	void agregarNodos(int n);
        void agregaArco(int origen, int destino);
        void borrarNodo(int n);
        void borrarArco(int origen, int destino);
        void buscarNodo(int n);
        void recorrerGrafo();
        void BFS(vector<vector <int> > &listAdj, int n);
        void getListaAdyacencia();
};

// Agregar nodos al grafo.
void Grafo::agregarNodos(int n){
	int valorNodo;
    vector<bool> linea;
    for(int i = 0; i < n; i++){
        cout << "Dame el valor del nodo: ";
        cin >> valorNodo;
        cout << endl;
        vecNodos.push_back(valorNodo);
        linea.push_back(false);
    }
    for(int x = 0; x < n; x++){
        matAdja.push_back(linea);
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

    } else {
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

// Imprimir la lveista de adyacencia.
void Grafo::imprimeListaAdj(vector<vector <int> > &listAdj){
    for(int i = 0; i < listAdj.size(); i++){
        cout << listAdj[i][0];
        for(int j = 1; j < listAdj[i].size(); j++){
            cout << "-->" << listAdj[i][j];
        }
        cout << endl << endl;
    }
}

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

void Grafo::BFS(vector<vector <int> > &listAdj, int n){
    vector<int> vecVisitados;
    vector<int> vecCola;
    int cont = 0;
    while(cont < listAdj.size()){
        if(listAdj[cont][0] == n){
            vecVisitados.push_back(n);
            for(int i = 1; i < listAdj[cont].size(); i++){
                vecCola.push_back(listAdj[cont][i]);
            }
            break;
        }
        cont++;
    }
    while(vecCola.size() != 0){
        int cont2 = 0;
        while(cont2 < listAdj.size()){
            if(listAdj[cont2][0] == vecCola[0]){
                for(int i = 1; i < listAdj[cont2].size(); i++){
                    vecCola.push_back(listAdj[cont2][i]);
                }
                break;
            }
            cont2++;
        }
        vecVisitados.push_back(vecCola[0]);
        vecCola.erase(vecCola.begin());
    }
    cout << "Recorrido BFS: ";
    for(int i = 0; i < vecVisitados.size(); i++){
        cout << vecVisitados[i] << " ";
    }
    cout << endl;
}

void Grafo::getListaAdyacencia(){
    int n;
    cout << "Dame el numero de nodos: ";
    cin >> n;
    agregarNodos(n);
    int vertice, adyacente;
    cout << "Dame el vertice: ";
    cin >> vertice;
    cout << "Dame el adyacente: ";
    cin >> adyacente;
    while(vertice != -1 && adyacente != -1){
        addEdgeAdjList(listAdj, vertice, adyacente);
        cout << "Dame el vertice: ";
        cin >> vertice;
        cout << "Dame el adyacente: ";
        cin >> adyacente;
    }
    imprimeListaAdj(listAdj);
    cout << "Dame el nodo para BFS: ";
    cin >> n;
    BFS(listAdj, n);
}

int main(){
    Grafo grafo;
    vector<vector<bool>> matAdja;
    grafo.agregarNodos(4);
    grafo.addEdgeAdjMat(10, 12);
    grafo.addEdgeAdjMat(10, 13);
    grafo.addEdgeAdjMat(11, 13);

    grafo.imprimeAdjMat();
    grafo.BFS(grafo.getListaAdyacencia(), 10);
}