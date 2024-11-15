#include "tablero.h"
#include <iostream>
using namespace std;

void codigo_error(int e);

int main(){
    Partida P;
    int t, p, y, x;

    do
    {
        cout<< "Elija el tablero: Ingrese el numero correspondiente" << endl;
        cout<< "1 = 10x10" << endl;
        cout<< "2 = 12x12" << endl;
        cout<< "3 = 15x15" << endl;
        cin>> t;
        if (t < 1 || t > 3)
        {
            codigo_error(1);
        }
    } while (t < 1 || t > 3);
    
    P.M.iniciarBarcos();

    for (int i = 0; i < 9; i++)
    {
        bool exito;
        P.U.getTP().mostrarTab();
        cout << "Ubique los barcos en el tablero." << endl;
        do
        {
            cout << "Ubicando barco de " << P.U.getBar(i).getLar() << " espacios de largo." << endl;
            cout << "Indique la orientación del barco." << endl;
            cout << "[1] Vertical" << endl;
            cout << "[2] Horizontal" << endl;
            cin >> p;
            P.U.getBar(i).setPos(p);
            cout << "El barco se orientara desde la posición inicial hacia abajo, o hacia arriba, según la orientación." << endl;
            cout << "Ingrese la coordenada y (fila) de la posición inicial" << endl;
            cin >> y;
            cout << "Ingrese la coordenada x (columna) de la posición inicial" <<endl;
            cin >> x;
            P.U.getBar(i).setCoo(y, x);
            if (P.U.getBar(i).ubicarBarco(P.U.getTP()))
            {
                cout << "Barco ubicado con éxito!" << endl;
                exito = true;
            }
            else
            {
                cout << "Posición no válida. Intente de nuevo." << endl;
                exito = false;
            }
            P.U.getTP().mostrarTab();
        } while (!exito);   
    }

    do
    {
        P.siguienteTur();
        cout << "-----------------------------------------" << endl;
        if (P.turno == 0)
        {
            cout << "Es turno del usuario." << endl << endl;
            cout << "TABLERO PROPIO" << endl;
            P.U.getTP().mostrarTab();
            cout << endl;
            cout << "TABLERO DEL RIVAL" << endl;
            P.U.getTR().mostrarTab();
            
            cout << "Ingrese la coordenada y (filas) de su tiro" << endl;
            cin >> y; 
            cout << "Ingrese la coordenada x (columnas) de su tiro" << endl;
            cin >> x;
            
            switch (P.U.tiro(y, x, P.M))
            {
                case -1:
                    cout << "Agua!" << endl;
                    break;
                case -2:
                    cout << "Barco ya tocado/hundido, pierde el turno." << endl;
                    break;
                case -3:
                    cout << "Barco tocado." << endl;
                    break;
                case -4:
                    cout << "Barco hundido!" << endl;
                    break;
                default:
                    codigo_error(4);
            }
            
        } else {
            cout << "Es turno de la máquina. Espere." << endl;
            
            switch (P.M.tiro(P.U))
            {
                case -1:
                    cout << "Agua!" << endl;
                    break;
                case -3:
                    cout << "Barco tocado." << endl;
                    break;
                case -4:
                    cout << "Barco hundido!" << endl;
                    break;
                default:
                    codigo_error(4);
            }
        }

        cout << "TABLERO PROPIO" << endl;
        P.U.getTP().mostrarTab();
        cout << endl;
        cout << "TABLERO DEL RIVAL" << endl;
        P.U.getTR().mostrarTab();

    } while (!P.checkGanador());
    
    cout << endl << "Ha terminado la partida!" << endl << endl;
    cout << "TABLERO DEL JUGADOR (PROPIO)" << endl;
    P.U.getTP().mostrarTab();
    cout << endl << "TABLERO DE LA MÁQUINA (PROPIO)" << endl;
    P.M.getTP().mostrarTab();
    cout << endl;

    if (P.empate)
    {
        cout << "Ha habido un empate!" << endl;
    }
    else if (P.ganador == 'u')
    {
        cout << "Ganaste! Felicitaciones!" << endl;
    }
    else
    {
        cout << "Ha ganado la máquina. Más suerte la próxima!" << endl;
    }
    
    cout << "Gracias por jugar.";
    return 0;
}

void codigo_error(int e)
{
    switch (e)
    {
        case 1:
            cout << "ERROR 01." << endl; 
            cout << "Input inválido, reingresar." << endl;
            break;
        case 4:
            cout << "ERROR 04." << endl;
            cout << "Error en la función tiro." << endl;
            break;
        default:
            cout << "ERROR NO IDENTIFICADO." << endl;
            break;
    }
}