#include <iostream>
using namespace std;
//Funcion de conversion
string toBinary(int);
int main()
{
    int number = 12;
    cout << "decimal: " << number << endl;
    cout << "binary : " << toBinary(number) << endl;
    return 0;
}
string toBinary(int n)
{
    string r;
    int var, A[30]; 
    while (n != 0)
    {
        r += (n % 2 == 0 ? "0" : "1"); //En "r" se concatena el numero en bits
        n /= 2;
    }
    var = r.length(); //Guardando el tamaño de la cadena

    //transformo el tipo string en char para ordenar los bits
    for (int i = 0; i < var; i++)
    {
        A[i] = r.at(i);
    }
    r.clear();
    //ordenamiento en la cadena string
    for (int i = var; i >= 0; i--)
    {
        r += A[i];
    }
    return r;
}
