#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include <math.h>
#include "Nogi.h"
#include "Tlow.h"


#define KEY_ESCAPE 27
#define GL_PI 3.14

double KamerX=40, KamerY=50, KamerZ=-100, kat = 0;

typedef struct {
	int width;
	int height;
	char* title;

	float field_of_view_angle;
	float z_near;
	float z_far;
} glutWindow;

glutWindow win;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(KamerX, KamerY, KamerZ, KamerX + 100 * sin(kat), KamerY - 4, KamerZ + 100 * cos(kat), 0.0, 1.0, 0.0);
	// Save the matrix state and do the rotations
	Tlow tlow;
	Nogi nogi;
	

	glPushMatrix();
	

	/////////////////////////////////////////////////////////////////
	// MIEJSCE NA KOD OPENGL DO TWORZENIA WLASNYCH SCEN:		   //
	//Sposób na odróŸnienie "przedniej" i "tylniej" œciany wielok¹ta:
	glPolygonMode(GL_BACK, GL_LINE);
	nogi.Nogi_rysuje();
	tlow.Tlow_rysuje();
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Flush drawing commands
	glFlush();

	glutSwapBuffers();
}


void initialize()
{
	glMatrixMode(GL_PROJECTION);												// select projection matrix
	glViewport(0, 0, win.width, win.height);									// set the viewport
	glMatrixMode(GL_PROJECTION);												// set matrix mode
	glLoadIdentity();															// reset projection matrix
	GLfloat aspect = (GLfloat)win.width / win.height;
	gluPerspective(win.field_of_view_angle, aspect, win.z_near, win.z_far);		// set up a perspective projection matrix
	
	glMatrixMode(GL_MODELVIEW);	

	// specify which matrix is the current matrix
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);														// specify the clear value for the depth buffer
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);						// specify implementation-specific hints
	glClearColor(1.0, 1.0, 1.0, 1.0);											// specify clear values for the color buffers								
}


void keyboard(unsigned char key, int mousePositionX, int mousePositionY)
{
	switch (key)
	{
	case KEY_ESCAPE:
		exit(0);
		break;
	case 97:
		kat += GL_PI / 50;
		break;
	case 100:
		kat -= GL_PI / 50;
		break;
	case 113:
		KamerY += 5;
		break;
	case 101:
		KamerY -= 5;
		break;
	case 119:
		KamerX += sin(kat)*3;
		KamerZ += cos(kat) * 3;
		break;
	case 115:
		KamerX -= sin(kat) *3;
		KamerZ -= cos(kat) * 3;
		break;
	default:
		break;
	}
}

int main(int argc, char **argv)
{
	// set window values
	win.width = 1280;
	win.height = 720;
	win.title = "Projekt Grafika";
	win.field_of_view_angle = 90;
	win.z_near = 10.0f;
	win.z_far = 1000.0f;

	// initialize and run program
	glutInit(&argc, argv);                                      // GLUT initialization
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);  // Display Mode
	glutInitWindowSize(win.width, win.height);					// set window size
	glutCreateWindow(win.title);								// create Window
	glutDisplayFunc(display);									// register Display Function
	glutIdleFunc(display);									// register Idle Function
	glutKeyboardFunc(keyboard);								// register Keyboard Handler
	initialize();
	glutMainLoop();												// run GLUT mainloop
	return 0;
}