#include <tchar.h>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#define OPERADOR 100
#define CALCULAR 101
#define SALIR 102
#define PRACTICAR 103
#define DIGITA 110
#define RESUL 120

LRESULT CALLBACK WindowProcedure(HWND ventana1,
                                 UINT MensajeComunica,
                                 WPARAM wParam,
                                 LPARAM lParam)
{
    HWND controles;
    static HINSTANCE Instancia;
    BOOL exito = FALSE;
    int numero = 0;
    int item = SendDlgItemMessage(ventana1,OPERADOR,CB_GETCURSEL,0,0);
    int opcion = 4;
    const char *Operaciones[] = {
        "Multiplicacion", "Division", "Suma", "Resta"};

    switch (MensajeComunica)
    {

     case WM_DESTROY:
        PostQuitMessage(0);
        break;

     case WM_CREATE:
        Instancia = ((LPCREATESTRUCT)lParam)->hInstance;
        controles = CreateWindow(_T("STATIC"), _T("TABLA DEL "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD,
                                 6, 10, 100, 22, ventana1,
                                 (HMENU)-1, Instancia,
                                 NULL);

        controles = CreateWindow(_T("STATIC"), _T("K.J.H.I.K"),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD,
                                 278, 290, 100, 22, ventana1,
                                 (HMENU)-1, Instancia,
                                 NULL);

        controles = CreateWindowEx(0, _T("EDIT"), _T(""),
                                   ES_LEFT | ES_NUMBER | WS_BORDER | WS_CHILD | WS_VISIBLE,
                                   110, 10, 50, 22, ventana1,
                                   (HMENU)DIGITA, Instancia,
                                   NULL);

        controles = CreateWindowEx(0, _T("BUTTON"), _T("Calcular"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   275, 10, 100, 22, ventana1,
                                   (HMENU)CALCULAR, Instancia,
                                   NULL);

        controles = CreateWindowEx(0, _T("BUTTON"), _T("Salir"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   275, 35, 100, 22, ventana1,
                                   (HMENU)SALIR, Instancia,
                                   NULL);
        
        controles = CreateWindowEx(0, _T("BUTTON"), _T("Practicar"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   275, 60, 100, 22, ventana1,
                                   (HMENU)PRACTICAR, Instancia,
                                   NULL);

        controles = CreateWindow(_T("STATIC"), _T(""),
                                 ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE,
                                 10, 35, 150, 270, ventana1,
                                 (HMENU)RESUL, Instancia,
                                 NULL);
        controles = CreateWindow(_T("COMBOBOX"), _T(""),
                                 CBS_DROPDOWNLIST | WS_CHILD | WS_VISIBLE,
                                 165, 10, 100, 500,
                                 ventana1, (HMENU)OPERADOR, Instancia,
                                 NULL);
        for (int i = 0; i < opcion; i++)
        {
            SendDlgItemMessage(ventana1, OPERADOR,
                               CB_ADDSTRING, 0,
                               (LPARAM)Operaciones[i]);
        }
        SendDlgItemMessage(ventana1, OPERADOR, CB_SETCURSEL,
                           (WPARAM)1, (LPARAM)0);
        break;

     case WM_COMMAND:

        switch (LOWORD(wParam))
        { 

         case CALCULAR:
                 numero = GetDlgItemInt(ventana1, DIGITA, &exito, TRUE);
            if (exito != TRUE)
            {
                MessageBox(ventana1, _T("DIGITE UN NUMERO"), _T("ERROR"), MB_ICONERROR);
                SetFocus(GetDlgItem(ventana1, DIGITA));
                break;
            }
            else
            {
                 char Resultado[50] = {0};
                 char Tabla[500] = {0};
                 int val =numero;
                  
                switch(item){
                    /*  0 = multiplicacion
                        1 = division 
                        2 = suma
                        3 = resta*/
                  case 0: 
                    for (int i = 0; i <= 12; i++)
                    {
                        sprintf(Resultado, "%d x %d = %d\n", i, numero, i * numero);
                        strcat(Tabla, Resultado);
                    }
                    SetDlgItemText(ventana1, RESUL, Tabla);
                    break;
                  case 1: 
                   if (numero==0){
                        MessageBox(ventana1, _T("Todo numero dividido entre cero sera infinito.\n Prueba con otro!"), _T("DATO"), MB_ICONINFORMATION);
                         SetFocus(GetDlgItem(ventana1, DIGITA));
                   }else{
                    for (int i = val; i <= (val+12); i++)
                    {
                        if(i % numero == 0){
                        sprintf(Resultado, "%d / %d = %d\n", i, numero, i / numero);
                        strcat(Tabla, Resultado);
                        }else{val++;}
                    }
                    SetDlgItemText(ventana1, RESUL, Tabla);
                    }
                    break;
                  case 2: 
                    for (int i = 0; i <= 12; i++)
                    {
                        sprintf(Resultado, "%d + %d = %d\n", i, numero, i + numero);
                        strcat(Tabla, Resultado);
                    }
                    SetDlgItemText(ventana1, RESUL, Tabla);
                    break;
                  case 3: 
                    for (int i = numero; i <= (numero+12); i++)
                    {
                        sprintf(Resultado, "%d - %d = %d\n", i,numero, i - numero);
                        strcat(Tabla, Resultado);
                    }
                    SetDlgItemText(ventana1, RESUL, Tabla);
                    break;
                }
            }

            break;

        case PRACTICAR:

            int v1, v2, v3, v4;
            int r1, r2;

            


            controles = CreateWindow(_T("STATIC"), _T(" "),
                                 ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE,
                                 180, 110, 30, 22, ventana1, //275, 60, 100, 22,
                                 (HMENU)RESUL, Instancia,
                                 NULL);
            
            controles = CreateWindow(_T("STATIC"), _T(" "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD,
                                 6, 10, 100, 22, ventana1,
                                 (HMENU)-1, Instancia,
                                 NULL);

            break;

         case SALIR:
            if (MessageBox(ventana1, _T("Seguro que quieres salir?"), _T("SALIR "), MB_ICONQUESTION | MB_OKCANCEL) == IDOK)
            {
                PostQuitMessage(0);
            }
            break;
        }

        break;

     default:
        return DefWindowProc(ventana1, MensajeComunica,
                             wParam, lParam);
    }

    return 0;
}
int WINAPI WinMain(HINSTANCE hThisInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpszArgument,
                   int nCmdShow)
{
    WNDCLASSEX estilo1;
    HWND ventana1;
    MSG MensajeComunica;

    estilo1.hInstance = hThisInstance;
    estilo1.lpszClassName = _T("Ventana");
    estilo1.lpfnWndProc = WindowProcedure;
    estilo1.style = CS_DBLCLKS;
    estilo1.cbSize = sizeof(WNDCLASSEX);
    estilo1.hIcon = LoadIcon(NULL, IDI_QUESTION);
    estilo1.hIconSm = LoadIcon(NULL, IDI_INFORMATION);
    estilo1.hCursor = LoadCursor(NULL, IDC_HAND);
    estilo1.lpszMenuName = NULL;
    estilo1.cbClsExtra = 0;
    estilo1.cbWndExtra = 0;
    estilo1.hbrBackground = (HBRUSH)COLOR_GRADIENTINACTIVECAPTION;

    if (!RegisterClassEx(&estilo1))
    {
        return 0;
    }

    ventana1 = CreateWindowEx(0, _T("Ventana"),
                              _T("TABLA DE OPERADORES"),
                              WS_MINIMIZEBOX|WS_CAPTION|WS_POPUPWINDOW,
                              550,
                              150,
                              400,
                              360,
                              HWND_DESKTOP,
                              NULL,
                              hThisInstance,
                              NULL);

    ShowWindow(ventana1, nCmdShow);
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    while (GetMessage(&MensajeComunica, NULL, 0, 0))
    {
        TranslateMessage(&MensajeComunica);

        DispatchMessage(&MensajeComunica);
    }
    return MensajeComunica.wParam;
}