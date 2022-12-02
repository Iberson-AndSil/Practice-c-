#include <iostream>
#include <fstream> //Sirve para poder leer o escribir ficheros

using namespace std;

int main()
{
    ofstream miarchivo("ejemplocc.txt"); // se crea el fichero con su extension

    if (miarchivo.is_open())
    {
        //en las siguientes 3 lineas se agrega contenido al .txt
        miarchivo << "primera linea \n";
        miarchivo << "segunda linea \n";
        miarchivo << "tercera linea \n";
        miarchivo.close(); 
        cout << "El archivo guardado exito";
    }
    else
    {
        cout << "hubo problemas al guardar";
    }
    return 0;
}