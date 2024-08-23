#include <iostream>
using namespace std;

int main()
{
    int x1 = 50; 
    // se crea la variable x1 de tipo int en la posición 1000, su contenido es 50
    int x2 = 100; 
    // se crea la variable x2 de tipo int en la posición 1002, su contenido es 100
    int *pun1, *pun2; 
    // se crea el puntero pun1 de tipo int en la posición 1004 (su contenido es null) 
    // se crea el puntero pun2 de tipo int en la posición 1006 (su contenido es null)
    pun1 = &x1;
    // en la posición 1004, se guarda la posición de x1 (1000) como contenido de pun1
    pun2 = pun1;
    // en la posición 1006, se guarda el contenido de pun1 (1000) como contenido de pun2
    *pun1 = 2000;
    //a traves del puntero pun1 se modifica el valor de x1, el contenido de la posición 1000 pasa a ser 2000
    //por tanto, el *pun2 será igual a 2000 también
    pun2 = &x2;
    // en la posición 1006, se guarda la posición de x2 (1002) como contenido de pun2
    x1 = 1;
    // el contenido de la posición 1000 pasa a ser 1
    x2 = 2;
    // el contenido de la posición 1002 pasa a ser 2
    *pun1 = 500;
    //a traves del puntero pun1 se modifica el valor de x1, el contenido de la posición 1000 pasa a ser 500
    *pun2 = 600;
    //a traves del puntero pun2 se modifica el valor de x2, el contenido de la posición 1002 pasa a ser 600
    return 0; 
}