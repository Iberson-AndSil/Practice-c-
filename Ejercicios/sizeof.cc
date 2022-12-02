#include <iostream>
#include <bitset>
using namespace std;
int main(){

    int numero = 255;
    float decimal;
    string cadena = "hola";
    char letra;
    
    cout << "int --> " << sizeof(numero) << endl;
    cout << "float --> " << sizeof(decimal) << endl;
    cout << "string --> " << sizeof(cadena) << endl;
    cout << "char --> " << sizeof(letra) << endl;

    bitset<8> miBinario(numero);

    cout << "hola en binario es ... " << endl;
    cout << miBinario << endl;

    return 0;
}