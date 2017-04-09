#include "kamerka.h"



kamerka::kamerka()
{
}


kamerka::~kamerka()
{
}

void kamerka::kamerka_rysuje(double r, double R, double h)
{
	
	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	for (alpha = 0; alpha <= 2 * pi; alpha += pi / 15.0)
	{
		x1 = r* sin(alpha);
		y1 = r* cos(alpha);
		glVertex3d(x1, 0, y1);
		glVertex3d(x1, h, y1);
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	for (alpha = 0; alpha <= 2 * pi; alpha += pi / 15.0)
	{
		x2 = R* sin(alpha);
		y2 = R* cos(alpha);
		glVertex3d(x2, 0, y2);
		glVertex3d(x2, h, y2);
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	for (alpha = 0; alpha <= 2 * pi; alpha += pi / 15.0)
	{
		x1 = r* sin(alpha);
		y1 = r* cos(alpha);
		x2 = R* sin(alpha);
		y2 = R* cos(alpha);
		glVertex3d(x1, h, y1);
		glVertex3d(x2, h, y2);
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	for (alpha = 0; alpha <= 2 * pi; alpha += pi / 15.0)
	{
		x1 = r* sin(alpha);
		y1 = r* cos(alpha);
		x2 = R* sin(alpha);
		y2 = R* cos(alpha);
		glVertex3d(x1, 0, y1);
		glVertex3d(x2, 0, y2);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.0, 1.0, 1.0);
	for (alpha = 0; alpha <= 2 * pi; alpha += pi / 15.0)
	{
		x1 = r*sin(alpha);
		y1 = r*cos(alpha);
		glVertex3d(x1, h - 1, y1);
	}
	glEnd();
}
