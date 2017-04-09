#include "Ostroslup.h"



Ostroslup::Ostroslup()
{
}


Ostroslup::~Ostroslup()
{
}

void Ostroslup::Ostroslup_rysuje(double a, double h)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{
		
		glBegin(GL_TRIANGLE_STRIP);
		x = a / 2;
		glColor3d(1.0, 1.0, 1.0);
		glVertex3d(-x, 0.0, 0.0);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(-x, 0.0, a);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(x, 0.0, 0.0);
		glColor3d(0.0, 0.0, 0.0);
		glVertex3d(x, 0.0, a);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		x = a / 2;
		glVertex3d(0.0, h, x);
		glColor3d(1, 1, 1);
		glVertex3d(-x, 0.0, 0.0);
		glColor3d(0.0, 0.0, 0.0);
		glVertex3d(-x, 0.0, a);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(x, 0.0, a);
		glColor3d(0.0, 0.0, 0.0);
		glVertex3d(x, 0.0, 0.0);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(-x, 0.0, 0.0);
		glEnd();
	}
}
