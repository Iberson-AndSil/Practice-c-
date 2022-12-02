#include <iostream>
using namespace std;
int main()
{

    int Matriz[4][4];
    int i, j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i == j)
            {
                Matriz[i][j] = 1;
            }
            else
            {
                Matriz[i][j] = 0;
            }
        }
    }
    char barra = 124;
    char raya = 196;

    for (int k = 0; k < 4; k++)
    {
         cout << "  " << k << " ";  
    }
    
    cout << endl;
    for (i = 0; i < 4; i++)
    {
        for (int k = 0; k < 4; k++)
        {

            cout << " " << raya << raya << raya;
        }
        cout << endl;
        cout << barra << " ";
        for (j = 0; j < 4; j++)
        {
            cout << Matriz[i][j] << " " << barra << " ";
        }
        cout << i;
        cout << endl;
    }
    for (int k = 0; k < 4; k++)
    {

        cout << " " << raya << raya << raya;
    }
    cout << endl;
    return 0;
}