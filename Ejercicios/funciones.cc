//calcular division con restas sucesivas
#include <iostream>
using namespace std;
void pedirDatos(int &, int &);
void algoritmo(int &, int, int &);
void mostrarResultado(int, int);
int main()
{
    int b1 = 0, b2 = 0, entero = 0;
    pedirDatos(b1, b2);
    algoritmo(b1, b2, entero);
    mostrarResultado(entero, b1);
    return 0;
}
void pedirDatos(int &num1, int &num2)
{
    cout << "digita numero 1: ";
    cin >> num1;
    cout << "digita numero 2: ";
    cin >> num2;
}
void algoritmo(int &n, int m, int &ent)
{
    do
    {
        n = n - m;
        ent++;
    } while (n >= m);
}
void mostrarResultado(int var1, int var2)
{
    cout << "el entero es: " << var1 << endl;
    cout << "el residuo es: " << var2 << endl;
}