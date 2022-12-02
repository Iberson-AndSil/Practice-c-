#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename Tp>
void Pedir(Tp v[]){

    cout << "Digitar numeros" << endl;
    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];
    }
}

template <typename Tp>
void Mostrar(Tp c[]){
    system("cls");
    cout << "mostrando... " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}

int main(){

   int vc[3];

    Pedir(vc);
    Mostrar(vc);

    return 0;
}