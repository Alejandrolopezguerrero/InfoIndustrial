//Alejandro L�pez Guerrero

//Este c�digo analiza una cadena de caracteres dada y devuelve el primer n�mero contenido en ella
//Ejemplo: Lea la cadena "manuel_87550"y extraiga el n�mero, mostr�ndolo por pantalla

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define none 0

long int extraer_primer_numero(const char*);

int main(void) { 
	char cadena[100] = "manuel";;
	sprintf(cadena, "%s_%d", cadena, 87550);
	puts("La cadena a leer es: ");
	puts(cadena);
	printf("El numero en la cadena es: %d", extraer_primer_numero(cadena));
	return 0;
}

long int extraer_primer_numero(const char* str)
{
	char* pos = (char*)str;
	int numeroleido = none;

	for (*pos; *pos != NULL; pos++) {
		if (isdigit(*pos)) {
			numeroleido = strtol(pos, &pos, 10);
			return numeroleido;
		}
	}
}
