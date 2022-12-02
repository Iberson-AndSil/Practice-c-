#include <stdio.h>
#include <windows.h>

int main()
{
    printf("*");
    HANDLE hCon;                            //HANDLE es un identificador para un objeto. HWND es un identificador de una ventana.
    hCon = GetStdHandle(STD_OUTPUT_HANDLE); //tomamos el control de salida y se lo designamos a la variable hCon.
    COORD dwPos;    // para las coordenadas
    dwPos.X = 4;
    dwPos.Y = 5;

    SetConsoleCursorPosition(hCon, dwPos);
    printf("*");

    return 0;
}