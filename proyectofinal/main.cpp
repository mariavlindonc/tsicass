#include "tablero.h"
#include <iostream>
using namespace std;

void codigo_error(int e);

int main(){
    Tablero TP;
    Barcos b;
    int t, x, y, p, bar;

    do
    {
        cout<< "Elija el tablero: Ingrese el numero correspondiente";
        cout<< "\n 1 = 10x10";
        cout<< "\n 2 = 12x12";
        cout<< "\n 3 = 15x15";
        cin>> t;
        if (t < 1 || t > 3)
        {
            codigo_error(1);
        }
    } while (t < 1 || t > 3);
    
    TP.setTam(t);
    
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
    M.iniciarBarcos(B1);

    return 0;
}

void codigo_error(int e)
{
    switch (e)
    {
        case 1:
            cout << "ERROR 01.";
            cout << "Input inválido, reingresar.";
            break;
        default:
            cout << "ERROR NO IDENTIFICADO.";
            break;
    }
}