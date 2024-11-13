#include "tablero.h"
#include <iostream>
using namespace std;
 
int main(){
    Tablero TP;
    Barcos b;
    int t, x, y, p, bar;

    cout<< "Elija el tablero: Ingrese el numero correspondiente";
    cout<< "\n 1 = 10x10";
    cout<< "\n 2 = 12x12";
    cout<< "\n 3 = 15x15";
    cin>> t;
    TP.setTam(t);
    TP.getTam();
    
    int tamBarco;
    cout << "Ingrese el tamaño del barco: ";
    cin >> tamBarco;
    b.setTam(tamBarco);

    int l=4;
    b.setLar(l);
    cout<< "Ingrese 1 si desea que el barco se encuentre de manera vertical. \n Ingrese 2 si desea que este horizontal";
    cin>> p;
    b.setPos(p);

    cout<< "\n Ingrese una de las coordenadas del barco";
    cin>> x;
    cin>> y;
    b.setCoo(x, y);
    b.ubicarBarco(b.getTam());  

    Maquina M;
    //CODIGO ABAJO ES PARA UBICAR CADA BARCO DE LA MAQUINA (REPETIR POR CADA BARCO)
    Barcos B1;
    B1.setLar(4);
    M.iniciarBarcos(B1, TP.getTam());

    return 0;
}