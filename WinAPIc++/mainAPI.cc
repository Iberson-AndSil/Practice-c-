#include <tchar.h>
#include <windows.h>

LRESULT CALLBACK WindowProcedure(HWND ventana1,
                                 UINT MensajeComunica,
                                 WPARAM wParam,
                                 LPARAM lParam)
{  
    static HINSTANCE Instancia;
	switch(MensajeComunica) {
		
		case WM_CLOSE: 

			DestroyWindow(ventana1);
			break;
		
        case WM_CREATE:
            Instancia = ((LPCREATESTRUCT)lParam)->hInstance;

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