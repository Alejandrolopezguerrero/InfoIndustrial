#pragma once
#include "Vector2D.h"
class Hombre {
public:
	
	float altura;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	
	Hombre();
	//virtual ~Hombre();
	void Dibuja();
	void Mueve(float t);
};
