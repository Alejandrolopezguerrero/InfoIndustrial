//#include<windows.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath> 
#include "glut.h"
#include "ETSIDI.h"
#include "freeglut.h"

#define PX_X 800
#define PX_Y 800

using namespace std;

int c = 0;
int switcher=0;
int checker_selected = 0;
int b_offset = 100;
int c_offset = 50;
int g_m_x;
int g_m_y;
int mx_new;
int my_new;


void init();
void drawSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void drawChecker(int c_x, int c_y);
void OnMouseEvent(int button, int state, int m_x, int m_y);
void checkerboard();

void creacionMenu(void);

void init();

//void display(void) {
//	float colores[6][3] = { { 0.00f, 0.00f, 0.00f}, // 0 - negro   
//	{ 0.06f, 0.25f, 0.13f}, // 1 - verde oscuro   
//	{ 0.10f, 0.07f, 0.33f}, // 2 - azul oscuro   
//	{ 1.00f, 1.00f, 1.00f}, // 3 - blanco
//	{ 0.12f, 0.50f, 0.26f}, // 4 - verde claro   
//	{ 0.20f, 0.14f, 0.66f}, // 5 - azul claro  
//	};
//	glClearColor(colores[iFondo][0], colores[iFondo][1], colores[iFondo][2], 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(colores[iDibujo][0], colores[iDibujo][1], colores[iDibujo][2]);
//	glutWireTeapot(0.5);
//	glFlush();
//	glutSwapBuffers();
//}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(200, 0);
	glutInitWindowSize(PX_X, PX_Y);
	glutCreateWindow("Checkers Board");
	init();
	//glutDisplayFunc(display);
	creacionMenu();
	glutDisplayFunc(checkerboard);
	glutMouseFunc(OnMouseEvent);


	glutMainLoop();
}



void init()
{
	glClearColor(0, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, PX_X, 0, PX_Y);
}

void checkerboard()
{
	GLint x, y;
	int select_checker_x = 0;
	int select_checker_y = 0;

	select_checker_x = g_m_x / 100;
	select_checker_y = g_m_y / 100;
	select_checker_x = trunc(select_checker_x * 100) / 100;
	select_checker_y = trunc(select_checker_y * 100) / 100;
	select_checker_x = select_checker_x * 100;
	select_checker_y = select_checker_y * 100;
	
	if (switcher == 1) {
		drawChecker(select_checker_x + 50, PX_Y - select_checker_y - 50);
		cout << select_checker_x + 50 << ":" << select_checker_y + 50 << endl;
	}
	else if (switcher == 2) {

		cout << select_checker_x + 50 << ":" << select_checker_y + 50 << endl;
		cout << "DOUBLE_CLICK" << endl;
		drawChecker(select_checker_x + 50, PX_Y - select_checker_y - 50);
	}
	else {
		drawSquare(0, 0, PX_X, 0, PX_X, PX_Y, 0, PX_Y);

		for (x = 0; x <= PX_X; x += 100)
		{
			for (y = 0; y <= PX_Y; y += 100)
			{
				if (c == 0 && y < 300) {

					drawChecker(x + c_offset, y + c_offset);
				}
				if (c == 0 && y >= PX_Y - 300) {

					drawChecker(x + c_offset, y + c_offset);
				}
			}
		}
	}
	glutSwapBuffers();
	glEnd;
}

void drawSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	if (c == 0)
	{
		glColor3f(1, 1, 1);
		c = 1;
	}
	else
	{
		glColor3f(0, 0, 0);
		c = 0;
	}

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/main_board.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2i(x1, y1);
	glTexCoord2d(1, 1); glVertex2i(x2, y2);
	glTexCoord2d(1, 0); glVertex2i(x3, y3);
	glTexCoord2d(0, 0); glVertex2i(x4, y4);
	glEnd();
	//glEnable(GL_LIGHTING); 
	glColor3f(1, 0, 0);
	/*glBegin(GL_POLYGON);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glVertex2i(x4, y4);
	glEnd();*/
}

void drawChecker(int c_x,int c_y) {

	float theta;
	int radio = 40;
	glBegin(GL_POLYGON);
	if (checker_selected == 0) {
		glColor3f(1, 0, 0);
	}
	else {
		glColor3f(0, 1, 0);

	}
	for (int i = 0; i < 360; i++) {
		theta = i * 3.1416 / 180;
		glVertex2f(c_x + radio * cos(theta), c_y + radio * sin(theta));
	}
	glEnd();
}

void OnMouseEvent(int button, int state, int m_x, int m_y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		
		g_m_x=m_x;
		g_m_y=m_y;
		

		if (m_x == mx_new && m_y == my_new) {

			switcher = 2;
			checker_selected = 1;
			checkerboard();

		}
		else {
			switcher = 1;
			checker_selected = 0;
			mx_new = m_x;
			my_new = m_y;
			checkerboard();
		}
	}

}
