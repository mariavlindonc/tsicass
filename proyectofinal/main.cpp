#include "tablero.h"
#include <iostream>
using namespace std;

void codigo_error(int e);

int main(){
    Partida P;
    P.U.setNom("guest");
    P.U.setPun(0);
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
    
    P.U.getTP().elegirTam(t);
    P.U.getTR().elegirTam(t);
    P.M.getTP().elegirTam(t);
    P.M.getTR().elegirTam(t);

    P.U.iniciar();
    P.M.iniciar();
    srand(static_cast<unsigned>(time(0)));
    P.M.iniciarBarcos();

    for (int i = 0; i < CAN_BAR; i++)
    {
        bool exito;
        P.U.getTP().mostrarTab();
        cout << "Ubique los barcos en el tablero." << endl;
        do
        {
            cout << "Ubicando barco de " << P.U.getBar(i).getLar() << " espacios de largo." << endl;
            cout << "Indique la orientación del barco." << endl;
            do {
                cout << "[1] Vertical" << endl;
                cout << "[2] Horizontal" << endl;
                cin >> p;
                if (p != 1 && p != 2) {
                    codigo_error(3);
                }
            } while (p != 1 && p != 2);
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
                case AGUA:
                    cout << "Agua!" << endl;
                    break;
                case YA_TOCADO:
                    cout << "Barco ya tocado/hundido, pierde el turno." << endl;
                    break;
                case TOCADO:
                    cout << "Barco tocado." << endl;
                    break;
                case HUNDIDO:
                    cout << "Barco hundido!" << endl;
                    break;
                default:
                    codigo_error(4);
            }
            
        } else {
            cout << "Es turno de la máquina. Espere." << endl;
            
            switch (P.M.tiro(P.U))
            {
                case AGUA:
                    cout << "Agua!" << endl;
                    break;
                case TOCADO:
                    cout << "Barco tocado." << endl;
                    break;
                case HUNDIDO:
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
    else if (P.ganador == 0)
    {
        cout << "Ganaste! Felicitaciones!" << endl;
        P.U.aumentarPuntaje(100);
    }
    else
    {
        cout << "Ha ganado la máquina. Más suerte la próxima!" << endl;
        P.U.aumentarPuntaje(-50);
    }
    cout << endl;
}

void codigo_error(int e)
{
    switch (e)
    {
        case 1:
            cout << "ERROR 01. Input inválido, reingresar." << endl; 
            break;
        case 3:
            cout << "ERROR 03. Orientación inválida! Reingresar." << endl;
            break;
        case 4:
            cout << "ERROR 04. Error en la función tiro." << endl;
            break;
        default:
            cout << "ERROR NO IDENTIFICADO." << endl;
            break;
    }
}