//notas de alumnos

#include <iostream>

using namespace std;

class alumnos
{

private:
    float notas[10];
    int cantidad;

public:
    void setpedirNotas(int);
    void setnotaMayor(int);
    void setnotaMenor(int);
};
void alumnos::setpedirNotas(int cant)
{
    cantidad = cant;
    cout << "digita datos : \n";

    for (int i = 0; i < cantidad; i++)
    {
        cout<<"nota --> ";
        cin >> notas[i];
    }
}
void alumnos::setnotaMayor(int cant)
{
    cantidad = cant;

    int mayor = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (notas[i] > mayor)
        {
            mayor = notas[i];
        }
    }
    cout << "la mayor nota es ---> " << mayor << endl;
}
void alumnos::setnotaMenor(int cant)
{
cantidad = cant;

int menor = notas[0];

for (int i = 1; i < cantidad; i++)
{
    if(menor >= notas[i]){

        menor = notas[i];

    }

}
cout<<"la menor nota es ---> " <<menor <<endl;


}

int main()
{
    int c;

    cout << "digita cantidad de notas ----> ";
    cin >> c;
    alumnos obj;

    obj.setpedirNotas(c);
    obj.setnotaMayor(c);
    obj.setnotaMenor(c);

    return 0;
}