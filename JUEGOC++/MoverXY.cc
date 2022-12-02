#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y){
    HANDLE hCon;    
    hCon = GetStdHandle(STD_OUTPUT_HANDLE); 
    COORD dwPos;    
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

int main()
{
    int x = 10, y = 10;
    gotoxy(x, y);
    printf("*");
    bool game_over = false;
    while(!game_over){

        if(kbhit()){			//kbhit es una funcion para evaluar si se ha presionado una tecla y trabaja con la libreria conio.h
            char tecla = getch();  //getch guarda la tecla que se presione y tambien trabaja con la libreria conio.h
            gotoxy(x, y);
            printf(" ");
            if(tecla == 'j') x--;
            if(tecla == 'l') x++;
            if(tecla == 'i') y--;
            if(tecla == 'k') y++;
            gotoxy(x, y);
            printf("*");
        }

        Sleep(30); // esta funcion detiene el proceso por 30 milisegundos para así no saturar al procesador
    }
   
    return 0;
}
