#include "Mundo.h"
#include <math.h>
#include "../include/glut.h"

void Mundo::RotarOjo() {
	float theta;
	const double d = sqrt((pow(pos_vista_x,2) + (pow(pos_vista_z,2))));
	theta = atan2(pos_vista_z, pos_vista_x);
	theta += 0.01;
	pos_vista_x = d * cos(theta);
	pos_vista_z = d * sin(theta); 
}
void Mundo::Inicializar() {
	esfera1.SetColor(255, 0, 0);
	esfera1.SetPos(0, 0, 0);
	esfera1.SetRadio(1);
	esfera2.SetColor(0, 255, 255);
	esfera2.SetPos(3, 0, 0);
	esfera2.SetRadio(1);
		
	pos_vista_x = 15;
	pos_vista_y = 15;
	pos_vista_z = -15;
}
void Mundo::Dibuja() {
	gluLookAt(pos_vista_x, pos_vista_y, pos_vista_z,  // posicion del ojo
		0, 0, 0,     // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el código de dibujo
	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 0);
	glVertex3f(5.0f, 0.0f, 5.0f);
	glColor3ub(255, 0, 0);
	glVertex3f(5.0f, 0.0f, -5.0f);
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0f, 0.0f, -5.0f);
	glColor3ub(255, 255, 0);
	glVertex3f(-5.0f, 0.0f, 5.0f);
	glEnd();

	glEnable(GL_LIGHTING);
	glTranslatef(0, 0, 0);
	glColor3ub(0, 255, 0);
	glutSolidTorus(1, 5.5, 30, 30);
	esfera1.Dibuja();
	esfera2.Dibuja();
}

void Mundo::Mueve() {
	RotarOjo();
	esfera1.Aumentar();
}
void Mundo::Tecla(unsigned char key)
{
	unsigned char r = 0, g = 0, b = 0, aux = 0;
	switch (key) {
	case 'r':
	case 'R':
		r = 255;
		break;
	case 'g':
	case 'G':
		g = 255;
		break;
	case 'b':
	case'B':
		b = 255;
		break;
	default:
		aux = 1;
	}
	if (aux != 1) {
		esfera1.SetColor(r, g, b);
	}
}
