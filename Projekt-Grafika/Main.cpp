#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include <math.h>
#include "systemDron.h"
#include "dron.h"
#include "glm.h"

#define KEY_ESCAPE 27
#define GL_PI 3.14

GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;
GLdouble xCam, yCam, zCam, angle = 0;
GLfloat rotatex = 90;
GLfloat rotatey = 90;
GLfloat rotate = 0;
GLfloat translatex = 0;
GLfloat translatey = 0;
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
SYSTEMB systembat;
GLMmodel *bud;

void TimerFunction(int value) {
	dronek.nachyl = dronek.nachyl*0.9;


	systembat.speed = systembat.speed*0.98;
	dronek.naboki = dronek.naboki*0.9;
	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}

void Budynek() {
	if (!bud) {
		bud = glmReadOBJ("nowy.obj");
		if (!bud) exit(0);
		glmFacetNormals(bud);
		glmVertexNormals(bud, 90.0);
	}
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Torus.003");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Torus.002");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Torus.001");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Torus");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.012_Cylinder.014");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.013");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.012");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.011");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.010");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.009");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.008");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.011_Cylinder.013");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.010_Cylinder.012");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.009_Cylinder.011");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.008_Cylinder.010");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.007");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.006");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.005");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.004");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.003");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.002");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder.001");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cylinder");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.007");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.006");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.005");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.004");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Plane.001_Plane.002");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.003");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.002");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube.001");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Cube");
	glmDraw(bud, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE, " Plane");
	
	glPushMatrix();
	glPopMatrix();

}

bool collision = false;
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
	glTranslatef(translatex, translatey, -15);
	glRotatef(-systembat.katY, 1.0, 0, 0);
	glRotatef(-systembat.katZ, 0, 1, 0);
	glTranslatef(-systembat.x+0.5, -systembat.y, -systembat.z+0.2);//camera pozycja
	glTranslatef(0, dronek.wysokosc, 0);
	Budynek();
	systembat.latanie(dronek.naboki, dronek.nachyl, dronek.wysokosc, collision);
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

	case GLUT_KEY_F1:
		if (dronek.wysokosc < 1)
			dronek.wysokosc += 0.05;
		break;

	case GLUT_KEY_F2:
		if (dronek.wysokosc >= -3.8)
			dronek.wysokosc -= 0.05;
		break;

	case GLUT_KEY_UP:
	
		if (collision)
		{
			systembat.speed == 0;
		}
		else
		{
			systembat.speed += 0.1;
			dronek.nachyl -= 0.05;
			if (systembat.speed > 0.5)systembat.speed = 0.5;
		}
		break;
	case GLUT_KEY_DOWN:
		systembat.speed -= 0.1;
		dronek.nachyl += 0.05;
		if (systembat.speed < -0.5)systembat.speed = -0.5;
		break;

	case GLUT_KEY_LEFT:
		dronek.naboki += 0.2;
		systembat.katZ += dronek.naboki;//kamera
		systembat.katX -= dronek.naboki;//dron
		break;

	case GLUT_KEY_RIGHT:

		dronek.naboki -= 0.2;
		systembat.katZ += dronek.naboki;//kamera
		systembat.katX -= dronek.naboki;//dron

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