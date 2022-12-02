#include <iostream>
using namespace std;

void PedirDatos(int& , int[]);
int NumMay(int, int[]);
int NumMen(int, int[]);
void ordenar(int, int[]);
int main()
{
    int numeros[10], cantidad;
    PedirDatos(cantidad, numeros);
    cout << "el mayor numero es " << NumMay(cantidad, numeros) << endl;
    cout << "el menor numero es " << NumMen(cantidad, numeros) << endl;
    ordenar(cantidad, numeros);
    return 0;
}
void PedirDatos(int &cant, int num[])
{
    cout << "cuantos numeros deseas comparar?\n";
    cin >> cant;
    cout << "digitar numeros:\n";
    for (int i = 0; i < cant; i++)
    {
        cout << "numero " << i + 1 << " --> ";
        cin >> num[i];
    }
}
int NumMay(int cant, int num[])
{
    int mayor = 0;
    for (int i = 0; i < cant; i++)
    {
        if (mayor < num[i])
        {
            mayor = num[i];
        }
    }
    return mayor;
}
int NumMen(int cant, int num[])
{
    int menor = num[0];
    for (int i = 1; i < cant; i++)
    {
        if (menor > num[i])
        {
            menor = num[i];
        }
    }
    return menor;
}
void ordenar(int cant, int num[])
{
    int aux_elem;
    for (int i = 0; i < cant - 1; i++)
    {
        for (int j = 1; j < cant; j++)
        {
            if (num[j] < num[j - 1])
            { // si el elemento anterior es mayor, hacemos el cambio
                aux_elem = num[j];
                num[j] = num[j - 1];
                num[j - 1] = aux_elem;
            }
        }
    }
    cout << "Numeros ordenados... ";
    for (int i = 0; i < cant; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
}