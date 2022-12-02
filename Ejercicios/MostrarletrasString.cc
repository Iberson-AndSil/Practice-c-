#include <iostream>
using namespace std;

void MostrarLetras(const string& str)
{
    for (char const &c : str)
    {
        cout << c << endl;
    }
}

int main()
{
    string cadenaOne = "HOLA";
    MostrarLetras(cadenaOne);

    return 0;
}