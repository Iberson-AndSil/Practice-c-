#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    char letra;
    int num, c = 0, resta;
    cout << "letra:  ";
    cin >> letra;
    cout << "numero: ";
    cin >> num;
    cout << endl;
    resta = (num * 2) - 1;
    for (int i = 1; i <= resta; i++)
    {
        if (i == num)
        {
            cout << letra;
        }
        else
        {
            cout << " ";
        }
    }
    cout << endl;
    for (int k = 0; k < num - 2; k++)
    {
        c++;
        for (int j = 1; j <= resta; j++)
        {

            if (j == num - c || j == num + c)
            {
                cout << letra;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    for (int x = 1; x <= resta; x++)
    {
        if (x % 2 == 1)
        {
            cout << letra;
        }
        else
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
