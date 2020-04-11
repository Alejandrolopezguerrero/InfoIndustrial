#include "Mundo.h"
#include "glut.h"

void Esfera::SetColor(unsigned char r, unsigned char g, unsigned char b) { 
	R = r;  
	G = g; 
	B = b; 
} 

void Esfera::SetRadio(float r) { 
	if (r < 0.1F) { 
		r = 0.1F; 
	}
	radio = r; 
}

void Esfera::Dibuja() { 
	glColor3ub(R, G, B);  
	glTranslatef(pos_x, pos_y, pos_z);  
	glutSolidSphere(radio, 20, 20);  
	glTranslatef(-pos_x, -pos_y, -pos_z); 
	glutPostRedisplay();
}

void Esfera::Aumentar() { 
	radio += 0.01f;  
	if (radio > 2)   
		radio = 0.5f; 
}

void Esfera::SetPos(float ix, float iy, float iz) { 
	pos_x = ix;  
	pos_y = iy;
	pos_z = iz;
}
