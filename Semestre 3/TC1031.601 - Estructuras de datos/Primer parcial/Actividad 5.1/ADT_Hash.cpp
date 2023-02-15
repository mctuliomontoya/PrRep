#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

class Hash
{
    public:
        int BUCKET; // número de buckets
        // apuntador a la lista que contiene los buckets
        list<string> *table;

        Hash(int V){ // Constructor
            BUCKET = V;
            table = new list<string>[BUCKET];
        }

        //Insertar un elemento en la tabla
        void insertaElemento(int key, string value){
            int index = funcionHash(key);
            table[index].push_back(to_string(key));
            table[index].push_back(value);
        }

        string getElemento(int key){
            int index = funcionHash(key);
            if(!table[index].empty()){
                return table[index].back();
            } else {
                return "No existe";
            }
        }
        
        void quadratic(int arr[], int N, string val[]){
            for(int i = 0; i < N; i++){
                int hb = arr[i] % BUCKET;
                if(table[hb].empty()){
                    table[hb].push_back(to_string(arr[i]));
                    table[hb].push_back(val[i]);
                } 
                else {
                    for(int x = 0; x < BUCKET; x++){
                        int t = (hb + x * x) % BUCKET;
                        if(table[t].empty()){
                            table[t].push_back(to_string(arr[i]));
                            table[t].push_back(val[i]);
                            break;
                        }
                    }
                }
            }
            
            cout << "Quadratic HashMap" << endl;
            for(int i = 0; i < BUCKET; i++){
                cout << i << " ->  ";
                if(!table[i].empty()){
                    cout << table[i].front() << ", " << table[i].back();
                }
                cout << endl;
            }
        }

        void chain(int arr[], int N, string val[]){
            for(int i = 0; i < N; i++){
                insertaElemento(arr[i], val[i]);
            }

            cout << "Chain HashMap" << endl;
            for(int x = 0; x < BUCKET; x++){
                cout << x << " ->  ";
                for(auto s : table[x]){
                    cout << s << ", ";
                }
                cout << endl;
            }
        }
    
	private:
        // función de hash que calcula la posición en la tabla
        int funcionHash(int x) {
            return (x % BUCKET);
        }    
};

int main(){
    Hash mapa(10);
    // mapa.insertaElemento(9, 10);
    // mapa.insertaElemento(13, 15);
    // cout << mapa.getElemento(9) << endl;
    // cout << mapa.getElemento(13) << endl;
    // cout << mapa.getElemento(5) << endl;
    int arreglo[] = {23, 34, 20, 7};
    string valores[] = {"valor1", "valor2", "valor3", "valor4"};
    mapa.quadratic(arreglo, 4, valores);
    // mapa.chain(arreglo, 4, valores);

    return 0;
}
