#include <iostream>
using namespace std;

int main()
{
    float *p, f1 = 0.2, f2 = 0.5;
    int *q, i1 = 2, i2 = 6;
    p = &f1;
    q = &i1;
    cout << *p << " " << *q << endl;
    p = &f2;
    q = &i2;
    cout << *p << " " << *q << endl;
}