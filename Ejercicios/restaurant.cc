#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

class restaurant{

    private:

        struct 
        {
            string contrasena;
            string NombreYApellidos;
        }Administrador, *ptr_admi = &Administrador;

        struct
        {
            char NombrePlatillo[40];
            char DescripcionPlatillo[80];
            float Precio;    
            }Platillos[10];

    protected:

        int cantidad;

    public:
        void MenuPrincipal();
        void CuentAdministrador();
        void OpcionesAdministrador();
        void ConfiguracionPlatillos();
        void DigitarPlatillos();
        void MostrarPlatillos();
        void AgregarPlatillo();
        void Cliente();
};

void restaurant::MenuPrincipal(){
    int opcion;
    cout << "\t\t____________" << endl;
    cout << "\t\t|RESTAURANT|" << endl;
    cout << "\t\t------------" << endl << endl;
    cout << "................................................." << endl;
    cout << "Elegir... '1' o '2'\n" << endl;
    cout << "1 =) Administrador\n";
    cout << "2 =) Cliente\n" << endl;
    cout << "\t-> ";
    while (opcion != 2 && opcion !=1)
    {
        cin >> opcion;
        if(opcion != 2 && opcion !=1){
            cout << "Error... " << endl;
        }
    }    
    cout << "................................................." << endl;
    switch (opcion)
    {
        case 1:
            OpcionesAdministrador();
            break;
        case 2:
            break;
    }
}

void restaurant::OpcionesAdministrador(){
    int opc;
    system("cls");
    cout << "\t\t_______________" << endl;
    cout << "\t\t|ADMINISTRADOR|" << endl;
    cout << "\t\t---------------" << endl << endl;
    cout << "................................................." << endl;
    cout << "Elegir... '1' o '2'\n" << endl;
    cout << "1 =) Configuracion de Platillos\n";
    cout << "2 =) Configuracion de Cuenta\n";
    cout << "3 =) Atras\n" << endl;
    cout << "\t-> ";
    while (opc != 2 && opc !=1 && opc !=3)
    {
        cin >> opc;
        if(opc == 3){
        	system("cls");
        	MenuPrincipal();
		}
        if(opc != 2 && opc !=1 && opc !=3){
            cout << "Error... " << endl;
        }
    }    
    cout << "................................................." << endl;
    switch (opc)
    {
        case 1:
            ConfiguracionPlatillos();
            break;
        case 2:
            break;
    }
}
void restaurant::ConfiguracionPlatillos(){

    int opc;
    system("cls");
    cout << "\t\t____________________________" << endl;
    cout << "\t\t|CONFIGURACION DE PLATILLOS|" << endl;
    cout << "\t\t----------------------------" << endl << endl;
    cout << "................................................." << endl;
    cout << "Elegir... '1', '2',..., '6'\n" << endl;
    cout << "1 =) Digitar Platillos\n" << endl;
    cout << "2 =) Mostrar Platillos\n" << endl;
    cout << "3 =) Agregar Platillo\n" << endl;
    cout << "4 =) Eliminar Platillo\n" << endl;
    cout << "5 =) Formatear Informacion\n" << endl;
    cout << "6 =) Editar Platillo\n" << endl;
    cout << "7 =) Atras\n" << endl;
    cout << "\t-> ";
    while (opc < 1 || opc > 7)
    {
        cin >> opc;
        if(opc == 7){
    		system("cls");
    		OpcionesAdministrador();
		}
        if(opc < 1 || opc > 6){
            cout << "Error... " << endl;
        }
    }    
    cout << "................................................." << endl;
    switch (opc)
    {
        case 1:
        	system("cls");
            DigitarPlatillos();
            break;
        case 2:
        	system("cls");
            MostrarPlatillos();
            break;
        case 3:
        	system("cls");
            AgregarPlatillo();
            break;

    }

}

void restaurant::DigitarPlatillos(){
    string opcion;
    int i = 1, OpcionVolver;
    cantidad = 0;
    cout << "\t\t___________________" << endl;
    cout << "\t\t|DIGITAR PLATILLOS|" << endl;
    cout << "\t\t-------------------" << endl << endl;
    cout << "................................................." << endl;
    do
    {
    	opcion.clear();
        cout << endl;
        fflush(stdin);
        cout << "\tPlatillo " << i << "... "<< endl << endl ;
        cout << "=) Nombre Platillo: ";
        cin.getline(Platillos[cantidad].NombrePlatillo, 40, '\n');
        cout << "=) Precio:          ";
        cin >> Platillos[cantidad].Precio;
        fflush(stdin);
        cout << "=) Descripcion:        ";
        cin.getline(Platillos[cantidad].DescripcionPlatillo, 80, '\n');
        cout << endl;
        cout << "\t-> Seguir Digitando? si/no... ";
        while (opcion != "si" && opcion != "no" )
        {
        	fflush(stdin);
            cin >> opcion;
            if (opcion != "si" && opcion != "no" )
            {
                cout << "Error... " << endl;
            }
            if (opcion == "no")
            {
            	cantidad++;
                ConfiguracionPlatillos();
            }
        }
        cantidad++;
        i++;
    } while (opcion == "si");
    cout << "................................................." << endl;
}

void restaurant::MostrarPlatillos(){
    cout << "\t\t___________________" << endl;
    cout << "\t\t|MOSTRAR PLATILLOS|" << endl;
    cout << "\t\t-------------------" << endl << endl;
    cout << "................................................." << endl;
    for (int i = 0; i < cantidad; i++)
    {
        cout << "*********************************************" << endl;
        cout << "\tPlatillo " << i + 1 << "... "<< endl << endl ;
        cout << "=) Nombre Platillo: " << Platillos[i].NombrePlatillo << endl;
        cout << "=) Precio:          " << Platillos[i].Precio << endl;
        cout << "=) Descripcion:     " << Platillos[i].DescripcionPlatillo << endl;
        cout << "*********************************************" << endl;
    }
    cout << "................................................." << endl;
}

void restaurant::AgregarPlatillo(){
    string op;
    cantidad++;
    cout << "\t\t___________________" << endl;
    cout << "\t\t|AGREGAR PLATILLOS|" << endl;
    cout << "\t\t-------------------" << endl << endl;
    cout << "................................................." << endl;
    do
    {
        cout << "=) Nombre Platillo: ";
        cin >> Platillos[cantidad].NombrePlatillo;
        cout << "=) Precio:          ";
        cin >> Platillos[cantidad].Precio;
        cout << "Descripcion:        ";
        cin >> Platillos[cantidad].DescripcionPlatillo;
        cout << endl;
        cout << "\t-> Seguir Digitando? si/no... ";

        while (op != "si" && op != "no" )
        {
            cin >> op;
            if (op != "si" && op != "no" )
            {
                cout << "Error... " << endl;
            } 
            if(op == "no"){
            	cantidad++;
            	ConfiguracionPlatillos();
        	}
        }
        if(op == "si"){
            cantidad++;
        }
        
    } while (op == "si");
    cout << "................................................." << endl;
    
}

int main(){

    restaurant ob;
    ob.MenuPrincipal();

    return 0;
}