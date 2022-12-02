#include <iostream>
#include <stdlib.h>
using namespace std;

class Persona
{
private:
    string nombre;
    int edad;

public:
    Persona(string, int);
    void mostrarPersona();
};
class Alumno : public Persona
{
private:
    string CodigoAlumno;
    float NotaFinal;

public:
    Alumno(string, int, string, float);
    void MostrarAlumno();
};

Persona::Persona(string _nombre, int _edad)
{
    nombre = _nombre;
    edad = _edad;
}
Alumno::Alumno(string _nombre, int _edad, string _CodigoAlumno, float _NotaFinal) : Persona(_nombre, _edad)
{
    CodigoAlumno = _CodigoAlumno;
    NotaFinal = _NotaFinal;
}

void Persona::mostrarPersona()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}
void Alumno::MostrarAlumno()
{
    mostrarPersona();
    cout << "Codigo Alumno: " << CodigoAlumno << endl;
    cout << "Nota Final: " << NotaFinal << endl;
}
int main()
{
    Alumno alumno1("Iberson", 20, "0020190527", 10.6);

    alumno1.MostrarAlumno();

    return 0;
}