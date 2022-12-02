/*- Atributos 
  DNI
  NOMBRE
  EDAD
- Constructores 
  Inicia el atributo DNI con la cadena 12345678 y el nombre con una cadena vacia
- Destructores
  Borra los contenidos de DNI y NOMBRE
- Metodos
  GuardaDNI, recibe el DNI y lo almacena siempre y cuando tenga longitud de 8 
caracteres
  GuardaNombre, recibe el nombre y lo almacena siempre y cuando no sea una cadena 
vacia.
  GuardaEdad, recibe la edad y lo almacena siempre y cuando sea mayor o igual a 
cero*/

#include <iostream>
#include <cstring>
using namespace std;

class Persona{

    private:
        long DNI;
        char* Nombre;
        int edad;
    public:
        Persona(long, const char*, int);
        ~Persona();
        void GuardaDni();
        void GuardaNombre();
        void GuardaEdad();
};

Persona::Persona(long _dni, const char* _nombre, int _edad){
    DNI = _dni;
    Nombre = new char[strlen(_nombre)+1];
    strcpy(Nombre, _nombre);
    edad = _edad;
}
Persona::~Persona(){}

void Persona::GuardaDni(){
  long DNIauxiliar;
  cout << "digitar DNI... ";
  cin >> DNIauxiliar;
  int r, s = 0;

  while(DNIauxiliar > 0)
	{
		r = DNIauxiliar % 10;
		s = s + r;
		DNIauxiliar = DNIauxiliar / 10;
	}

  if (s = 8)
  {
    DNI = DNIauxiliar;
  }
  
}

void Persona::GuardaNombre(){
  string nombreAuxiliar;
  cout << "digita nombre... ";
  cin >> nombreAuxiliar;
  if (nombreAuxiliar.length() != 0){

    for (int i = 0; i < nombreAuxiliar.length(); i++)
    {
      Nombre[i] = nombreAuxiliar.at(i);
    }
  }

}

void Persona::GuardaEdad(){

  int auxiliarEdad;
  cout << "digitar edad... ";
  cin >> auxiliarEdad;
  if(auxiliarEdad >= 0){
    edad = auxiliarEdad;
  }

}

int main()
{
    Persona p1(12345678, " ", 0);
    p1.~Persona();
    p1.GuardaDni();
    p1.GuardaEdad();
    p1.GuardaNombre();

    return 0;
}