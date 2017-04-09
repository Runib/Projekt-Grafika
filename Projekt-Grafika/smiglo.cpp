#include "smiglo.h"



smiglo::smiglo()
{
}


smiglo::~smiglo()
{
}

void smiglo::smiglo_rysuje(double le, double h)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{
		glBegin(GL_TRIANGLE_STRIP);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(0.0, 0.0, le);
		glColor3d(1.0, 1.0, 1.0);
		glVertex3d(0.0, h, 0.0);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(h, 0.0, le);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(0.0, 0.0, 0.0);
		glColor3d(0.0, 0.0, 0.0);
		glVertex3d(0.0, 0.0, -le);
		glColor3d(1.0, 1.0, 1.0);
		glVertex3d(0.0, h, 0.0);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(-h, 0.0, -le);
		glEnd();
	}
}
