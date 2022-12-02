#include <iostream>
#include <fstream> //Sirve para poder leer o escribir ficheros
using namespace std;

int main()
{
    ifstream miarchivo("ejemplojava.txt"); //ifstream es una funcion de salida para el archivo
    string linea;

    if (miarchivo.is_open())
    {
        while (getline(miarchivo, linea)) //Se obtiene informacion desde miarchivo y descargaso en linea
        {
            cout << linea << endl;
        }
        miarchivo.close();
    }
    else
    {
        cout << "no se pudo leer" << endl;
    }
}