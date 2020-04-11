#pragma once
#include "Vector2D.h"
class Pared {
private:

	unsigned char rojo, verde, azul;
	Vector2D limite1, limite2;
public:
	Pared();
	//virtual ~Pared();
	void Dibuja();
	void SetColor(unsigned char R, unsigned char G, unsigned char B);
	void SetLimit(float lim1X, float lim1Y, float lim2X, float lim2Y);
};