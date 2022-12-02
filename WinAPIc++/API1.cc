#include <tchar.h>
#include <windows.h>

/* Aquí es donde va toda la entrada a la ventana.*/
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		/* Tras la destrucción, dile al hilo principal que se detenga */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* Todos los demás mensajes (muchos de ellos) se procesan mediante procedimientos predeterminados */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* La función 'principal' de los programas GUI de Win32: aquí es donde comienza la ejecución */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* Una estructura de propiedades de nuestra ventana*/
	HWND hwnd; /* Un 'HANDLE', de ahí la H, o un puntero a nuestra ventana */
	MSG msg; /* Una ubicación temporal para todos los mensajes. */

	/* poner a cero la estructura y establecer las cosas que queremos modificar */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* Aquí es donde enviaremos mensajes a */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.style		 = CS_DBLCLKS; //Identifica un click dentro de una ventana
	
	/* Blanco, COLOR_WINDOW es solo una #define para un color del sistema, intente Ctrl + clic */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); // cambiar el color de la ventana
	wc.lpszClassName = _T("WindowClass");
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Cargar un icon estándar */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /*usa el nombre "A" para usar el ícon del proyecto */
	wc.lpszMenuName  = NULL; // sirve para crear un menú pero ahora lo dejaré en NULL


	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, _T("Window Registration Failed!"),_T("Error!"),MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,_T("WindowClass"),_T("Hola Mundo"),WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, // x indica el lugar en donde quiere que habramos la ventana en el eje x
		CW_USEDEFAULT, // y indica el lugar en donde quiere que habramos la ventana en el eje y
		640, /* ancho de mi ventana*/
		480, /* altura de mi ventana */
		HWND_DESKTOP, // permite saber si mi ventana va a formar parte del escritorio o de otra ventana
		NULL, //no exite un menú
		hInstance, //recibe parametros y queda así
		NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, _T("Window Creation Failed!"),_T("Error!"),MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	//muestra la ventana:
	ShowWindow (hwnd, nCmdShow);

	/*
		Este es el corazón de nuestro programa donde se procesan todas las entradas y
enviado a WndProc. Tenga en cuenta que GetMessage bloquea el flujo de código hasta que recibe algo, por lo que
este bucle no producirá un uso excesivamente alto de la CPU
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* Si no se recibe ningún error ... */
		TranslateMessage(&msg); /* Traducir códigos clave a caracteres, si están presentes*/
		DispatchMessage(&msg); /* Envíalo a WndProc*/
	}
	return msg.wParam;
}