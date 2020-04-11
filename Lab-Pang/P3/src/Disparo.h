#pragma once
#include "Vector2D.h"
class Disparo{
public:
	
	float radio;
	Vector2D posicion;
	Vector2D origen;
	Vector2D velocidad;
	Vector2D aceleracion;

	Disparo();
	//virtual ~Disparo();
	void Dibuja();
	void Mueve(float t);
};