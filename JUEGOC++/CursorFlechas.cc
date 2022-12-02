#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

void gotoxy(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;

    SetConsoleCursorPosition(hCon, dwPos);
}

void OcultarCursor(){ //funcion de manejo del cursor
    HANDLE hcon;        
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci; //CONSOLE_CURSOR_INFO es una estructura que permite usar los manejos del cursor
    cci.dwSize = 40; // sirve para manejar el tamaÃ±o del cursor
    cci.bVisible = false; // true indica que el cursor serÃ¡ visible, si indicamos lo contrario desaparecerÃ¡

    SetConsoleCursorInfo(hcon, &cci); // cci va con paramatro porque esta variable serÃ¡ modificada
}

int main(){
    OcultarCursor();
    int x = 10, y =10;
    gotoxy(x, y);
    printf("*");
    
    bool game_over = false;
    while(!game_over){

        if(kbhit()){			
            char tecla = getch();  
            gotoxy(x, y);
            printf(" ");
            if(tecla == IZQUIERDA) x--;
            if(tecla == DERECHA) x++;
            if(tecla == ARRIBA) y--;
            if(tecla == ABAJO) y++;
            gotoxy(x, y);
            printf("*");
        }

        Sleep(30);
    }
   
    return 0;
}
