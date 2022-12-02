#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream archivo("alumnos.txt");
    string linea;
    string extraeNumero, codigo;

    cout << "Ingresar codigo de verificacion: ";
    cin >> codigo;

    if (archivo.is_open())
    {
        while (getline(archivo, linea))
        {
            for (char const &c : linea)
            {
                if (isdigit(c))
                {
                    extraeNumero += c;
                }
            }
            if (extraeNumero == codigo)
            {
                cout << "el alumno es: " << linea << endl;
                cout << "pertenece a la clase!\n";
            }
            extraeNumero.clear();
        }
        archivo.close();
    }
    else
    {
        cout << "no se pudo leer" << endl;
    }

    if (extraeNumero != codigo)
    {
        cout << "el alumno " << codigo << " no pertenece a la clase \n";
    }
    return 0;
}