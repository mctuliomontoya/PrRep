#include <iostream>
#include <fstream>
using namespace std;

// void ejercicio1(){
//     int a = 1, b = 2;
//     int *p = *q = &b;
//     *q++;
//     cout << b << " " << a << endl;
// }

void ejercicio2(){
    int a=1, b=2, *p, *q;
    p = &a;
    q = &b;
    (*q)++;
    cout << b << " " << a << endl;
}

void ejercicio3(){
    int a=10, b=20, *p, *q;
    p = &a;
    q = p;
    *q+=30;
    cout << *p << " " << *q << endl;
}

void ejercicio4(){
    int a=10, b=20, *p, *q;
    p = new int(5);
    q = &a;
    *q+=30;
    cout << *p << " " << *q << " " << a << " " << b << endl;
}

void ejercicio5(){
    int a=10, b=20, *p, *q;
    p = new int(5);
    q = p;
    *q+=30;
    cout << *p << " " << *q << " " << a << " " << b << endl;
}

void ejercicio6(){
    int a=10, b=20, *p, *q;
    p = new int(5);
    q = new int(10);
    *q += 30;
    b = *q + *p;
    cout << *p << " " << *q << " " << a << " " << b << endl;
    delete q;
    delete p;
}

void ejercicio7(){
    int a=10, b=20, *p, *q;
    p = new int(15);
    q = &b;
    *q+=30;
    cout << *p << " " << *q << " " << a << " " << b << endl;
    delete p;
}

void ejercicio8(){
    int a=8, b=17, *p, *q;
    p = &a;
    q = new int(10);
    *q+=a;
    cout << *p << " " << *q << " " << a << " " << b << endl;
    delete q;
}

int main(){
    // ejercicio1();
    ejercicio2();
    ejercicio3();
    ejercicio4();
    ejercicio5();
    ejercicio6();
    ejercicio7();
    ejercicio8();
    
    return 0;
}