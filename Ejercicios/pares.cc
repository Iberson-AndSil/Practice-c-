#include <iostream>

using namespace std;

int main()
{

    int *p, num;

    cout << "digita numero\n";
    cin >> num;
    p = &num;

    if (*p % 2 == 0)
    {
        cout << "el numero es par\n";
        cout << "direccion de memoria ---> " << p << endl;
    }
    else
    {
        cout << "el nuemero es impar\n";
        cout << "direccion de memoria ---> " << p << endl;
    }

    return 0;
}