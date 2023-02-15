// Code made by: Marco Tulio Montoya - A01254155

#include <iostream>
#include <fstream>

using namespace std;

#define MAX 50

class Queue {
	private:
		int datos[MAX];
		int frente, final;
	public:
		Queue() {
			frente = -1;
			final = -1;
		}
		void push(int valor) {
			final = (final+1) % MAX;
			datos[final] = valor;
			if (frente == -1) {
				frente++;
			}
		}

		int pop() {
			int valor = datos[frente];
			if (frente == final)
				frente = final = -1;
			else
				frente = (frente+1) % MAX;
			return valor;
		}

		int front() {
			return datos[frente];
		}
		bool isEmpty(){
			return(frente == -1);
		}
		bool isFull() {
			return ((final +1) % MAX == frente);
		}

};