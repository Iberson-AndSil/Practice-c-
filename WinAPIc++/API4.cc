#include <tchar.h>
#include <windows.h>
#include <string.h>
#include <stdio.h>

#define CALCULAR 100
#define SALIR 101
#define UNID 102
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
    int nOpc = 4;
    const char* Operaciones[] = {
        "Multiplicacion", "Division", "Suma", "Resta"
    };

	switch(MensajeComunica) {
		
		case WM_DESTROY :
             PostQuitMessage(0);  

             break;

        case WM_CREATE:
            Instancia = ((LPCREATESTRUCT)lParam)->hInstance;
            controles = CreateWindow    (_T("STATIC"), _T("TABLA DEL "), 
                                        SS_RIGHT|WS_VISIBLE|WS_CHILD, 
                                        10, 10, 100, 22, ventana1, 
                                        (HMENU)-1, Instancia,
                                         NULL);
               
            controles = CreateWindowEx  (0,_T("EDIT"), _T(""), 
                                        ES_LEFT|ES_NUMBER|WS_BORDER|WS_CHILD|WS_VISIBLE, 
                                        110, 10, 50, 22, ventana1, 
                                        (HMENU)DIGITA, Instancia, 
                                        NULL);
                
            controles = CreateWindowEx  (0,_T("BUTTON"), _T("Calcular"), 
                                        BS_CENTER|BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE, 
                                        165, 10, 100, 22, ventana1, 
                                        (HMENU)CALCULAR, Instancia, 
                                        NULL);

            controles = CreateWindowEx  (0,_T("BUTTON"), _T("Salir"), 
                                        BS_CENTER|BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE, 
                                        165, 35, 100, 22, ventana1, 
                                        (HMENU)SALIR, Instancia, 
                                        NULL);
             
            controles = CreateWindow    (_T("STATIC"), _T(""), 
                                        ES_LEFT|WS_BORDER|WS_CHILD|WS_VISIBLE, 
                                        10, 35, 150, 270, ventana1, 
                                        (HMENU)RESUL, Instancia, 
                                        NULL);
            controles = CreateWindow    (_T("COMBOBOX"), _T("elige"), 
                                        CBS_DROPDOWNLIST|WS_CHILD|WS_VISIBLE, 
                                        165, 60, 100, 500, 
                                        ventana1, (HMENU)UNID, Instancia,
                                        NULL);
            for (int i = 0; i < nOpc; i++)
            {
                SendDlgItemMessage  (ventana1, UNID, 
                                    CB_ADDSTRING, 0,
                                     (LPARAM)Operaciones[i]);
            }
            SendDlgItemMessage  (ventana1, UNID, CB_SETCURSEL,
                                (WPARAM)1, (LPARAM)0);
        break;
        case WM_COMMAND:

            switch (LOWORD(wParam))
            {

            case CALCULAR:

                int itemIndice, item;
                char *cad;
                memset(cad, 0, item); //memset libera la memoria
                itemIndice = SendMessage    (ventana1,
                                            CB_GETCURSEL, // CB_GETCURSEL: recupera el indice del elemento
                                            0,0);
                
                item = SendMessage  (ventana1, CB_GETLBTEXTLEN,  //CB_GETLBTEXTLEN: Obtiene longitud en caracteres de cad
                                    (WPARAM)itemIndice, (LPARAM)cad);
                cad = (char*)malloc(item+1); //con malloc damos una porción de memoria
                SendMessage (ventana1, CB_GETLBTEXT, (WPARAM)itemIndice, //CB_GETLBTEXT: obtiene una cadena en cad
                            (LPARAM)cad);

                numero = GetDlgItemInt(ventana1, DIGITA, &exito,TRUE); //Obtener numero
                if ((strcmp(cad, "Suma")!=0))
                {
                    if (exito != TRUE)
                    {
                        MessageBox(ventana1, _T("Digitar Numero"), _T("ERROR"), MB_OK);
                        SetFocus(GetDlgItem(ventana1, DIGITA)); 
                    }else{
                        char Resultado[50] = {0};
                        char Tabla[500] = {0};
                        
                        for (int i = 1; i <= 12; i++)
                        {
                            sprintf(Resultado, "%d + %d = %d\n", numero, i, i+numero);
                            strcat(Tabla, Resultado);
                        }
                        //memset(Tabla, 0, 500);
                    SetDlgItemText(ventana1, RESUL, Tabla);
                    }
                    break;
                }else if((strcmp(cad, "Multiplicacion")!=0))
                {
                    if (exito != TRUE)
                    {
                        MessageBox(ventana1, _T("Digitar Numero"), _T("ERROR"), MB_OK);
                        SetFocus(GetDlgItem(ventana1, DIGITA)); 
                    }else{
                        char Resultado[50] = {0};
                        char Tabla[500] = {0};

                        for (int i = 1; i <= 12; i++)
                        {
                            sprintf(Resultado, "%d x %d = %d\n", numero, i, i*numero);
                            strcat(Tabla, Resultado);
                        }
                    SetDlgItemText(ventana1, RESUL, Tabla);
                    }
                    break;
                }               
 
                break;
            case SALIR:
                if (MessageBox(ventana1, _T("Seguro que quieres salir?"), _T("Salir! "), MB_OKCANCEL) == IDOK)
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
    estilo1.hCursor = LoadCursor(NULL, IDC_ARROW);
    estilo1.lpszMenuName = NULL;
    estilo1.cbClsExtra = 0;
    estilo1.cbWndExtra = 0;
    estilo1.hbrBackground = (HBRUSH)COLOR_WINDOW;

	if(!RegisterClassEx(&estilo1)) 
    {
		return 0;
	}

	ventana1 = CreateWindowEx   (0, _T("Ventana"),
                              _T("TRABAJO"),
                              WS_OVERLAPPEDWINDOW | WS_BORDER,
                              400,
                              70,
                              300,
                              400,
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