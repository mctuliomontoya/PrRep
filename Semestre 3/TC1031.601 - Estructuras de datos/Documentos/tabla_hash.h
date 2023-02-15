#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

class Hash
{
    private:
        int funcionHash(int key){
            return key % BUCKET;
        }

    public:
        int BUCKET; // número de buckets

        list<string> *table;

        Hash(int v) { // Constructor
            BUCKET = v;
            table = new list<string>[BUCKET];
        }

        string getElemento(int key);
        void quadratic(int arr[], int N, string val[]);
        void chaining(int arr[], int N, string val[]);
};


string Hash::getElemento(int key){
    int index = funcionHash(key);
    if(!table[index].empty()){
        return table[index].back();
    } else {
        return "No existe";
    }
}

void Hash::quadratic(int arr[], int N, string val[]){
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

void Hash::chaining(int arr[], int N, string val[]){
    for(int i = 0; i < N; i++){
        int hb = arr[i] % BUCKET;
        if(table[hb].empty()){
            table[hb].push_back(to_string(arr[i]));
            table[hb].push_back(val[i]);
        } 
        else {
            for(int x = 0; x < BUCKET; x++){
                int t = (hb + x) % BUCKET;
                if(table[t].empty()){
                    table[t].push_back(to_string(arr[i]));
                    table[t].push_back(val[i]);
                    break;
                }
            }
        }
    }
    
    cout << "Chaining HashMap" << endl;
    for(int i = 0; i < BUCKET; i++){
        cout << i << " ->  ";
        if(!table[i].empty()){
            cout << table[i].front() << ", " << table[i].back();
        }
        cout << endl;
    }
}

