#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <tchar.h>
#include <iostream>

#define BT1 101
#define BT2 102
#define BT3 103
#define ESP 110

HWND boton1;
HWND boton2;
HWND btleer;
HWND escribir;

LRESULT CALLBACK WindowProcedure(HWND ventana1,
                                 UINT MensajeComunica,
                                 WPARAM wParam,
                                 LPARAM lParam)
{
    switch (MensajeComunica)
    {
    case WM_CLOSE:

        DestroyWindow(ventana1);
        break;

    case WM_CREATE:

        boton1 = CreateWindowEx(0, _T("button"),
                                _T("Aceptar"),
                                WS_VISIBLE | WS_CHILD | 0,
                                10, 10, 150, 25,
                                ventana1,
                                (HMENU)BT1, 0, 0);

        boton2 = CreateWindowEx(0, _T("button"),
                                _T("Cerrar"),
                                WS_VISIBLE | WS_CHILD | 0,
                                170, 10, 150, 25,
                                ventana1,
                                (HMENU)BT2, 0, 0);

        btleer = CreateWindowEx(0, _T("button"),
                                _T("Leer"),
                                WS_VISIBLE | WS_CHILD | 0,
                                10, 40, 150, 25,
                                ventana1,
                                (HMENU)BT3, 0, 0);

        escribir = CreateWindowEx(0, _T("Edit"),
                                  _T(""),
                                  BS_PUSHBUTTON | BS_CENTER |
                                      WS_CHILD | WS_VISIBLE |
                                      WS_BORDER,
                                  170, 40, 150, 25,
                                  ventana1,
                                  (HMENU)ESP, 0, 0);

        break;

    case WM_COMMAND:

        switch (LOWORD(wParam))
        {
        case BT1:
            MessageBox(NULL,
                       _T("Soy Iberson y este es mi programa "),
                       _T("Iber el papu"),
                       MB_OKCANCEL | MB_DEFBUTTON2);
            break;

        case BT2:
            if (MessageBox(ventana1, _T("Seguroski quieres salir?"), _T("SAL!! "), MB_OKCANCEL) == IDOK)
            {
                SendMessage(ventana1, WM_CLOSE, 0, 0);
            }
            break;

        case BT3:
            char texto[100] = {0}; // creo una variable de tipo char para almacenar una cadena
            if(GetDlgItemText(ventana1, ESP, texto, 100) == 0){
                MessageBox(ventana1, _T("No se pudo leer el texto"), _T("Error"), MB_OK);
            }
            MessageBox(ventana1, texto, _T("texto leido"), MB_OK);
            SetDlgItemText(ventana1, ESP, _T("")); // Sirve para guardar texto escrito
            break;

        }

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
    HWND ventana1;
    MSG MensajeComunica;
    WNDCLASSEX estilo1;

    estilo1.hInstance = hThisInstance;
    estilo1.lpszClassName = _T("Ventana");
    estilo1.lpfnWndProc = WindowProcedure;
    estilo1.style = CS_DBLCLKS;
    estilo1.cbSize = sizeof(WNDCLASSEX);
    estilo1.hIcon = LoadIcon(NULL, IDI_QUESTION);
    estilo1.hIconSm = LoadIcon(NULL, IDI_INFORMATION);
    estilo1.hCursor = LoadCursor(NULL, IDC_ARROW);
    estilo1.lpszMenuName = NULL;
    estilo1.cbClsExtra = 0;
    estilo1.cbWndExtra = 0;
    estilo1.hbrBackground = (HBRUSH)COLOR_WINDOW;

    if (!RegisterClassEx(&estilo1))
    {
        return 0;
    }

    ventana1 = CreateWindowEx(0, _T("Ventana"),
                              _T("Ventana de Iberson"),
                              WS_OVERLAPPEDWINDOW | WS_BORDER,
                              400,
                              70,
                              644,
                              575,
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