//#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
int main()
{

    int num[10];

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        num[i] = 40 + rand() % (50 - 40);
        cout << num[i] << endl;
    }
    return 0;
}