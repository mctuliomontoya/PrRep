#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <set>

using namespace std;

class GrafoPuertos {
    private:
        vector<string> vecNodos;
        vector<vector<int>> listAdj;
        
        set<string> setNodos;
    public:
        void read(string arc);
        void addEdgeAdjList(string vertice, string adyacente);
        void imprimeListaAdj();
    	void agregarNodos(int cantidad);
        int findNodo(string nodo);
        int findListPos(int valor);
        int puertosRestantes(string inicio, int mnp);
        void visitarRecursivo(int posNodo, int mnp, vector<bool> &visitado);
        void loadGraph();
        void loadNodes(string arch);
        void setNodosArchivo(string arch);
        void createSetNodos(string arch);
        void cargarNodos();
        void printSetNodos();
};

void GrafoPuertos::read(string arch) { // Lee un archivo con nodo - adyacente y lo carga en el grafo.
    ifstream archivo;
    string linea;
    string vertice;
    string adyacente;
    int pos;
    archivo.open(arch);
    if(archivo.is_open()) {
        while(getline(archivo, linea)) {
            pos = linea.find(" ");
            vertice = linea.substr(0, pos);
            adyacente = linea.substr(pos+1, linea.length());
            addEdgeAdjList(vertice, adyacente);
        }
    }
    archivo.close();
}
void GrafoPuertos::cargarNodos() { // carga el contenido del set en el vector de nodos.
    set<string>::iterator it;
    for(it = setNodos.begin(); it != setNodos.end(); it++) {
        vecNodos.push_back(*it);
    }
}

void GrafoPuertos::printSetNodos() {
    set<string>::iterator it;
    for(it = setNodos.begin(); it != setNodos.end(); it++) {
        cout << *it << endl;
    }
}

void GrafoPuertos::createSetNodos(string arch) { //inserta nodos del archivo en un set
    ifstream archivo;
    string linea;
    string puerto, puerto2;
    int pos;
    archivo.open(arch);
    if(archivo.is_open()) {
        while(getline(archivo, linea)) {
            pos = linea.find(" ");
            puerto = linea.substr(0, pos);
            puerto2 = linea.substr(pos+1, linea.length());
            setNodos.insert(puerto);
            setNodos.insert(puerto2);
        }
    }

}

int GrafoPuertos::findNodo(string valor){
    int lugar = 0;
    while(lugar < vecNodos.size()){
        if(vecNodos[lugar] == valor){
            return lugar;
        }
        lugar++;
    }
    return -1;
}

int GrafoPuertos::findListPos(int valor){
    int posLista = 0;
    while(posLista < listAdj.size()){
        if(listAdj[posLista][0] == valor){
            break;
        }
        posLista++;
    }
    return posLista;
}

void GrafoPuertos::addEdgeAdjList(string vertice, string adyacente) {
    int posVerNodo = findNodo(vertice);
    int posAdjNodo = findNodo(adyacente);

    if(listAdj.size()==0){
        vector<int> vecLista;
        vector<int> vecListaAdj;
    	
        listAdj.push_back(vecLista);

        listAdj[0].push_back(posVerNodo);
        listAdj[0].push_back(posAdjNodo);

        listAdj.push_back(vecListaAdj);

        listAdj[1].push_back(posAdjNodo);
        listAdj[1].push_back(posVerNodo);

    } else {
        int cont = 0;
        bool foundVer = false;
        bool foundAdj = false;
        while((cont < listAdj.size()) && ((foundVer == false) || (foundAdj == false))){
            // Si existe el alguno lo agrego
            if(vecNodos[listAdj[cont][0]] == vertice){
                listAdj[cont].push_back(posAdjNodo);
                foundVer = true;
            }
            if(vecNodos[listAdj[cont][0]] == adyacente){
                listAdj[cont].push_back(posVerNodo);
                foundAdj = true;
            }
            cont++;
		}
        if(cont == listAdj.size() && ((foundVer == false) || (foundAdj == false))){
            // Si no encontro alguno busca cual falta
            vector<int> vecVertice;
            if(foundVer == foundAdj){ // No existe ninguno
                vector<int> vecAdj;
                vecAdj.push_back(posVerNodo);
                vecAdj.push_back(posAdjNodo);

                listAdj.push_back(vecAdj);

                vecVertice.push_back(posAdjNodo);
                vecVertice.push_back(posVerNodo);
            }
            else if(foundVer == false){ // No existe vertice
                vecVertice.push_back(posVerNodo);
                vecVertice.push_back(posAdjNodo); 
            } 
            else { // No existe adyacente
                vecVertice.push_back(posAdjNodo);
                vecVertice.push_back(posVerNodo); 
            }

            listAdj.push_back(vecVertice);
        }
    }
}

void GrafoPuertos::imprimeListaAdj(){
    for(int i = 0; i < listAdj.size(); i++){
        cout << vecNodos[listAdj[i][0]];
        for(int j = 1; j < listAdj[i].size(); j++){
            cout << "->" << vecNodos[listAdj[i][j]];
        }
        cout << endl;
    }
}

void GrafoPuertos::agregarNodos(int n){
	string valorNodo;
    vector<bool> linea;
    for(int i = 0; i < n; i++){
        cout << "Dame el valor del nodo " << i << ": ";
        cin >> valorNodo;
        vecNodos.push_back(valorNodo);
        linea.push_back(false);
    }
}

int GrafoPuertos::puertosRestantes(string inicio, int mnp){
    int puertosFaltantes = vecNodos.size();
    
    vector<bool> visitado(vecNodos.size(), false);

    int posInicio = findNodo(inicio);

    visitarRecursivo(posInicio, mnp, visitado);

    for(int i = 0; i < visitado.size(); i++){
        if(visitado[i] == true){
            puertosFaltantes--;
        }
    }

    return puertosFaltantes;
}

void GrafoPuertos::visitarRecursivo(int posNodo, int mnp, vector<bool> &visitado){
    visitado[posNodo] = true;
    if(mnp > 0){
        int posLista = findListPos(posNodo);
        for(int tam = 0; tam < listAdj[posLista].size(); tam++){
            visitarRecursivo(listAdj[posLista][tam], mnp-1, visitado);
        }
    }
}

void GrafoPuertos::loadGraph(){
    string arch = "puertos.txt";
    createSetNodos(arch);
    cargarNodos();
    printSetNodos();
    read("puertos.txt");
}

int main(){
    GrafoPuertos muelle;

    muelle.loadGraph();
    
    muelle.imprimeListaAdj();
    cout << "Restantes: " <<  muelle.puertosRestantes("c", 1);
    
    return 0;
}