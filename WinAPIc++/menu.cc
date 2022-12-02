#include <windows.h>
#include <tchar.h>
#define CM_PRUEBA 100
#define CM_SALIR  101

/*  Declaración del procedimiento de ventana  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/* Otros prototipos */
void InsertarMenu(HWND);

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)
{
    HWND hwnd;               /* Manipulador de ventana */
    MSG mensaje;             /* Mensajes recibidos por la aplicación */
    WNDCLASSEX wincl;        /* Estructura de datos para la clase de ventana */

    /* Estructura de la ventana */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = _T("NUESTRA_CLASE");
    wincl.lpfnWndProc = WindowProcedure;      /* Esta función es invocada por Windows */
    wincl.style = CS_DBLCLKS;                 /* Captura los doble-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Usar icono y puntero por defector */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* Sin menú */
    wincl.cbClsExtra = 0;                      /* Sin información adicional para la */
    wincl.cbWndExtra = 0;                      /* clase o la ventana */
    /* Usar el color de fondo por defecto para la ventana */
    wincl.hbrBackground = GetSysColorBrush(COLOR_BACKGROUND);

    /* Registrar la clase de ventana, si falla, salir del programa */
    if(!RegisterClassEx(&wincl)) return 0;

    /* La clase está registrada, crear la ventana */
    hwnd = CreateWindowEx(
           0,                   /* Posibilidades de variación */
           _T("NUESTRA_CLASE"),     /* Nombre de la clase */
           _T("Ejemplo 002"),       /* Texto del título */
           WS_OVERLAPPEDWINDOW, /* Tipo por defecto */
           CW_USEDEFAULT,       /* Windows decide la posición */
           CW_USEDEFAULT,       /* donde se coloca la ventana */
           544,                 /* Ancho */
           375,                 /* Alto en pixels */
           HWND_DESKTOP,        /* La ventana es hija del escritorio */
           NULL,                /* Sin menú */
           hThisInstance,       /* Manipulador de instancia */
           NULL                 /* No hay datos de creación de ventana */
    );

    /* Insertar menú */
    InsertarMenu(hwnd);
    
    /* Mostrar la ventana */
    ShowWindow(hwnd, SW_SHOWDEFAULT);

    /* Bucle de mensajes, se ejecuta hasta que haya error o GetMessage devuelva FALSE */
    while(TRUE == GetMessage(&mensaje, NULL, 0, 0))
    {
        /* Traducir mensajes de teclas virtuales a mensajes de caracteres */
        TranslateMessage(&mensaje);
        /* Enviar mensaje al procedimiento de ventana */
        DispatchMessage(&mensaje);
    }

    /* Salir con valor de retorno */
    return mensaje.wParam;
}


/*  Esta función es invocada por la función DispatchMessage()  */
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)                  /* manipulador del mensaje */
    {
        case WM_COMMAND:
           switch(LOWORD(wParam)) {
              case CM_PRUEBA:
                 MessageBox(hwnd, _T("Comando: Prueba"), _T("Mensaje de menú"), MB_OK);
                 break;
              case CM_SALIR:
                 MessageBox(hwnd, _T("Comando: Salir"), _T("Mensaje de menú"), MB_OK);
                 PostQuitMessage(0);    /* envía un mensaje WM_QUIT a la cola de mensajes */
                 break;
           }
           break;   
        case WM_DESTROY:
           PostQuitMessage(0);    /* envía un mensaje WM_QUIT a la cola de mensajes */
           break;
        default:                  /* para los mensajes de los que no nos ocupamos */
           return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

void InsertarMenu(HWND hWnd)
{
   HMENU hMenu1, hMenu2;
   
   hMenu1 = CreateMenu();
   hMenu2 = CreateMenu();

   AppendMenu(hMenu2, MF_STRING, CM_PRUEBA, _T("&Prueba"));
   AppendMenu(hMenu2, MF_SEPARATOR, 0, NULL);
   AppendMenu(hMenu2, MF_STRING, CM_SALIR, _T("&Salir"));
   AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu2, _T("&Principal"));
   SetMenu (hWnd, hMenu1);  
}
