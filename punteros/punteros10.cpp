#include <iostream>
using namespace std;

int funcion1(int n);
void funcion2(int &a);

int main()
{
    int a = 10;

    cout << funcion1(a) << endl;

    funcion2(a);
    cout << a << endl;
}

int funcion1(int n)
{
    n += 30;
    return n;
}

void funcion2(int &a)
{
    a += 10;
}