#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>

using namespace std;

class GrafoPuertos {
    private:
        vector<string> vecNodos;
        vector<vector<int>> listAdj;
        unordered_set<string> setNodos;
    public:
        void testFile(string arc);
        void addEdgeAdjList(string vertice, string adyacente);
        void imprimeListaAdj();
        int findNodo(string nodo);
        int findListPos(int valor);
        int puertosRestantes(string inicio, int mnp);
        void visitarRecursivo(int posNodo, int mnp, vector<bool> &visitado);
};

void GrafoPuertos::testFile(string arch) { // Lee un archivo con nodo - adyacente, lo carga en el grafo y hace casos de prueba.
    ifstream archivo;
    string linea, vertice, adyacente, puerto, mnp;
    int pos, num, mnpInt;
    archivo.open(arch);
    if(archivo.is_open()) {
        getline(archivo, linea);
        num = stoi(linea);
        for(int i = 0; i < num; i++){
            getline(archivo, linea);
            pos = linea.find(" ");
            vertice = linea.substr(0, pos);
            adyacente = linea.substr(pos+1, linea.length());
            if(setNodos.find(vertice) == setNodos.end()){ // No existe vertice
                vecNodos.push_back(vertice);
                setNodos.insert(vertice);
            }
            if(setNodos.find(adyacente) == setNodos.end()){ // No existe adyacente
                vecNodos.push_back(adyacente);
                setNodos.insert(adyacente);
            }
            addEdgeAdjList(vertice, adyacente);
        }

        getline(archivo, linea);
        num = stoi(linea);
        for(int x = 0; x < num; x++){
            getline(archivo, linea);
            pos = linea.find(" ");
            puerto = linea.substr(0, pos);
            mnp = linea.substr(pos+1, linea.length());
            mnpInt = stoi(mnp);
            cout << "Case " << x+1 << ": " << puertosRestantes(puerto, mnpInt) << " ports not reachable from port "  << puerto << " with MNP = " << mnp << "." << endl;
        }
    }
    archivo.close();
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

int GrafoPuertos::puertosRestantes(string inicio, int mnp){
    vector<bool> visitado(vecNodos.size(), false);
    
    int puertosFaltantes = vecNodos.size();
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

int main(){
    GrafoPuertos muelle;

    muelle.testFile("entrada.txt");

    return 0;
}