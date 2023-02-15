#include <iostream>

using namespace std;

void intercambia (int *a, int*b) {
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}



int main() {
	int z = 10;
	int w = 20;

	cout << "Variables antes del intercambio, z: " << z << " w: " << w << endl;
	intercambia(&z, &w);
	cout << "Variables despues del intercambio, z: " << z << " w: " << w << endl;

	int a = 5, *p;
	p = new int;
	*p = a;
	a = *p+2;
	cout << a << " " << *p <<endl;
	delete p;

	return 0;
}