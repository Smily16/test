#include<iostream>
#include<cstdlib> //Libreria para generar numeros aleatorios
#include <ctime> // Para obtener el tiempo actual
using namespace std;

//Definicion de funciones
void dibujar(char arregloDeCaracteres[]);
void aleatorizar(char arregloDeCaracteres[]);
short menu(short &opc);

int main(){
	system("color 0");
    char caracteresDeJuego[5];
    short opc;
    
    do{ 	
	    switch(menu(opc)){
	    	case 0:
	    	break;
	    	
	    	case 1:
			aleatorizar(caracteresDeJuego);	
			dibujar(caracteresDeJuego);
			break;
	    }
    }while(opc != 0);

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
	
	//establesco el caracter usando el codigo ascii, que desde el 97-122 son las
	//letras minusculas del abecedario
	for(int i = 0; i<5; i++){
		//Rand()%26 genera un numero aleatorio entre 0-25
		arregloDeCaracteres[i] = 97+rand()%26;
	}
}

short menu(short &opc){
	cout<<"############Juego de memoria############"<<endl;
	cout<<"1. Jugar"<<endl;
	cout<<"0. Salir"<<endl;
	cin>>opc;
	return opc;
}



