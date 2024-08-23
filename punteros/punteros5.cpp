#include <iostream>
using namespace std;

int main()
{
    int a = 501; //se crea la variable a en la posición 1000 y se guarda el int 501 en ella
    int *p; //se crea el puntero p en la posición 1002, su contenido es null
    p = &a; //en la posición 1002, se guarda 1000 como contenido del puntero p
    *p = 5; //a traves del puntero se modifica el valor de a, el contenido de la posición 1000 pasa a ser 5
}