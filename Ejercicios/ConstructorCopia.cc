#include <iostream>
using namespace std;

class Persona
{
private:
    string nombre;
    short int edad;

public:
    Persona(string _name, short int _years) : nombre(_name), edad(_years){};
    Persona(const Persona &P){};
    void MostrarPersona();
};
void Persona::MostrarPersona()
{
    cout << "Nombre --> " << nombre << endl;
    cout << "Edad   --> " << edad << endl;
}

int main()
{

    Persona P1("Iberson", 20);
    Persona P2(P1);

    P2 = P1;

    P1.MostrarPersona();
    cout << endl;
    P2.MostrarPersona();

    return 0;
}