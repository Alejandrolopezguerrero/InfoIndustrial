#include "Pared.h"
#include "glut.h"

void Pared::Dibuja() { 
	glDisable(GL_LIGHTING);  
	glColor3ub(rojo, verde, azul);  
	glBegin(GL_POLYGON);   
		glVertex3d(limite1.x, limite1.y, 10);   
		glVertex3d(limite2.x, limite2.y, 10);   
		glVertex3d(limite2.x, limite2.y, -10);   
		glVertex3d(limite1.x, limite1.y, -10);  
	glEnd();  
	glEnable(GL_LIGHTING); 
}

void Pared::SetColor(unsigned char R, unsigned char G, unsigned char B) {
	rojo = R;
	verde = G;
	azul = B;
}

void Pared::SetLimit(float lim1X, float lim1Y, float lim2X, float lim2Y) {
	limite1.x = lim1X;
	limite1.y = lim1Y;
	limite2.x = lim2X;
	limite2.y = lim2Y;
}

Pared::Pared() {

}