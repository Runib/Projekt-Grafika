#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include <math.h>
#include "dron.h"
#include "sterowanie.h"
#include "glm.h"

#define KEY_ESCAPE 27
#define GL_PI 3.14


dron dronek;

typedef struct {
	int width;
	int height;
	char* title;

	float field_of_view_angle;
	float z_near;
	float z_far;
} glutWindow;

float g_rotation;
glutWindow win;
sterowanie ster;
GLMmodel *stadion;

//funkcja powodujaca zatrzymywanie sie drona i wracanie do normalnej pozycji
void TimerFunction(int value) {
	dronek.nachyl = dronek.nachyl*0.9;


	ster.szybkosc = ster.szybkosc*0.98;
	dronek.naboki = dronek.naboki*0.9;
	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}

//import z blendera
void stad() {
	if (!stadion) {
		stadion = glmReadOBJ("nowy.obj");
		if (!stadion) exit(0);
		glmFacetNormals(stadion);
		glmVertexNormals(stadion, 90.0);
	}
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Torus.003");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Torus.002");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Torus.001");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Torus");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.012_Cylinder.014");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.013");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.012");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.011");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.010");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.009");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.008");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.011_Cylinder.013");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.010_Cylinder.012");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.009_Cylinder.011");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.008_Cylinder.010");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.007");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.006");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.005");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.004");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.003");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.002");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.001");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.007");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.006");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.005");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.004");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Plane.001_Plane.002");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.003");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.002");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.001");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube");
	glmDraw(stadion, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Plane");
	
	glPushMatrix();
	glPopMatrix();

}
void collis();
bool collision = false; //do kolizji, mozliwe ze do usuniecia
void display()
{

	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_POLYGON_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_ONE);
	glEnable(GL_COLOR_MATERIAL);
	glTranslatef(0, 0, -15);
	glRotatef(-ster.katY, 1.0, 0, 0);
	glRotatef(-ster.katZ, 0, 1, 0);
	glTranslatef(-ster.x+0.5, -ster.y, -ster.z+0.2);//camera pozycja
	glTranslatef(0, dronek.wysokosc, 0);
	stad();
	ster.Poruszanie(dronek.naboki, dronek.nachyl, dronek.wysokosc, collision);
	glPushMatrix();
	glScalef(0.02, 0.02, 0.02);
	glTranslatef(0, -dronek.wysokosc * 5, 0);
	glRotatef(-180, 0, 1, 0);
	glTranslatef(1, 1, 1);
	dronek.dron_rysuje();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	

}



void initialize()
{
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, win.width, win.height);
	GLfloat aspect = (GLfloat)win.width / win.height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(win.field_of_view_angle, aspect, win.z_near, win.z_far);
	glMatrixMode(GL_MODELVIEW);
	glShadeModel(GL_SMOOTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	GLfloat amb_light[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat diffuse[] = { 0.6, 0.6, 0.6, 1 };
	GLfloat specular[] = { 0.7, 0.7, 0.3, 1 };

	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);

	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
											// specify clear values for the color buffers								
}


void keyboard(int key, int x,int y)
{
	switch (key) {
	case KEY_ESCAPE:
		exit(0);
		break;

	case GLUT_KEY_F9:
		if (dronek.wysokosc < 2)
			dronek.wysokosc += 0.05;
		break;

	case GLUT_KEY_F8:
		if (dronek.wysokosc >= -4.8)
			dronek.wysokosc -= 0.05;
		break;

	case GLUT_KEY_UP:
		collis();
		if (collision)
		{
			ster.szybkosc == 0;
		}
		else
		{
			ster.szybkosc += 0.1;
			dronek.nachyl -= 0.05;
			if (ster.szybkosc > 0.5)ster.szybkosc = 0.5;
		}
		break;
	case GLUT_KEY_DOWN:
		ster.szybkosc -= 0.1;
		dronek.nachyl += 0.05;
		if (ster.szybkosc < -0.5)ster.szybkosc = -0.5;
		break;

	case GLUT_KEY_LEFT:
		dronek.naboki += 0.2;
		ster.katZ += dronek.naboki;//kamera
		ster.katX -= dronek.naboki;//dron
		break;

	case GLUT_KEY_RIGHT:

		dronek.naboki -= 0.2;
		ster.katZ += dronek.naboki;//kamera
		ster.katX -= dronek.naboki;//dron

	default:
		break;
	}
}

void collis()
{
	float odleglosc;

	float PrzeszkodaX[15] = { -361.324, -361.324,-899.030, -899.030 , -362.131, -362.131, -362.131, -362.131, -362.131, -362.131, -362.131, -362.131, -362.131, -362.131, -362.131 };
	float PrzeszkodaZ[15] = { -97.317, 78.098, 78.098, -97.317, 48.098, 18.098, -12.098, -42.098 , -72.098, 63.098, 33.098, 3.098, -27.098, -57.098, -87.098 };
	float PrzeszkodaY[15] = { 0, 0, 0, 0 , -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2 };
	for (int i = 0; i < 17; i++)
	{
		if (PrzeszkodaY[i] == 0)
		{
			odleglosc = sqrt((ster.x - PrzeszkodaX[i])*(ster.x - PrzeszkodaX[i]) + (ster.z - PrzeszkodaZ[i])*(ster.z - PrzeszkodaZ[i]));
			if (odleglosc < 15)
			{
				collision = true;
				break;
			}
			else
			{
				collision = false;
			}
		}
		else
		{
			odleglosc = sqrt((ster.x - PrzeszkodaX[i])*(ster.x - PrzeszkodaX[i]) + (ster.z - PrzeszkodaZ[i])*(ster.z - PrzeszkodaZ[i]) + (dronek.wysokosc - PrzeszkodaY[i])*(dronek.wysokosc - PrzeszkodaY[i]));
			if (odleglosc < 17)
			{
				collision = true;
				break;
			}
			else
			{
				collision = false;
			}
			
		}
	}
}


int main(int argc, char **argv)
{
	// set window values
	win.width = 1280;
	win.height = 720;
	win.title = "Projekt Grafika";
	win.field_of_view_angle = 45;
	win.z_near = 10.0f;
	win.z_far = 100000.0f;

	// initialize and run program
	glutInit(&argc, argv);                                      // GLUT initialization
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);  // Display Mode
	glutInitWindowSize(win.width, win.height);					// set window size
	glutCreateWindow(win.title);								// create Window
	glutDisplayFunc(display);									// reginaboki Display Function
	glutIdleFunc(display);									// reginaboki Idle Function
	//glutKeyboardFunc(keyboard);								// reginaboki Keyboard Handler
	glutSpecialFunc(keyboard);
	initialize();
	glutTimerFunc(33, TimerFunction, 1);
	glutMainLoop();												// run GLUT mainloop
	return 0;
}