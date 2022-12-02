#include <iostream>
using namespace std;
 
int main()
{
    int i, j;
 
    for (i=0; i<=5; i++)
        for (j=0; j<=20; j+=2)
        {
            if ((i==1) && (j>=7)) 
                goto salida;
            cout << "i vale " << i << " y j vale "
                << j << endl;
        }
    salida:
    cout << "Fin del programa" << endl;
 
    return 0;
}