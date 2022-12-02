#include <iostream>
#include <cstring>
using namespace std;

class Puntero{

    private: 
        int entero;
        char *p;
    public:
        Puntero(int, char*);
        void Mostrar();
};

Puntero::Puntero(int _entero, char *_p){
    entero = _entero;
    p = new char[strlen(_p)];
    strcpy(p, _p);
}

void Puntero::Mostrar(){

    cout << "entero... " << this->entero << endl;
    cout << "letra... " << this->p << endl;

}

int main(){

    Puntero P(4, "a");
    P.Mostrar();
    return 0;
}