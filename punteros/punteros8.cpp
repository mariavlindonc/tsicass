#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 10, c = 15, *p;
    p = &a;
    cout << *p << endl;
    p = &b;
    cout << *p << endl;
    p = &c;
    cout << *p << endl;
}