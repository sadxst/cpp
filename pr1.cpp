#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    double x, y, z;
    cout << "Введіть x: ";
    cin >> x;
    cout << "Введіть y: ";
    cin >> y;
    cout << "Введіть z: ";
    cin >> z;
    const double pi = acos(-1.0);
    double ch = x + exp(-x + 1.3) * log(1 + x * x + y * y) + (3.0 / 4.0) * y + pi * z;
    double zn = (8.0 + (x * x) / 2.0 + (y * y) / 3.0 + z) * (pow(cos(x), 2) + pow(sin(y + z), 2) + 1.001);
    double a = ch / zn;
    cout << "A = " << a << endl;
    return 0;
    }