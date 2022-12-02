#include <iostream>
using namespace std;

int main(){
	
	//variables para guardar el nombre...
	char **nombre;
	string nombreAux;
	int guardatamanio[24];
	int numeroCaracteresNombre; 
	
	//variable para DNI...
	long int *dni;
	
	//variable para edad...
	int *edad;
	
		
	//estructura de hotel 4x6...
	int indicaCuarto[4][6];
	
	//reservando espacio...
	nombre = new char* [24];
		
	for(int i = 0; i < 24; i++){
		
		nombre[i] = new char[30];
		
	}
	
	dni = new long int[24];
	
	edad = new int[24];
	
	int cuentaNombres = -1;
	string respuesta;
	
	//apartando habitacion...
	for(int i = 0; i < 4; i++){
		
		cout << "*********************************************" << endl;
		cout << "\t\tPiso " << i + 1 << ":\n" << endl;
		
		for(int j = 0; j < 6; j++){
			
			cuentaNombres++; 
			
			cout << "> Habitacion " << j + 1 << ":\n" << endl; 
			
			//guardando nombre...
			cout << "\tNombre... ";
			cin >> nombreAux;
			numeroCaracteresNombre = nombreAux.length();
			guardatamanio[cuentaNombres] = numeroCaracteresNombre;

			for(int k = 0; k < numeroCaracteresNombre; k++){
				*( *(nombre + cuentaNombres ) + k) = nombreAux.at(k);
			
			}
			
			//guardando DNI...
			cout << "\tDNI... ";
			cin >> *(dni + cuentaNombres);
			
			//guardando edad...
			cout << "\tEdad... ";
			cin >> *(edad + cuentaNombres);
			
			cout << "Continuar?... (s/n) ";
			cin >> respuesta;
			
			cout << "\n*********************************************" << endl;
			
			if(respuesta=="n") goto salir;
		}
	}
	salir:
		
	system("cls");
		
	cout << "\n\t\tMostrando..." << endl;
	
	int cont = -1; 
	//mostrando...
	for(int i = 0; i < 4; i++){
		
		cout << "*********************************************" << endl;
		
		cout << "\t\tPiso " << i + 1 << ":\n" << endl;
		
		for (int j = 0; j < 6; j++){
			
			cont++;
			
			if(cont <= cuentaNombres){
				
				//mostrando nombres...
				cout << "> Habitacion " << j + 1 << ":\n" << endl; 
				
				cout << "\tNombre... ";				
				for(int k = 0; k < guardatamanio[cont]; k++){
					cout << *( *(nombre + cont) + k);
				}
				cout << endl;
				
				//mostrando DNI...
				cout << "\tDNI... " << *(dni + cont) << endl;
				cout << "\tEdad... " << *(edad + cont) << endl;
				
				cout << "\n*********************************************" << endl;
				
			}else goto salto2;
						
			cout << endl;
		}
		
	}
	
	salto2:
		
	//liberando espacio...
	delete[] edad;
	delete[] dni;
	for(int i = 0; i < 24; i++){
		delete[] nombre[i];
	}
	delete[] nombre;
	
	return 0;
}
