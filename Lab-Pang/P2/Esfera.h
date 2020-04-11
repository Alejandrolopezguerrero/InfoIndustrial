#ifndef _ESFERA_H 
#define _ESFERA_H 

class Esfera {
private:
	float pos_x;
	float pos_y;
	float pos_z;
	float radio;
	unsigned char R;
	unsigned char G;
	unsigned char B;
public:
	void SetColor(unsigned char r, unsigned char g, unsigned char b);
	void SetRadio(float r);
	void SetPos(float ix, float iy, float iz);
	void Dibuja();
	void Aumentar();
};

#endif