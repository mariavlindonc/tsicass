#include <iostream>
using namespace std;

int suma_pos(int sumanp[100], int n)
{
    int total = 0;
    for (int j = 0; j < n; j++)
    {
        if (sumanp[j] > 0)
        {
            total += sumanp[j];
        }
    }
    return total;
}

int suma_neg(int sumann[100], int n)
{
    int difer = 0;
    for (int k = 0; k < n; k++)
    {
        if (sumann[k] < 0)
        {
            difer += sumann[k];
        }
    }
    return difer;
}

float prom(int valores[100], int n)
{
    int promedio = 0;
    for (int l = 0; l < n; l++)
    {
        promedio += valores[l];
    }
    promedio /= n;
    return promedio;
}

int main()
{
    bool cont;
    int num[100];
    int n, i = 0;
    cout << "Cantidad de números: ";
    cin >> n;
    do
    {
        cout << "Ingresar nota: ";
        cin >> num[i];
        i++;
        cout << "Continuar? (true/false)";
        cin >> cont;
    } while (cont);
    
    cout << "La suma de los positivos es " << suma_pos(num, i) << endl;
    cout << "La suma de los negativos es " << suma_neg(num, i) << endl;
    cout << "El promedio de los valores es " << prom(num, i) << endl;
} 