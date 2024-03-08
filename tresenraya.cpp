#include <iostream>
using namespace std;

void dibujar(char caracter[]);
void jugar(char posicion[],char ficha);
int resultado(char caracter[]);

int main(){
    char marcas[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int opc = 0;
    while(true){
   		//Aqui jugara el jugador 1 poniendo la X
        jugar(marcas,'X');
        if(resultado(marcas) == 1){ //Aqui comprobaremos si el tablero se lleno o no
			break;
		}
        dibujar(marcas);//Y ahora dibujaremos el tablero

        jugar(marcas,'O');
        if(resultado(marcas) == 1){
			break;
		}
        dibujar(marcas);
    }
    return 0;
}

void dibujar(char caracter[]){
    cout<<                "         |    "<<             "     |    "<<endl;
    cout<<"     "<<caracter[0]<<"   |    "<<caracter[1]<< "    |   "<<caracter[2]<<endl;
    cout<<	              "  _______|"<<             "_________|________"<<endl;
    cout<<                "         |    "<<             "     |    "<<endl;
    cout<<"     "<<caracter[3]<<"   |    "<<caracter[4]<< "    |   "<<caracter[5]<<endl;
    cout<<                "  _______|"<<             "_________|________"<<endl;
    cout<<                "         |    "<<             "     |    "<<endl;
    cout<<"     "<<caracter[6]<<"   |    "<<caracter[7]<< "    |   "<<caracter[8]<<endl;
    cout<<                "         |    "    <<         "     |    "<<endl;


}

void jugar(char posicion[], char ficha){
	int opc = 0;
	cout<<"Seleccione una posicion para poner la ficha "<<ficha<<": ";
    cin>>opc;
    
    //Compruebo que el numero que ingrese este entre 1 y 9
    while(opc < 1 || opc > 9){
        cout<<"Su numero tiene que estar entre el 1-9\ningrese su numero: ";
        cin>>opc; 
    }
    opc--; //Ajusto el indice
    
    //Compruebo que la casilla no este ocupada ya
    while(posicion[opc] != ' '){
        cout<<"ese espacio ya esta ocupado, porfavor elija otro numero: ";
        cin>>opc;
        opc--;
    }
    
    //Asigno la ficha al tablero
    posicion[opc] = ficha;
    system("cls");
    
}

int resultado(char caracter[]){
	// Comprobación de filas
    for (int i = 0; i < 3; ++i) {
        if (caracter[i * 3] != ' ' && caracter[i * 3] == caracter[i * 3 + 1] && caracter[i * 3 + 1] == caracter[i * 3 + 2]) {
            dibujar(caracter);
            cout << "¡El jugador " << caracter[i * 3] << " ha ganado!" << endl;
            return 1; // Retorna 1 si hay un ganador
        }
    }

    // Comprobación de columnas
    for (int i = 0; i < 3; ++i) {
        if (caracter[i] != ' ' && caracter[i] == caracter[i + 3] && caracter[i + 3] == caracter[i + 6]) {
            dibujar(caracter);
            cout << "¡El jugador " << caracter[i] << " ha ganado!" << endl;
            return 1; // Retorna 1 si hay un ganador
        }
    }
    
    // Comprobación de diagonales
    if (caracter[0] != ' ' && caracter[0] == caracter[4] && caracter[4] == caracter[8]) {
        dibujar(caracter);
        cout << "¡El jugador " << caracter[0] << " ha ganado!" << endl;
        return 1; // Retorna 1 si hay un ganador
    }
    if (caracter[2] != ' ' && caracter[2] == caracter[4] && caracter[4] == caracter[6]) {
        dibujar(caracter);
        cout << "¡El jugador " << caracter[2] << " ha ganado!" << endl;
        return 1; // Retorna 1 si hay un ganador
    }
	
	//aqui cuento cuantos espacios tomados hay en el vector
	int contador = 0;
	for(int i = 0; i<9; i++){
		if(caracter[i] != ' '){
			contador++;
		}
	}
	
	//Si hay 9 espacios tomados, la funcion retornara un 1, dando fin al programa en el main
	if(contador == 9){
		dibujar(caracter);
		cout<<"¡Empate!";
		return 1;
	}
	
	//caso contrario mandara 0 para seguir normal
	return 0;
}
