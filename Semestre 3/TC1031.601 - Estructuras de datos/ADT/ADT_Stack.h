#include <iostream>

using namespace std;

#define MAX 50

class Stack {
    private:
        int datos[MAX];
        int top = -1;
    public:
        Stack() {
            top = -1;
        }

        bool push (int valor) {
            if(isFull())
                return false;
            else {
                top ++;
                datos[top] = valor;
                return true;
            }
        }

        int getTop() {
            return datos[top];
        }

        int pop() {
            if(isEmpty())
                return false;
            else{
                top--;
                return true;
            }
        }

        bool isEmpty() {
            if(top== - 1)
                return true;
            else    
                return false;
        }

        bool isFull() {
            if(top== MAX-1)
                return true;
            else    
                return false;
        }
};