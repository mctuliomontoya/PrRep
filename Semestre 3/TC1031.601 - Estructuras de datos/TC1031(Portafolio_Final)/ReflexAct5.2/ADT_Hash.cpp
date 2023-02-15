#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

class Hash {
    private:
        int BUCKET; // número de buckets
        list<string> *table; // Lista de hash
        vector<string> arreglo;
        vector<int> valores;
        int funcionHash(int x) { // función de hash que calcula la posición en la tabla
            return (x % BUCKET);
        }  
    
    public:
        vector<string> parrafos;
        Hash(int V){ // Constructor
            BUCKET = V;
            table = new list<string>[BUCKET];
        }

        int getElemento(string key){
            int index = getASCII(key) % BUCKET;
            if(!table[index].empty()){
                if(table[index].front() == key){
                    return stoi(table[index].back());
                } else {
                    for(int i = 0; i < BUCKET; i++){
                        int t = (index + i * i) % BUCKET;
                        if(table[t].front() == key){
                            return stoi(table[t].back());
                        }
                    }
                    return 0;
                }
            } else {
                return 0;
            }
        }
        
        void quadratic(){
            for(int i = 0; i < arreglo.size(); i++){
                int hb = getASCII(arreglo[i]) % BUCKET;
                if(table[hb].empty()){
                    table[hb].push_back(arreglo[i]);
                    table[hb].push_back(to_string(valores[i]));
                } 
                else {
                    for(int x = 0; x < BUCKET; x++){
                        int t = (hb + x * x) % BUCKET;
                        if(table[t].empty()){
                            table[t].push_back(arreglo[i]);
                            table[t].push_back(to_string(valores[i]));
                            break;
                        }
                    }
                }
            }
        }
        
        int getASCII(string palabra){
            int sumaASCII = 0;
            for(int s = 0; s < palabra.size(); s++){
                sumaASCII += int(palabra[s]);
            }
            return sumaASCII;
        }

        void readData() { 
            int n, tests, num;
            string key;
            ifstream myFile("data.txt");
            if(myFile.is_open()) {
                myFile >> n >> tests;
                // se le por fila los valores de las llaves y los valores, almacenando llaves en un vector y valores en otro
                for(int i = 0; i < n; i++){
                    myFile >> key >> num;
                    arreglo.push_back(key);
                    valores.push_back(num);
                }
                // se crea un string que almacena las lineas hasta encontrar un "." y despues lo manda como un tesst case
                string line;
                for (int p = 0; p < tests; p++){
                    string test_case = "";
                    while(getline(myFile, line) && line != "."){
                        test_case += line + " ";
                    }
                    parrafos.push_back(test_case);
                }
                myFile.close(); 
            }
        }

        int getSalario(string parrafo){
            int sumaSalario = 0;
            string palabra;
            
            stringstream iss(parrafo);

            while(iss >> palabra){
                sumaSalario += getElemento(palabra);
            }

            return sumaSalario;
        }
};

int main(){
    Hash diccionario(7);
    
    diccionario.readData();
    diccionario.quadratic();

    for(int tam = 0; tam < diccionario.parrafos.size(); tam++){
        cout << diccionario.getSalario(diccionario.parrafos[tam]) << endl;
    }

    return 0;
}