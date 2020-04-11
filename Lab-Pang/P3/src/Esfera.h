#pragma once
#include "Vector2D.h"
class Esfera {
private:
	unsigned char rojo, verde, azul;
	float radio;
	Vector2D posicion, velocidad, aceleracion;
public:
	Esfera();
	//virtual ~Esfera();
	void Dibuja();
	void Mueve(float);
	
	void SetColor(unsigned char R, unsigned char G, unsigned char B);
	void SetPos(float x, float y);
	void SetRadio(float newRadio);
};