#include "Prostopadloscian.h"



Prostopadloscian::Prostopadloscian()
{
}


Prostopadloscian::~Prostopadloscian()
{
}

void Prostopadloscian::Prostopadloscian_rysuje(double a, double b, double c)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{
		
		glColor3d(0.5, 0.5, 0.5);
		glBegin(GL_TRIANGLE_STRIP);
		x = a / 2;
		glVertex3d(-x, 0.0, 0.0);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(-x, b, 0.0);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(x, 0.0, 0.0);
		glColor3d(1.0, 1.0, 1.0);
		glVertex3d(x, b, 0.0);
		glEnd();

		glColor3d(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLE_STRIP);
		glVertex3d(-x, 0.0, c);
		glVertex3d(-x, 0.0, c);
		glVertex3d(-x, b, c);
		glColor3d(0.0, 0.0, 0.0);
		glVertex3d(x, 0.0, c);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(x, b, c);
		glEnd();

		glColor3d(0.5, 0.5, 0.5);
		glBegin(GL_TRIANGLE_STRIP);
		glVertex3d(-x, 0.0, 0.0);
		glColor3d(1, 1, 1);
		glVertex3d(-x, 0.0, c);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(x, 0.0, 0.0);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(x, 0.0, c);

		glColor3d(1.0, 1.0, 1.0);
		glVertex3d(x, b, 0.0);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(x, b, c);

		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(-x, b, 0.0);
		glColor3d(1.0, 1.0, 1.0);
		glVertex3d(-x, b, c);

		glColor3d(1.0, 1.0, 1.0);
		glVertex3d(-x, 0.0, 0.0);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(-x, 0.0, c);
		glEnd();
	}
}
