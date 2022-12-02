/*solicitar 10 numeros por teclado al usuario y 
almacenarlos en una estrutura estatica.
una vez alamacenados los 10 numeros hacer un
meno con las siguientes opciones:

1.) calcular la suma de los 10  numeros y mostrarla
por pantalla al usuario.

2.) calcular la media de todos los numeros y 
mostrarla por pantalla al usuario.

3.) calcular el mayor de los 10 numeros y mostrarlo
por pantalla.*/

#include<iostream>


using namespace std;

int main(){
	int num[10], suma=0, mayor=0;
	float media;
	
//	para digitar los 10 numeros

	cout<<"digita 10 numeros cualquiera\n";

	for(int i=0; i<10; i++){
		
		cin>>num[i];
		
//		para calcular suma

		suma=suma+num[i];
		
	}
	
	cout<<"la suma es: "<<suma<<endl;
	
//	para calcular la media 

	media=suma/10;
	
	cout<<"la media de los numeros degitados son: "<<media;
	
//	para buscar el mayor numero

	for(int i=0; i<10; i++){
		
		if(num[i]>mayor){
			
			mayor=num[i];
			
		}
		
	}
	cout<<"\nel mayor numero es: "<<mayor;



	
	
	
	
	return 0;
}
