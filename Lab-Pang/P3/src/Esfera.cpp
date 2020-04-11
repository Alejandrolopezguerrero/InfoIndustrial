#include "Esfera.h"
#include "glut.h"

Esfera::Esfera() {
	rojo = verde = azul = 255;
	radio = 0.2f;
	aceleracion.y = -9.8f;
}

void Esfera::Dibuja() {

	glColor3ub(rojo, verde, azul);  
	glTranslatef(posicion.x, posicion.y, 0);  
	glutSolidSphere(radio, 20, 20);  
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void Esfera::Mueve(float t) {
	posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.x = velocidad.x + aceleracion.x * t;
	velocidad.y = velocidad.y + aceleracion.y * t;
}

void Esfera::SetColor(unsigned char R, unsigned char G, unsigned char B) {
	rojo = R;
	verde = G;
	azul = B;
}

void Esfera::SetPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

void Esfera::SetRadio(float newRadio) {
	radio = newRadio;
}