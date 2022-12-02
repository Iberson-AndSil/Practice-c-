#include <iostream>
using namespace std;
void conjuntoA(int, int[]);
void conjuntoB(int, int[]);
void compararAB(int, int, int A[], int B[]);
int main()
{

    int var_1, var_2, A[10], B[10];

    cout << "\tdigite cantidad de valores de: \n\n";
    cout << "conjunto A --> ";
    cin >> var_1;
    conjuntoA(var_1, A);
    cout << "conjunto B --> ";
    cin >> var_2;
    conjuntoB(var_2, B);
    compararAB(var_1, var_2, A, B);
    cout << "los valores del conjunto A son: ";
    for (int i = 0; i < var_1; i++)
    {
        cout << A[i] << ", ";
    }

    return 0;
}
void conjuntoA(int C_A, int a[])
{

    for (int i = 0; i < C_A; i++)
    {
        cout << "numero " << i + 1 << " --> ";
        cin >> a[i];
    }
}
void conjuntoB(int C_B, int b[])
{
    for (int i = 0; i < C_B; i++)
    {
        cout << "numero " << i + 1 << " --> ";
        cin >> b[i];
    }
}
void compararAB(int C_A, int C_B, int A[], int B[])
{
    int var = 0;
    if (C_A >= C_B)
    {
        for (int i = 0; i < C_A; i++)
        {
            for (int j = 0; j < C_B; j++)
            {
                if (A[i] == B[j])
                {
                    var++;
                }
            }
        }
        if (var == C_B)
        {
            cout << "el conjunto B incluye A\n";
        }
        if (var != C_B)
        {
            cout << "el conjunto B no incluye A\n";
        }
    }
    if (C_B > C_A)
    {
        for (int i = 0; i < C_B; i++)
        {
            for (int j = 0; j < C_A; j++)
            {
                if (B[i] == A[j])
                {
                    var++;
                }
            }
        }
        if (var == C_A)
        {
            cout << "el conjunto A incluye B\n";
        }
        if (var != C_A)
        {
            cout << "el conjunto A no incluye B\n";
        }
    }
}