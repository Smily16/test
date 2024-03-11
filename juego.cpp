#include<iostream>
#include<cstdlib> //Libreria para generar numeros aleatorios
#include <ctime> // Para obtener el tiempo actual

using namespace std;

//Constantes
const char caracteres[37] ={'q','w','e','r','t','y','u','i','o','p',
						 	'a','s','d','f','g','h','j','k','l','ñ',
						 	'z','x','c','v','b','n','m','1','2','3',
							'4','5','6','7','8','9','0'};
						 
//Definicion de funciones
void dibujar(char arregloDeCaracteres[]);
void aleatorizar(char arregloDeCaracteres[]);

int main(){
    char caracteresDeJuego[5];
	aleatorizar(caracteresDeJuego);		
	
	
	//ESTA LINEA DE AQUI ES SOLO PARA VER LOS CARACTERES
	//Comenta y descomenta para revisar
	/*
	for(int i=0; i<5; i++){
		cout<<"caracter "<<i<<": "<<caracteresDeJuego[i]<<endl;
	}			 
	*/
	
    dibujar(caracteresDeJuego);
    return 0;
}

void dibujar(char AC[]){
	cout<<"+---------------------------------------+"<<endl;
	cout<<"|       |       |       |       |       |"<<endl;
	cout<<"|   "<<AC[0]<<"   |   "<<AC[1]<<"   |   "<<AC[2]<<"   |   "<<AC[3]<<"   |   "<<AC[4]<<"   |"<<endl;
	cout<<"|       |       |       |       |       |"<<endl;
	cout<<"+---------------------------------------+"<<endl;
}

void aleatorizar(char arregloDeCaracteres[]){
	srand(time(NULL)); // Establecer la semilla con el tiempo actual
	for(int i = 0; i<5; i++){
		arregloDeCaracteres[i] = caracteres[rand()%37];
	}
}



