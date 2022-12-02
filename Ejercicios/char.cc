#include <iostream>
using namespace std;
int main()
{
    string codigo;
    char *almacenaCodigo;
    int cantidadCaracter, ultimoElemento;

    cout << "Digita codigo... ";
    cin >> codigo;

    cantidadCaracter = codigo.length();

    almacenaCodigo = new char[cantidadCaracter];
    
    for (int i = 0; i < cantidadCaracter; i++)
    {
        almacenaCodigo[i] = codigo.at(i);
        if(i == cantidadCaracter){
            ultimoElemento = almacenaCodigo[i];
        }
    }

    ultimoElemento++;
    cout << "el ultimo elemento = " << ultimoElemento << endl; 
    almacenaCodigo[cantidadCaracter] = ultimoElemento;
    codigo.clear();

    codigo = almacenaCodigo;

    cout << "el siguiente codigo sera... " << codigo << endl;
    delete[] almacenaCodigo; 

    return 0;
}