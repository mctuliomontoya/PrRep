#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

void intercambiarLineas(vector<string> &vect, int pos1, int pos2){
    // pos1 y pos2 necesitan ser el comienzo de la "linea"
    string temp [4];
    for(int i = 0; i < 4; i++){
        temp[i] = vect[pos1+i];
    }
    for(int j = 0; j < 4; j++){
        vect[pos1+j] = vect[pos2+j];
    }
    for(int k = 0; k < 4; k++){
        vect[pos2+k] = temp[k];
    }    
}

void unir(vector<string> &vect, int inicio, int mitad, int fin){
    int i = inicio;
    int j = mitad+1;
    int k = 0;
    string aux [(fin-inicio+1)*4];
    while((i <= mitad) && (j <= fin)){
        if(vect[(i*4)+3] <= vect[(j*4)+3]){
            for(int r = 0; r < 4; r++){  // Guardar los 4 elementos
                aux[(k*4)+r] = vect[(i*4)+r];
            }
            i++;
        } else {
            for(int r = 0; r < 4; r++){  // Guardar los 4 elementos
                aux[(k*4)+r] = vect[(j*4)+r];
            }
            j++;
        }
        k++;
    }
    while(i <= mitad){
        for(int r = 0; r < 4; r++){  // Guardar los 4 elementos
            aux[(k*4)+r] = vect[(i*4)+r];
        }
        k++;
        i++;
    }
    while(j <= fin){
        for(int r = 0; r < 4; r++){  // Guardar los 4 elementos
            aux[(k*4)+r] = vect[(j*4)+r];
        }
        k++;
        j++;
    }
    for(i = inicio; i <= fin; i++){
        for(int r = 0; r < 4; r++){  // Guardar los 4 elementos
            vect[(i*4)+r] = aux[((i-inicio)*4)+r];
        }
    }
}

void mergeSort(vector<string> &vect, int inicio, int fin){
    int mitad;
    if(inicio < fin){
        mitad = (inicio + fin) / 2;
        mergeSort(vect, inicio, mitad);
        mergeSort(vect, mitad+1, fin);
        unir(vect, inicio, mitad, fin);
    }
}

int compararUBI(string ubi, string str){
    string maxCHARS = "}}";
    string minCHARS = "!!";
    string comparator1 = ubi;
    string comparator2 = ubi;
    comparator1.append(maxCHARS);
    comparator2.append(minCHARS);
    if((str.compare(comparator2) > 0) && (str.compare(comparator1) < 0)){
        return 0;
    } else {
        return str.compare(comparator2);
    }
}

int busquedaBinaria(vector<string> &vect, string UBI){
    int low = 0;
    int high = 2195;
    while(low <= high){
        int mid = (low + (high - low) / 2);
        if(compararUBI(UBI, vect[(mid*4)+3]) == 1){
            high = mid - 1;
        } else if(compararUBI(UBI, vect[(mid*4)+3]) == -1){
            low = mid + 1;
        } else {
            while((mid > 0) && (compararUBI(UBI, vect[((mid-1)*4)+3]) == 0)){
                mid--;
            }
            return mid;
        }
    }
    return -1;
}

int main(){
    vector<string> registros;
    string basura, linea, UBI;
    int inicio;
    int resultados = 1;
    ifstream miArchivo("bitacora.txt");

    // Guardar elementos en vector
    if(miArchivo.is_open()){
        for(int i = 0; i < 4; i++){  //Quitar renglones innecesarios
            miArchivo >> basura;
        }
        
        for(int i = 0; i < 8784; i++){
            miArchivo >> linea;
            registros.push_back(linea);
        }
        miArchivo.close();
    } else {
        cout << "No se puede abrir el archivo" << endl;
    }

    // Pedir UBI
    cout << "Ingrese la serie de 3 digitos que desee buscar: ";
    cin >> UBI;

    // Ordenar registros
    mergeSort(registros, 0, 2195);

    // Buscar primer registro con la serie
    inicio = busquedaBinaria(registros, UBI);

    // Mostrar resultados
    if(inicio != -1){
        cout  << endl << "RESULTADOS:" << endl << endl;;
        while(compararUBI(UBI, registros[(inicio*4)+3]) == 0){
            cout << resultados << " | " << registros[(inicio*4)] << " " << registros[(inicio*4)+1] << " " 
            << registros[(inicio*4)+2] << " " << registros[(inicio*4)+3] << endl;
            inicio++;
            resultados++;
        }
    } else {
        cout << "No se encontraron registros con esa serie." << endl;
    }
    return 0;
}