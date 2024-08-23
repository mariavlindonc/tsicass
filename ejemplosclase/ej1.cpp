#include <iostream>
using namespace std;

int main()
{
    int n1, n2, acum = 0;
    do {
        cout << "Ingrese un número entero: ";
        cin >> n1;
        cout << "Ingrese un número entero: ";
        cin >> n2;
        acum += (n1 + n2);
    } while (n1 + n2 >= 0);
    cout << "Acumulado: " << acum;
}