#include "stozek.h"



stozek::stozek()
{
}

void stozek::Stozek_rysuje(double r, double h)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{
		
		glColor3d(0.5, 0.5, 0.5);
		glBegin(GL_TRIANGLE_FAN);
		glVertex3d(0.0, h, 0.0);
		for (angle = 0; angle <= 2 * GL_PI; angle += GL_PI / 15.0)
		{
			x = r * sin(angle);
			y = r * cos(angle);
			glColor3d(1.0, 1.0, 1.0);
			glVertex3d(x, 0.0, y);
		}
		glEnd();
	}
}


stozek::~stozek()
{
}
