#include "Caja.h"
#define ANCHO 20
#define ALTO 15

Caja::Caja() {

	suelo.SetLimit(-ANCHO/2, 0, ANCHO/2, 0);
	techo.SetLimit(-ANCHO/2, ALTO, ANCHO/2, ALTO);
	pared_izda.SetLimit(-ANCHO/2, 0, -ANCHO/2, ALTO);
	pared_drcha.SetLimit(ANCHO/2, 0, ANCHO/2, ALTO);

	suelo.SetColor(0, 150, 0);
	techo.SetColor(0, 180,0);
	pared_izda.SetColor(0,240, 0);
	pared_drcha.SetColor(0, 240, 0);

}

void Caja::Dibuja() {
	suelo.Dibuja();  
	techo.Dibuja();  
	pared_izda.Dibuja();  
	pared_drcha.Dibuja();
}