#include "trapez.h"



trapez::trapez()
{
}


trapez::~trapez()
{
}

void trapez::trapez_rysuje(void)
{
	glBegin(GL_POLYGON);
	glColor3d(1.0, 1.0, 1.0);
	glVertex2f(0.0, 0.0);
	glColor3d(0.5, 0.5, 0.5);
	glVertex2f(0.0, 20.0);
	glColor3d(0.5, 0.5, 0.5);
	glVertex2f(15.0, 20.0);
	glColor3d(1.0, 1.0, 1.0);
	glVertex2f(3.0, 0.0);
	glEnd();
}
