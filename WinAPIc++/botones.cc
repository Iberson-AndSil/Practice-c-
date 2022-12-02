#include <tchar.h>
#include <windows.h>
#define bt1 101
#define bt2 102
HWND boton1;
HWND boton2;

LRESULT CALLBACK WndProc	(HWND hwnd, 
							UINT Message, 
							WPARAM wParam, 
							LPARAM lParam) 
{
	switch(Message) {
		
		case WM_DESTROY: 

			PostQuitMessage(0); // boton "x" para cerrar el programa
			break;

        case WM_CREATE:  

            boton1 = CreateWindowEx	(0, _T("button"), 
									_T("Aceptar"), 
									WS_VISIBLE|WS_CHILD|0, 
									0, 0, 80, 25, hwnd, 
									(HMENU)bt1, 0, 0);
			//bt1 es un identificador
            boton2 = CreateWindowEx	(0, _T("button"), 
									_T("Cancelar"), 
									WS_VISIBLE|WS_CHILD|0, 
									0, 30, 80, 25, hwnd, 
									(HMENU)bt2, 0, 0);
            break;

		case WM_COMMAND:

			if(LOWORD(wParam) == bt1){
				MessageBox	(NULL,
							_T("Este es un mensaje de prueba, modifiquelo."), 
							_T("Alerta Codigazo"), 
							MB_OKCANCEL | MB_DEFBUTTON2);

			}
			else{
				PostQuitMessage(0);
			}
			break;
		
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain	(HINSTANCE hInstance, 
					HINSTANCE hPrevInstance, 
					LPSTR lpCmdLine, 
					int nCmdShow) 
{
	WNDCLASSEX wc; 
	HWND hwnd; 
	MSG msg; 

	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; 
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = _T("WindowClass");
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); 
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); 
	if(!RegisterClassEx(&wc)) 
	{
		MessageBox	(NULL, 
					_T("Window Registration Failed!"),
					_T("Error!"),
					MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx	(WS_EX_CLIENTEDGE,
							_T("WindowClass"),
							_T("Hola Mundo"),
							WS_VISIBLE|WS_OVERLAPPEDWINDOW,
							CW_USEDEFAULT, /* x */
							CW_USEDEFAULT, /* y */
							640, /* ancho */
							480, /* altura */
							NULL,
							NULL,
							hInstance,
							NULL);

	if(hwnd == NULL) 
	{
		MessageBox	(NULL, 
					_T("Window Creation Failed!"),
					_T("Error!"),
					MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	while(GetMessage(&msg, NULL, 0, 0) > 0) 
	{ 
		TranslateMessage(&msg);
		DispatchMessage(&msg); 
	}
	return msg.wParam;
}