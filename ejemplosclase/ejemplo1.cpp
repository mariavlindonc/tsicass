#include <iostream>
using namespace std;

struct Producto {
    string código;
    string descripcion;
    float precio;
    int stock;
};

void cargar(int n, Producto P[]) {
    for (int i = 0; i < n; i++)
    {
        cout << "Producto " << i + 1 << endl;
        cout << "Código: ";
        cin >> P[i].código;
        cout << "Descripción: ";
        cin >> P[i].descripcion;
        cout << "Precio: ";
        cin >> P[i].precio;
        cout << "Stock: ";
        cin >> P[i].stock;
        cout << endl;
    }
}

void mostrar(int n, Producto P[]) {
    for (int i = 0; i < n; i++)
    {
        cout << "Producto " << i + 1 << endl;
        cout << "Código: " << P[i].código << endl;
        cout << "Descripción: " << P[i].descripcion << endl;
        cout << "Precio: " << P[i].precio << endl;
        cout << "Stock: " << P[i].stock << endl;
        cout << endl;
    }  
}

void verBajoStock(int n, Producto P[]) {
    cout << "Productos con stock menor a 100..." << endl;
    for (int i = 0; i < n; i++)
    {
        if (P[i].stock < 100)
        {
            cout << "Producto " << i + 1 << endl;
            cout << "Código: " << P[i].código << endl;
            cout << "Descripción: " << P[i].descripcion << endl;
            cout << "Precio: " << P[i].precio << endl;
            cout << "Stock: " << P[i].stock << endl << endl;
        } 
    }
}

void verSobrantes(int n, Producto P[]) {
    cout << "Productos con stock mayor a 500 y precio mayor a 100..." << endl;
    for (int i = 0; i < n; i++)
    {
        if (P[i].stock > 500 && P[i].precio > 100)
        {
            cout << "Producto " << i + 1 << endl;
            cout << "Código: " << P[i].código << endl;
            cout << "Descripción: " << P[i].descripcion << endl;
            cout << "Precio: " << P[i].precio << endl;
            cout << "Stock: " << P[i].stock << endl << endl;
        }
    }
}

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