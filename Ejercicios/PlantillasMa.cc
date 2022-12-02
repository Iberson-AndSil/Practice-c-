#include <iostream>

using namespace std;

template <typename Td>
class Mt{

    private:
        Td M[3];
    public:
        void Pedir();
        void Mostrar();
};

void Mt::Pedir(){
    cout << "Digita Numeros... " << endl;
    for (int i = 0; i < 3; i++)
    {
        cin >> M[i];
    }
}
void Mt::Mostrar(){
    cout << "Mostrando... " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << M[i] << " ";
    }
    cout << endl;
}

int main(){

    Mt matriz;

    matriz.Pedir();
    matriz.Mostrar();

    return 0;
}