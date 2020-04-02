#include <stdio.h>
#include <string.h>
char cadena[] = "Hola mundo creeeel";

void main(void) {

	char* pos;
	pos = strstr(cadena, "cr");
	strcpy(pos, "cruel");
	printf("%s",cadena);
	printf("Hola mundo");
}
