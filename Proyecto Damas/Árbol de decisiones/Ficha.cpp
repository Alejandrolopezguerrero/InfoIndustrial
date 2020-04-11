#include "Ficha.h"
#include "glut.h"
#include<math.h>

Estado Ficha::GetEstado()
{
	return estado;
}

void Ficha::SetEstado(Estado est)
{
	estado = est;
}

Tipo Ficha::GetTipo()
{
	return tipo;
}

void Ficha::SetTipo(Tipo tip)
{
	tipo = tip;
}

Color Ficha::GetColor()
{
	return color;
}

void Ficha::SetColor(Color col)
{
	color = col;
}

float Ficha::GetRadio()
{
	return radio;
}

void Ficha::SetRadio(float rad)
{
	radio = rad;
}

void Ficha::DibujaFicha(int i, int j)
{
	float theta;
	glBegin(GL_POLYGON);

	//Color de la ficha
	if (!color){glColor3f(255, 0, 0);} //Pinta de color rojo la ficha (ROJO=0)
	glColor3f(255, 255, 255); //pinta de color blanco la ficha

	//El vector posicion corresponde con coordenadas en el dibujo (x,y).
	//Lo ideal es que fuesen los indices (i,j) del elemento de la matriz del tablero
	//y después, en función del tamaño del dibujo calcular las coordenadas (x,y)
	//algo como:
	//posicion.x=i*DIST_ENTRE_CUADRADOS + DISTANCIA_ENTRE_CUADRADOS/2 
	//posicion.y=-j*DIST_ENTRE_CUADRADOS - DISTANCIA_ENTRE_CUADRADOS/2

	for (int i = 0; i < 360; i++) {
		theta = i * 3.1416 / 180;
		glVertex2f(posicion.x + radio * cos(theta), posicion.y + radio * sin(theta));
	}
	glEnd();
}
