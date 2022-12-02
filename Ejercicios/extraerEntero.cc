#include <iostream>
using namespace std;
int main()
{
    string cadena;
    int longitudCadena;
    cout << "cadena... ";
    cin >> cadena;

    longitudCadena = cadena.length();
    cout << "longitud... " << longitudCadena << endl;

    string extraeNumeros;
    int numeros;

    for (char const &c : cadena) {
        if (isdigit(c) == 0)
        {
            cout << c << ": no number" << endl;
        }
        else
        {
            cout << c << ": number" << endl;
            extraeNumeros += c;
        }
    }
    cout << "Mostrando cadena: " << endl;
    cout << "cadena: " << cadena << endl;
    //convertir de string a int
    numeros = stoi(extraeNumeros);
    cout << "numeros: " << numeros << endl;
    //aumentar entero en 1...
    numeros++;
    //mostrando aumento de entero...
    cout << "numero aumentado en 1: " << numeros << endl;

    return 0;
}