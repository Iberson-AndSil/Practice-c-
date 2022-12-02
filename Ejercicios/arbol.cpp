#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *der;
    Nodo *izq;
};



Nodo *crearNodo(int n){
    Nodo *Nuevo_nodo = new Nodo();

    Nuevo_nodo->dato = n;
    Nuevo_nodo->der = NULL;
    Nuevo_nodo->izq = NULL;

    return Nuevo_nodo;
}

void InsertarNodo(Nodo *&arbol, int n){
    if (arbol == NULL){

        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;

    }
    else
    {
        int valorRaiz = arbol->dato;

        if (n < valorRaiz)
        {
            InsertarNodo(arbol->izq, n);
        }
        else
        {
            InsertarNodo(arbol->der, n);
        }
        
    }

}

void menu(){

    int dato;
    int opcion;

    do
    {
        cout << "\t.:MENU:." << endl;
        cout << "1. Insertar un nuevo nodo" << endl;
        cout << "2. Salir" << endl; 
        cout << "opcion... ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "\nDigite un numero: ";
            cin >> dato;
            InsertarNodo(arbol, dato);
            cout << endl;
            system("pause");

            break;
        }

        system("cls");

    } while (opcion != 2);
    
}

Nodo *arbol = NULL;

int main(){

    menu();

    return 0;
}

