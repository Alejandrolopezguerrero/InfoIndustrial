#pragma once
#include "Vector2D.h"
class Bonus {
public:
	
	float lado;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

	Bonus();
	//virtual ~Bonus();
	void Dibuja();
	void Mueve(float t);
};