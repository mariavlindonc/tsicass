#include <iostream>
using namespace std;

int main()
{
    float a, b, *p;
    p = &a;
    p = &b;
    *p = 5;
    p = &a;
    *p = 10;
    cout << a << " " << b;
}