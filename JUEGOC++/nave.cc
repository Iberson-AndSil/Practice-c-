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
    CONSOLE_CURSOR_INFO cci; 
    cci.dwSize = 40; 
    cci.bVisible = false; 

    SetConsoleCursorInfo(hcon, &cci); 
}

class NAVE{

    private:
        int x;
        int y;
    public:
        NAVE(int _x, int _y): x(_x), y(_y){};
        void Pintar();
        void Borrar();
        void Mover();
};


void NAVE::Pintar(){

    gotoxy(x, y); 
    printf("  %c", 30);
    gotoxy(x, y+1);
    printf(" %c%c%c", 40, 207, 41);
    gotoxy(x, y+2); 
    printf("%c%c %c%c", 30, 190, 190, 30);
    
}

void NAVE::Borrar(){
    gotoxy(x, y);   printf("     ");
    gotoxy(x, y+1); printf("     ");
    gotoxy(x, y+2); printf("     ");
}

void NAVE::Mover(){
    if(kbhit()){			
        char tecla = getch();  
        Borrar();
        if(tecla == IZQUIERDA) x--;
        if(tecla == DERECHA) x++;
        if(tecla == ARRIBA) y--;
        if(tecla == ABAJO) y++;
        Pintar();
    }
    
}
int main(){
    OcultarCursor();
    NAVE N(10, 10);
    N.Pintar();
    bool game_over = false;
    while(!game_over){
        N.Mover();
        Sleep(30);
    }
   
    return 0;
}
