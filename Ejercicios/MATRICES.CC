#include <iostream>
using namespace std;
class matriz
{
private:
    int mat[50][50];
    int col;
    int fil;

public:
    matriz(int, int);
    void almacenarMatriz();
    void quitarElementos(int);
    void quitarPares();
    void calcularDeterminante();
    void mostrarMatriz();
};
matriz::matriz(int _f, int _c)
{
    fil = _f;
    col = _c;
}
void matriz::almacenarMatriz()
{
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "\tPosicion [" << i << "][" << j << "] ---> ";
            cin >> mat[i][j];
        }
    }
}
void matriz::quitarElementos(int N)
{
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (N == mat[i][j])
            {
                mat[i][j] = 0;
                cout << "\tla posicion es --> [" << i << "][" << j << "]" << endl;
            }
        }
    }
}
void matriz::quitarPares()
{
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] % 2 == 0)
            {
                mat[i][j] = 0;
            }
        }
    }
}
void matriz::calcularDeterminante()
{
    int det, aux;
    if (fil = col)
    {
        det = mat[0][0];
        for (int k = 0; k < fil - 1; k++)
        {
            aux = k + 1;
            for (int i = aux; i <= fil; i++)
            {
                for (int j = aux; j <= fil; j++)
                {
                    mat[i][j] = (mat[k][k] * mat[i][j] - mat[k][j] * mat[i][k] / mat[k][k]);
                }
                det = det * mat[k + 1][k + 1];
            }
        }
        cout << "\tla determinante es ---> " << det << endl;
    }
    else
    {
        cout << "\tes imposible calcular determinante\n\n";
        cout << "\tes necesario que el numero de columnas y de filas sean iguales\n\n";
    }
}
void matriz::mostrarMatriz()
{
    cout << "****MUESTRA DE MATRIZ****\n";
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "\t" << mat[i][j];
            cout << "   ";
        }
        cout << "\n";
    }
}
int main()
{
    int f, c, element, opc2;
    char opc;
    cout << "digitar: \n";
    cout << "\tfilas --> ";
    cin >> f;
    cout << "\tcolumnas --> ";
    cin >> c;
    matriz obj(f, c);
    obj.almacenarMatriz();
    do
    {
        cout << "elegir una opcion:\n\n";
        cout << "a.) Quitar elementos\n";
        cout << "b.) Quitar pares\n";
        cout << "c.) Calcular determinante\n";
        cout << "d.) Mostrar matriz\n";
        cin >> opc;
        switch (opc)
        {
        case 'a':
            cout << "Digitar elemento por favor: ";
            cin >> element;
            obj.quitarElementos(element);
            break;
        case 'b':
            obj.quitarPares();
            break;
        case 'c':
            obj.calcularDeterminante();
            break;
        case 'd':
            obj.mostrarMatriz();
            break;
        default:
            cout << "error, intente de nuevo\n";
            break;
        }
        cout << "si deseas salir presiona '1', \nsi deseas continuar presiona '2' \n";
        cin>>opc2;
    } while (opc2 == 2);
    return 0;
}