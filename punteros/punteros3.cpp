#include <iostream>
using namespace std;

int main()
{
    int *p, a = 1;
    p = &a;
    cout << "Se puede imprimir la dirección (contenido del puntero)..." << endl;
    cout << p << endl;
    cout << "... y se puede imprimir el contenido de la dirección a la que apunta el puntero." << endl;
    cout << *p << endl;
}