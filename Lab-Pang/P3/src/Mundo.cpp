#include "Mundo.h"
#include "glut.h"

Mundo::Mundo() {
    x_ojo = 0;
    y_ojo = 7.5;
    z_ojo = 30;
}

void Mundo::Inicializa() {
    x_ojo = 0;  
    y_ojo = 7.5;  
    z_ojo = 30;

    esfera.SetColor(0, 0, 255);
    esfera.SetRadio(1.5f);
    esfera.SetPos(2.0, 4.0);

    bonus.posicion.x = 5.0f;  
    bonus.posicion.y = 5.0f;

    disparo.posicion.x = -5.0f;  
    disparo.posicion.y = 0.0f;

    disparo.origen.x = -5.0f;
    disparo.origen.y = 0.0f;

    plataforma.SetLimit(-5.0f,9.0f, 5.0f, 9.0f);
    plataforma.SetColor(255, 0, 0);
}

void Mundo::Dibuja() {
    gluLookAt(x_ojo, y_ojo, z_ojo, 
        0.0, y_ojo, 0.0,          
        0.0, 1.0, 0.0);         
    esfera.Dibuja();  
    caja.Dibuja();  
    hombre.Dibuja();  
    disparo.Dibuja(); 
    plataforma.Dibuja();  
    bonus.Dibuja(); 
} 

void Mundo::Mover() { 
    hombre.Mueve(0.025f);  
    esfera.Mueve(0.025f);  
    bonus.Mueve(0.025f);  
    disparo.Mueve(0.025f); 
}