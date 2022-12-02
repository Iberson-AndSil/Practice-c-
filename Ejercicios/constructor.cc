/*construya una clase tiempo que contenga los 
siguientes atributos enteros: horas, minutos,
segundos. haga que la clase contenga 2 constructores,
el primero debe tener 3 parametros tiempo(int,int,int)
y el segundo solo tendra un campo que seran los
segundos y desemsale el numero entero largo en horas, 
minutos y segundos.*/

#include <iostream>

using namespace std;

class tiempo
{

private:
    int horas;
    int minutos;
    int segundos;

public:
    tiempo(int, int, int);
    tiempo(long);
    void mostrar();
};
tiempo::tiempo(int _h, int _m, int _s)
{

    horas = _h;
    minutos = _m;
    segundos = _s;
}
tiempo::tiempo(long temp)
{
    int var;

    var = temp / 60;
    segundos = (temp % 60);
    minutos = (var % 60);
    horas = (var / 60);
}
void tiempo::mostrar()
{

    cout << "la hora es : " << horas << " : " << minutos << " : " << segundos << endl;
}

int main()
{
    tiempo obj(19, 4, 10);
    tiempo obje(19410);
 
    obj.mostrar();
    obje.mostrar();
        
   return 0;
}