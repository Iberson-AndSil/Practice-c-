#include <tchar.h>
#include <windows.h>

#define UNID 100

LRESULT CALLBACK WindowProcedure(HWND ventana1,
                                 UINT MensajeComunica,
                                 WPARAM wParam,
                                 LPARAM lParam)
{ 
    HWND ctr; 
    static HINSTANCE Instancia;
    int nOpc = 4;
    const char* Operaciones[] = {
        "Multiplicacion", "Division", "Suma", "Resta"
    };
    
	switch(MensajeComunica) {
		
		case WM_CLOSE: {

			DestroyWindow(ventana1);
			break;
		}

        case WM_CREATE:
            Instancia = ((LPCREATESTRUCT)lParam)->hInstance;
            CreateWindow    (_T("COMBOBOX"), _T("elige"), 
                            CBS_DROPDOWNLIST|WS_CHILD|WS_VISIBLE, 
                            120, 10, 100, 500, 
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