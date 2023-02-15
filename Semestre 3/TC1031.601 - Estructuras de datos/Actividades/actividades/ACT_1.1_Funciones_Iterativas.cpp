//Alumno: Marco Tulio Montoya
//Matrícula: A01254155
//Fecha: 21 de Agosto 2022
//Clase: TC1031.601
//Profesor: Baldomero Olvera Villanueva

#include <iostream> //Libreria para entrada y salida de datos
#include <cstdlib> //Libreria para usar funciones de la libreria estandar
using namespace std; //Libreria estandar

int sumaIterativa(int n) {  //Funcion para suma iterativa
    int count = 0; //Condicion inicial

    for (int i = 1; i < n+1; ++i) { //Ciclo para sumar los numeros del 1 al n
        count = count + i;

    }
    return count;
}

unsigned long sumaRecursiva(int n){ // Funcion para suma utilizando recursividad
    if(n < 0) //Si el numero es negativo, se retorna 0
        return 0;
    else 
        return n + sumaRecursiva(n - 1); //Si no, se retorna el numero mas la suma de los numeros anteriores
}

int sumaDirecta(int n){ // Funcion para suma directa
    return (n * (n + 1)) / 2; // Formula para suma directa
}

void menu(int n){ // Funcion para menu
    while (1 == 1){ 
    int eleccion; //Variable para eleccion de opcion
    cout << "Elige el metodo a utilizar: " << endl; //Menu de opciones
    cout << "[1] - Suma Iterativa. " << endl;
    cout << "[2] - Suma Recursiva. " << endl;
    cout << "[3] - Suma Directa. " << endl;
    cout << "[4] - Salir. " << endl;

    cin >> eleccion;
    
    switch(eleccion) { //Switch para eleccion de opcion
        case 1:  //Si la opcion es 1, se ejecuta la funcion suma iterativa
            cout << "La suma desde 1 hasta " << n << " por el metodo iterativo es: " << sumaIterativa(n) << endl;
            break;
        
        case 2: //Si la opcion es 2, se ejecuta la funcion suma recursiva
            cout << "La suma desde 1 hasta " << n << " por el metodo recursivo es: " << sumaRecursiva(n) << endl;
            break;
        case 3: //Si la opcion es 3, se ejecuta la funcion suma directa
            cout << "La suma desde 1 hasta " << n << " por el metodo directo es: " << sumaDirecta(n) << endl;
            break;
        case 4: //Si la opcion es 4, se sale del programa
            exit(EXIT_SUCCESS);
        default: //Si la opcion no es 1, 2, 3, 4, se muestra el menu de nuevo
            cout << "La opcion elegida esta fuera de los parametros."<< endl;
    }

}
}

int main(){ // Funcion principal
    int n;  //Variable para numero a sumar
    cout << "Ingresa un numero: "; //Pregunta para ingresar numero
    cin >> n; 
    if (n > 0) { //Si el numero es positivo, se ejecuta el menu
        menu(n);
    }
    else { //Si el numero es negativo, se muestra el mensaje de error
        cout << "El numero ingresado es negativo." << endl;
    }
    return 0;
}