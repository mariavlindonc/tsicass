#include <iostream>
#include"milibreria.h" 
using namespace std;


int main() {
    int opcion, cantprod = 0, cont;
    cout << "¿Cuántos productos desea cargar?" << endl;
    cin >> cantprod;
    Producto Lista[cantprod];
    cargar(cantprod, Lista);
    
    do {
        cout << "###---- Menú ---###" << endl;
        cout << "[1] Mostrar productos." << endl;
        cout << "[2] Ver productos con bajo stock." << endl;
        cout << "[3] Ver productos caros con mucho stock." << endl;
        cout << "----------------" << endl;

        do {
            cout << "Ingresar una opción válida: ";
            cin >> opcion;
        } while (opcion > 3 || opcion < 1);
        
        cout << endl;
        
        switch(opcion)
        {
            case 1:
                mostrar(cantprod, Lista);
                break;
            case 2:
                verBajoStock(cantprod, Lista);
                break;
            case 3:
                verSobrantes(cantprod, Lista);
                break;
            default:
                cout << "ERROR 001";
        }

        cout << endl;
        do {
            cout << "¿Desea continuar?" << endl << "1 para continuar, 2 para cerrar el programa." << endl;
            cin >> cont;
        } while (cont != 1 && cont != 2);
    } while (cont == 1);
}