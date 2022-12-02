#include <iostream>
#include <cstring>
using namespace std;

class ADMINCADENA{

private:
    char *letras;
public:
    ADMINCADENA(const char*);
    void AsignarCadena(const char*);
    char* MostrarCadena(char* l);
};

ADMINCADENA::ADMINCADENA(const char* l){
    letras = new char[strlen(l)+1];
    strcpy(letras, l);
}

void ADMINCADENA::AsignarCadena(const char* c){

    delete[] letras;
    letras = new char[strlen(c)+1];
    strcpy(letras, c);
}

char* ADMINCADENA::MostrarCadena(char *l){
    strcpy(letras, l);
    return l;
}

int main()
{  
    ADMINCADENA c1(" ");

    return 0;
}