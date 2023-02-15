#include <iostream>
#include "ADT_Grafo.h"

using namespace std;

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
    cout << endl;
    cout << "Matriz de Adyacencia" << endl;
    objGrafo.imprimeMatrizAdj(matAdj);
    cout << endl;



    // BFS
    // cout << "BFS" << endl;
    // cout << "Ingrese el nodo inicial del grafo: ";
    // cin >> datoInicial;
    // objGrafo.BFS(listAdj, datoInicial);

    // // DFS
    cout << "\n\nDFS" << endl;
    cout << "Ingrese el nodo inicial del grafo: ";
    cin >> datoInicial;
    objGrafo.DFSRec(matAdj, 0, vecVisitados);
    return 0;
}