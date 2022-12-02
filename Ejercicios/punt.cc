#include <iostream>
using namespace std;

void ImprimeHola(int x){
    cout << "Hola numero " << x << endl;
}

void ImprimeAdios(int x, void(*ptr_func)()){
    cout << "Adios numero " << x  << endl;
    if (ptr_func != NULL)
    {
        ptr_func();
    }
}

void func_call_back(){
    cout << "retrollamda " << endl;
}

int main(){
    void (*ptr_func_1) (int) = NULL;
    void (*ptr_func_2) (int, void (*call_back_func)()) = NULL;
    ptr_func_1 = ImprimeHola;
    cout << "la direccion del primer puntero es " << ptr_func_1 << endl;
    ptr_func_1(3);
    ptr_func_2 = ImprimeAdios;
    cout << "using a callback funcion " << ptr_func_2 << endl;
    ptr_func_2(3, func_call_back);
    return 0;
}