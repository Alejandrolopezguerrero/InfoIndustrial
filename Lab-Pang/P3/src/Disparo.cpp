#include "Disparo.h"
#include "glut.h"

Disparo::Disparo() {
	radio = 0.25f;
	velocidad.x = 0;
	velocidad.y = 1.0f;
	aceleracion.x = 0.0f;
	aceleracion.y = 0.0f;
}

void Disparo::Dibuja() {
	glColor3f(0.0f, 1.0f, 1.0f);  
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glVertex3f(origen.x, origen.y, 0);
	glVertex3f(posicion.x, posicion.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glPushMatrix();  
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);  
	glPopMatrix();
}

void Disparo::Mueve(float t) {
	posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;  
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;  
	velocidad.x = velocidad.x + aceleracion.x * t;  
	velocidad.y = velocidad.y + aceleracion.y * t;
}