#include <iostream>
using namespace std;

int main()
{
    float *p; // se crea el puntero p de tipo float en la posición 1000, su contenido es null
    float f1 = 0.2; // se crea la variable f1 de tipo float en la posición 1004, su contenido es 0.2
    float f2 = 0.5; // se crea la variable f2 de tipo float en la posición 1008, su contenido es 0.5
    int *q; // se crea el puntero q de tipo int en la posición 1012, su contenido es null
    int i1 = 2; // se crea la variable i1 de tipo int en la posición 1014, su contenido es 2
    int i2 = 6; // se crea la variable i2 de tipo int en la posición 1016, su contenido es 6
    p = &f1; // en la posición 1000, se guarda la posición de f1 (1004) como contenido de p
    q = &i1; // en la posición 1012, se guarda la posición de i1 (1014) como contenido de q
    cout << *p << " " << *q << endl; //se imprime el contenido de la dirección guardada en p (0.2) y el de la dirección guardada en q (2)
    p = &f2; // en la posición 1000, se guarda la posición de f2 (1008) como contenido de p
    q = &i2; // en la posición 1012, se guarda la posición de i2 (1016) como contenido de q
    cout << *p << " " << *q << endl; //se imprime el contenido de la dirección guardada en p (0.5) y el de la dirección guardada en q (6)
}