#include <iostream>
using namespace std;
int main()
{
    int arreglo[10], *direccion;

    cout << "\tdigitar datos\n\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "numero " << i + 1 << " ---> ";
        cin >> arreglo[i];
    }

    direccion = arreglo;

    cout << "los numeros digitados son:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << *direccion << ", ";
        direccion++;
    }

    return 0;
}
