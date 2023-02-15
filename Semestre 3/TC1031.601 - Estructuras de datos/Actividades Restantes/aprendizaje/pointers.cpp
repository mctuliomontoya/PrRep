#include <iostream>

using namespace std;

int main()
{
    int a= 1, b = 2, *p, *q;
    *p = *q = &b;
    *q++;
    cout << b << " " << a << endl;
    return 0;

    int a = 1, b = 2, *p, *q;
    p = &a;
    q = &b;
    cout << b << " " << a << endl;

    int a = 10, b = 20, *p, *q;
    p = &a;
    q = p;
    *p+=30;
    cout << *p << " " << *q << endl;

    int a = 10, b = 20, *p, *q;
    p = new int(5);
    q = &a;
    *q+=30;
    cout << *p << " " << *q << " " << a << " " << b << endl;
    delete p;

    int a = 10, b = 20, *p, *q;
    p = new int(5);
    q = p;
    *q+= 30;
    cout << *p << " " << *q << " " << a << " " << b << endl;
    delete q;

    int a = 10, b = 20, *p, *q;
    p = new int(5);
    q = new int(10);
    *q+= 30;
    b = *q + *p;
    cout << *p << " " << *q << " " << a << " " << b << endl;
    delete p;
    delete q;

    int a = 10, b = 20, *p, *q;
    p = new int(15);
    q = &b;
    *q+= 30;
    cout << *p << " " << *q << " " << a << " " << b << endl;
    delete p;

    int a = 8, b = 17, *p, *q;
    p = &a;
    q = new int (10);
    *q+=a;
    cout << *p << " " << *q << " " << a << " " << b << endl;
    delete q;
}