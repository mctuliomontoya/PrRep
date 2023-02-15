#include "ListaLigada.h"
#include <fstream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <cstdlib>

int main(){
    LinkedList *listaMRojo = new LinkedList();
    LinkedList *listaMMedi = new LinkedList();
    string arch, serie;

    cout << "Ingrese el nombre del archivo: ";
    cin >> arch;

    ifstream miArchivo(arch);

    // Guardar elementos en lista ligada
    if(miArchivo.is_open()){
        string basura, fecha, hora, puntoEntrada, UBI;
        for(int i = 0; i < 4; i++){  //Quitar renglones innecesarios
            miArchivo >> basura;
        }
        
        for(int i = 0; i < 2196; i++){ // 2196¿
            miArchivo >> fecha;
            miArchivo >> hora;
            miArchivo >> puntoEntrada;
            miArchivo >> UBI;
            if(puntoEntrada == "M"){
                listaMMedi->insertarFinal(fecha, hora, puntoEntrada, UBI);
            } else {
                listaMRojo->insertarFinal(fecha, hora, puntoEntrada, UBI);
            }
        }
        miArchivo.close();
    } else {
        system("cls");
        cerr << "No se puede abrir el archivo o el archivo no existe." << endl;
        return 0;
    }
    system("cls");

    cout << "Ingrese 3 digitos de UBI: ";
    cin >> serie;

    listaMRojo->mergeSort(); // Ordenar rojo
    int contadorRojo[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    listaMRojo->contadorMesesUBI(serie, contadorRojo);

    listaMMedi->mergeSort(); // Ordenar mediterraneo
    int contadorMedi[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    listaMMedi->contadorMesesUBI(serie, contadorMedi);

    string meses[12] = {"Ene", "Feb", "Mar", "Abr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"};  // Diccionario de meses
    cout << "Contador M-R " << serie << ":" << endl;
    for(int i = 0; i < 12; i++){ // Imprimir meses con contadores
        cout << meses[i] << " 20  " << contadorMedi[i] << " " << contadorRojo[i] << endl;
    }
    return 0;
}