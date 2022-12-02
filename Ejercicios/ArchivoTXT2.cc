#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream archivo("alumnos.txt");
    string linea, codigo;

    if (archivo.is_open())
    {
        while (getline(archivo, linea))
        {
            for (char const &c : linea)
            {
                if (c == ' ')
                {
                    c == '\t';
                    codigo += c;
                }
            }
            cout << "codigo: " << codigo << endl;
            codigo.clear();
        }
        archivo.close();
    }
    else
    {
        cout << "no se pudo leer" << endl;
    }
    return 0;
}