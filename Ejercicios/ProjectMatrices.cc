#include <iostream>
#include <stdlib.h>
using namespace std;

class Mtr
{
private:
    int **Matrix1;
    int **Matrix2;
    int **resultado_operacion;
    int NFilas;
    int NCol;

public:
    Mtr(int, int);
    void MenuMatrix();
    void DigitarMatrix();
    void MostrarMatrix();
    void SumarMatrix();
    void RestarMatrix();
    void MultiplicarMatrix();
};
Mtr::Mtr(int _NFilas, int _NCol)
{
    NFilas = _NFilas;
    NCol = _NCol;
}

void Mtr::MenuMatrix()
{
    int op;
    cout << "\t ________________" << endl;
    cout << "\t| MENU MATRICES |" << endl;
    cout << "\t-----------------" << endl
         << endl;
    cout << "1. SUMAR \n";
    cout << "2. RESTAR \n";
    cout << "3. MULTIPLICAR\n";
    cout << "4. DIVIDIR\n";
    cout << "5.SALIR\n";

    cin >> op;

    switch (op)
    {
    case 1:
        SumarMatrix();
        break;
    case 2:
        RestarMatrix();
        break;
    default:
        break;
    }
}

void Mtr::DigitarMatrix()
{

    Matrix1 = new int *[NFilas];
    for (int i = 0; i < NFilas; i++)
    {
        Matrix1[i] = new int[NCol];
    }

    Matrix2 = new int *[NFilas];
    for (int i = 0; i < NFilas; i++)
    {
        Matrix2[i] = new int[NCol];
    }

    cout << "Digitando...\n"
         << endl;
    cout << "\tMatrix 1...\n";
    for (int i = 0; i < NFilas; i++)
    {
        for (int j = 0; j < NCol; j++)
        {
            cout << "[" << i << "][" << j << "] --> ";
            cin >> *(*(Matrix1 + i) + j);
        }
    }
    system("cls");
    cout << "\tMatrix 2...\n";
    for (int i = 0; i < NFilas; i++)
    {
        for (int j = 0; j < NCol; j++)
        {
            cout << "[" << i << "][" << j << "] --> ";
            cin >> *(*(Matrix2 + i) + j);
        }
    }
}
void Mtr::MostrarMatrix()
{
    system("cls");
    cout << "Mostrando...\n"
         << endl;
    cout << "\tMatrix 1...\n";
    for (int i = 0; i < NFilas; i++)
    {
        for (int j = 0; j < NCol; j++)
        {
            cout << *(*(Matrix1 + i) + j) << "  ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
    cout << "\tMatrix 2...\n";
    for (int i = 0; i < NFilas; i++)
    {
        for (int j = 0; j < NCol; j++)
        {
            cout << *(*(Matrix2 + i) + j) << "  ";
        }
        cout << endl;
    }
}

void Mtr::SumarMatrix()
{
    system("cls");
    string opc;
    resultado_operacion = new int *[NFilas];
    for (int i = 0; i < NFilas; i++)
    {
        resultado_operacion[i] = new int[NCol];
    }

    //En este bloque hare la suma de matriz 1 y matriz 2
    for (int i = 0; i < NFilas; i++)
    {
        for (int j = 0; j < NCol; j++)
        {
            *(*(resultado_operacion + i) + j) = *(*(Matrix1 + i) + j) + *(*(Matrix2 + i) + j);
        }
    }
    cout << "mostrando... " << endl;
    for (int i = 0; i < NFilas; i++)
    {
        for (int j = 0; j < NCol; j++)
        {
            cout << *(*(resultado_operacion + i) + j) << "  ";
        }
        cout << endl;
    }
    //liberando memoria
    for (int i = 0; i < NFilas; i++)
    {
        delete[] resultado_operacion[i];
    }
    delete[] resultado_operacion;

    cout << "Volver al menu?(si/no)... ";
    while (opc != "si" && opc != "no")
    {
        cin >> opc;
    }
    if (opc == "si")
        MenuMatrix();
    else
        system("exit");
}
void Mtr::RestarMatrix(){

     system("cls");
    string opc;
    resultado_operacion = new int *[NFilas];
    for (int i = 0; i < NFilas; i++)
    {
        resultado_operacion[i] = new int[NCol];
    }

    //En este bloque hare la suma de matriz 1 y matriz 2
    for (int i = 0; i < NFilas; i++)
    {
        for (int j = 0; j < NCol; j++)
        {
            *(*(resultado_operacion + i) + j) = *(*(Matrix1 + i) + j) - *(*(Matrix2 + i) + j);
        }
    }
    cout << "mostrando... " << endl;
    for (int i = 0; i < NFilas; i++)
    {
        for (int j = 0; j < NCol; j++)
        {
            cout << *(*(resultado_operacion + i) + j) << "  ";
        }
        cout << endl;
    }
    //liberando memoria
    for (int i = 0; i < NFilas; i++)
    {
        delete[] resultado_operacion[i];
    }
    delete[] resultado_operacion;

    cout << "Volver al menu?(si/no)... ";
    while (opc != "si" && opc != "no")
    {
        cin >> opc;
    }
    if (opc == "si")
        MenuMatrix();
    else
        system("exit");

}

void Mtr::MultiplicarMatrix(){
    system("cls");
    string opc;
    resultado_operacion = new int *[NFilas];
    for (int i = 0; i < NFilas; i++)
    {
        resultado_operacion[i] = new int[NCol];
    }

    //En este bloque hare la suma de matriz 1 y matriz 2
    for (int i = 0; i < NFilas; i++)
    {
        for (int j = 0; j < NCol; j++)
        {
            *(*(resultado_operacion + i) + j) = *(*(Matrix1 + i) + j) - *(*(Matrix2 + i) + j);
        }
    }
    cout << "mostrando... " << endl;
    for (int i = 0; i < NFilas; i++)
    {
        for (int j = 0; j < NCol; j++)
        {
            cout << *(*(resultado_operacion + i) + j) << "  ";
        }
        cout << endl;
    }
    //liberando memoria
    for (int i = 0; i < NFilas; i++)
    {
        delete[] resultado_operacion[i];
    }
    delete[] resultado_operacion;

    cout << "Volver al menu?(si/no)... ";
    while (opc != "si" && opc != "no")
    {
        cin >> opc;
    }
    if (opc == "si")
        MenuMatrix();
    else
        system("exit");
}

void PedirFilCol(int &, int &);

int main()
{

    int f, c;
    PedirFilCol(f, c);
    Mtr M1(f, c);

    M1.DigitarMatrix();
    M1.MostrarMatrix();
    M1.MenuMatrix();

    return 0;
}
void PedirFilCol(int &fil, int &col)
{
    cout << "Filas    --> ";
    cin >> fil;
    cout << "columnas --> ";
    cin >> col;
}