#include "prostoTrojkat.h"



prostoTrojkat::prostoTrojkat()
{
}


prostoTrojkat::~prostoTrojkat()
{
}

void prostoTrojkat::prostoTrojkat_rysuje(double a, double h)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{
		
		x = y = z = 0;
		glBegin(GL_TRIANGLES);//jeden bok
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(-a, y, z);
		x += a * 2;
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(a, y, z);
		y = sqrt((x*x) - (a*a));
		glColor3d(1.0, 1.0, 1.0);
		glVertex3d(0.0, y, z);
		glEnd();

		x = y = z = 0;
		glBegin(GL_TRIANGLES);//drugi bok
		z += h;
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(-a, y, z);
		x += a * 2;
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(a, y, z);
		y = sqrt((x*x) - (a*a));
		glColor3d(1.0, 1.0, 1.0);
		glVertex3d(0.0, y, z);
		glEnd();

		x = y = z = 0;
		glBegin(GL_TRIANGLE_STRIP);//laczymy od dolu
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(-a, y, z);
		glColor3d(1.0, 1.0, 1.0);
		z += h;
		glVertex3d(-a, y, z);
		z = 0;
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(a, y, z);

		glColor3d(1.0, 1.0, 1.0);
		z += h;
		glVertex3d(a, y, z);
		z = 0;
		x += a * 2;
		y = sqrt((x*x) - (a*a));
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(0.0, y, z);
		z += h;
		glColor3d(1.0, 1.0, 1.0);
		glVertex3d(0.0, y, z);

		glColor3d(0.5, 0.5, 0.5);
		x = y = z = 0;
		glVertex3d(-a, y, z);
		z += h;
		glColor3d(1.0, 1.0, 1.0);
		glVertex3d(-a, y, z);
		glEnd();
	}
}
