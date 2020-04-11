#include <iostream>
#define N 8 //Dimensión máxima del tablero

//El siguiente código permite la conversión entre las coordenadas de
//una casilla y el número asociado a esa.
//Está pensado para un tablero de 8x8 con la esquina superior 
//izquierda con casilla blanca.

using namespace std;

int eq_coord_a_casilla(int i, int j);
int eq_casilla_a_coord(int casilla, int& fila, int& columna);

//Equvalencia de coordenadas en tablero a casilla numérica. 
//Inicio en (0,0) esquina sup. izda casilla blanca.

inline int eq_coord_a_casilla(int posX, int posY) {
	int casilla = 0, num;
	if ((posX % 2 == 0 && posY % 2 == 0) || (posX % 2 == 1 && posY % 2 == 1)) {
		cerr << "Casilla blanca. No tiene numero asignado" << endl;
		return 0;
	}
	else {
		//Algoritmo de conversión entre coordenadas y casillas
		casilla = ((4 * posX) + 1) + ((posY - (1 * ((posX + 1) % 2))) / 2);

		return casilla;
	}
}

int eq_casilla_a_coord(int casilla, int& fila, int& columna) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j=((i+1)%2); j <N; j+=2) {
			if (casilla==eq_coord_a_casilla(i,j)) {
				fila = i;
				columna = j;
				return 0;
			}
		}
	}
	fila = 0, columna = 0;
	return 1;
	
}

int main() {

	int i = 7, j = 6, casilla, k,l;
	cout << "Introduce fila y columna (Casilla inicial (0,0) blanca): " << endl;
	cin >> i >> j;
	casilla = eq_coord_a_casilla(i, j);
	cout << "Casilla "<<casilla << endl;
	eq_casilla_a_coord(casilla, k, l);
	cout << "Fila: " << k << " Columna: " << l << endl;
}
