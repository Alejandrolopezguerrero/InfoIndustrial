#pragma once
#include "Caja.h" 
#include "Hombre.h"  
#include "Esfera.h"  
#include "Bonus.h"  
#include "Disparo.h" 
class Mundo   { 
public:  
	Disparo disparo;  
	Esfera esfera;  
	Hombre hombre;  
	Caja caja;  
	Bonus bonus;  
	Pared plataforma; 
	float x_ojo, y_ojo, z_ojo;

	Mundo();
	void Inicializa();
	void Mover();
	void Dibuja();
}; 