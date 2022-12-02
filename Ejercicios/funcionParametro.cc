#include <iostream>

using namespace std;

void suma(int &, int &);

int main()
{

    int a, b;

    cout << "digita dos numeros para sumar --> ";
    cin >> a >> b;
    suma(a, b);

    cout << "los nuevos numeros son: " << a << ", " << b << endl
         << endl;

    return 0;
}
void suma(int &num1, int &num2)
{
    int suma;

    suma = num1 + num2;

    cout << "la suma es: " << suma << endl;
    num1 = 8;
    num2 = 7;
}