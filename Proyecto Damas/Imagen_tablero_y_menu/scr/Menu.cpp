#include "glut.h"
#include "freeglut.h"

int iDibujo = 3;
int iFondo = 0;

void creacionMenu(void);
void onMenu(int opcion);

typedef enum {
	FONDO1, FONDO2, FONDO3, FONDO4, DIBUJO1, DIBUJO2, DIBUJO3, DIBUJO4
} opcionesMenu;

void creacionMenu(void) {
	int menuFondo, menuOpciones, menuPrincipal;
	menuFondo = glutCreateMenu(onMenu);
	glutAddMenuEntry("Negro", FONDO1);
	glutAddMenuEntry("Verde oscuro", FONDO2);
	glutAddMenuEntry("Azul oscuro", FONDO3);

	menuOpciones = glutCreateMenu(onMenu);
	glutAddMenuEntry("Pantalla completa", DIBUJO1);
	glutAddMenuEntry("Salir de pantalla completa", DIBUJO2);

	menuPrincipal = glutCreateMenu(onMenu);
	glutAddSubMenu("Color de fondo", menuFondo);
	glutAddSubMenu("Opciones ", menuOpciones);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutSetMenuFont(menuPrincipal, GLUT_BITMAP_9_BY_15);


}



void onMenu(int opcion) {
	switch (opcion) {
	case FONDO1:
		iFondo = 0;
		break;
	case FONDO2:
		iFondo = 1;
		break;
	case FONDO3:
		iFondo = 2;
		break;
	case DIBUJO1:
		iDibujo = 3;
		break;
	case DIBUJO2:
		iDibujo = 4;
		break;
	case DIBUJO3:
		iDibujo = 5;
		break;
	}

	glutPostRedisplay();
}