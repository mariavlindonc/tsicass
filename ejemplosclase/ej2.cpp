#include <iostream>
using namespace std;

int main()
{
    int n;
    float notas[3], promedio;
    cout << "Cantidad de estudiantes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        promedio = 0;
        for (int j = 0; j < 3; j++) 
        {
            cout << "Indique la nota " << j + 1  << " del alumno " << i + 1 << endl;
            cin >> notas[j];
            promedio += notas[j];
            
        }
        promedio /= 3;
        cout << "El promedio del alumno " << i + 1 << " es " << promedio << endl;
    }
}