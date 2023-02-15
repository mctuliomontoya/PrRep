/* Ordenamiento topológico de un DAG AD-2022 */
//4
#include <iostream>
#include <vector>
#include <algorithm> // Para el metodo find
#include <stack>
#include <list>
using namespace std;

/*
// Clase para representar un grafo
class Grafo {
    public:
        // No. de vertices'
        int V;
        // apuntador a un arreglo que contiene la lista de adyacencia
        list<int>* adj;

        Grafo(int v){   // Constructor
            V = v;
            adj = new list<int>[V];
        }

    public:
    void agregarVertice(int v, int w){
        // Agrega w a la lista de v’s.
        adj[v].push_back(w);
    }
*/

class Grafo {
    private:
        vector<int> vecNodos;
    public:
        Grafo();
        void agregarNodos(int n);
        void addEdgeAdjList(vector<vector<int>> &listAdj, int vertice, int adyacente);
        // void imprimeListaAdj(vector<vector<int>> &listAdj);
        void loadGraph(int n, int m, vector<vector<int>> &listAdj);
  		void agregarVertice(int vertice, int adyacente);
        void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
        void topologicalSort();
};

// agregar nodos al grafo
void Grafo::agregarNodos(int n){ // n es la cantidad de nodos que se van a agregar
	int valorNodo;
    for(int i = 0; i < n; i++){
        cout << "Dame el valor del nodo: ";
        cin >> valorNodo;
        cout << endl;
        vecNodos.push_back(valorNodo); // agrega el nodo al vector vecNodos
    }
}

// Recibe la lista adyacente, el vertice del grafo y sus vecinos
void Grafo::addEdgeAdjList(vector<vector<int>> &listAdj, int vertice, int adyacente) {
    if(listAdj.size() == 0) {
        // Se crean vectores vacios donde se guardaran los siguientes datos
        vector<int> vecLista; // corresponde a todos los nodos que existen

        // Nodos de la lista
        listAdj.push_back(vecLista);

        listAdj[0].push_back(vertice);
        listAdj[0].push_back(adyacente);
    } 
    else {
        int contador = 0;

        while(contador < listAdj.size()) {
            // Si existe el vertice en la lista de adyaciencia, mete el adyacente
            if(listAdj[contador][0] == vertice) {
                listAdj[contador].push_back(adyacente);
                break;
            }
            contador++;
        }
      	if (contador + 1 == listAdj.size()) {
            // Si no existe el vertice, crea el vector para el vertice y meto su adyacente
            vector<int> vecVertice;
            vecVertice.push_back(vertice);
            vecVertice.push_back(adyacente);
            listAdj.push_back(vecVertice);
        }
    }
}

void Grafo::loadGraph(int n, int m, vector<vector <int> > &listAdj){
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
        // busca en vecNodos el valor del vertice con el que se hara un arco

        // mientras el vertice o el adyacente no se encuentren en el grafo, se vuelven a pedir estos valores
        while((find(vecNodos.begin(), vecNodos.end(), ver) == vecNodos.end()) || (find(vecNodos.begin(), vecNodos.end(), adya) == vecNodos.end())){
            cout << "Has ingresado un valor que no es parte del grafo, intente de nuevo.";
            cout << "\nIngrese el vertice: ";
            cin >> ver;
            cout << endl;
            cout << "Ingrese el vertice adyacente: ";
            cin >> adya;
            cout << endl; 
        }

        // se llama a esta funcion para llenar la lista de adyacencias
        addEdgeAdjList(listAdj, ver, adya);
    }
}

void Grafo::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
  
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
  
    // Push current vertex to stack which stores result
    Stack.push(v);
}
  
// The function to do Topological Sort. It uses recursive
// topologicalSortUtil()
void Grafo::topologicalSort()
{
    stack<int> Stack;
  
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
  
    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
  
    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

// Función
int main()
{
    // Crear un grafo
    Grafo g(6);
    g.agregarVertice(5, 2);
    g.agregarVertice(5, 0);
    g.agregarVertice(4, 0);
    g.agregarVertice(4, 1);
    g.agregarVertice(2, 3);
    g.agregarVertice(3, 1);
  	

    cout << "Ordenamiento Topologico del grafo " << endl;

    // Llamar a la función
    g.ordenTopologico();

    return 0;
}
