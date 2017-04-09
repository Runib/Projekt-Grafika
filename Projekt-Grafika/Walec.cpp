#include "Walec.h"



Walec::Walec()
{
}


Walec::~Walec()
{
}

void Walec::Walec_do_rysowania(double r, double h)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{
		
		glBegin(GL_TRIANGLE_FAN);
		glColor3d(1.0, 1.0, 1.0);
		glVertex3d(0, 0, 0);
		for (alpha = 0; alpha <= 2 * PI; alpha += PI / 15.0)
		{
			x = r*sin(alpha);
			y = r*cos(alpha);
			glColor3d(0.5, 0.5, 0.5);
			glVertex3d(x, 0, y);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (alpha = 0; alpha <= 2 * PI; alpha += PI / 15.0)
		{
			x = r* sin(alpha);
			y = r* cos(alpha);
			glColor3d(0.5, 0.5, 0.5);
			glVertex3d(x, 0, y);
			glColor3d(1.0, 1.0, 1.0);
			glVertex3d(x, h, y);
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(0, h, 0);
		for (alpha = 0; alpha <= 2 * PI; alpha += PI / 15.0)
		{
			x = r*sin(alpha);
			y = r*cos(alpha);
			glColor3d(1.0, 1.0, 1.0);
			glVertex3d(x, h, y);
		}
		glEnd();
	}
}
