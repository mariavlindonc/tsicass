#include "tablero.h"
#include<iostream>
using namespace std;

int main(){
    tablero TP;
    barcos b;
    int t, x, y, p, bar;
    cout<< "Elija el tablero: Ingrese el numero correspondiente";
    cout<< "\n 1=10x10";
    cout<< "\n 2=12x12";
    cout<< "\n 3=15x15";
    cin>> t;
    TP.settam(t);
    TP.gettam();
    int l=4;
    b.setlargo(l);
    cout<< "Ingrese 1 si desea que el barco se encuentre de manera vertical. \n Ingrese 2 si desea que este horizontal";
    cin>> p;
    b.setpos(p);
    cout<< "\n Ingrese una de las coordenadas del barco";
    cin>> x;
    cin>> y;
    b.setcoor(x, y);
    b.ubicarBarco(b.gettam());                                                                                                                                                                                                                                                                                                                                            
    maquina M;
    //CODIGO ABAJO ES PARA UBICAR CADA BARCO DE LA MAQUINA (REPETIR POR CADA BARCO)
    barcos B1;
    B1.setlargo(4);
    M.iniciarBarcos(B1,t);
}