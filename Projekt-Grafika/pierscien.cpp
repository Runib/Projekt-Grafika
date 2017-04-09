#include "pierscien.h"



pierscien::pierscien()
{
}


pierscien::~pierscien()
{
}

void pierscien::pierscien_rysuje(double r, double h, double w)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{
		
		glColor3d(0.0, 0.0, 0.0);
		glBegin(GL_TRIANGLE_STRIP);
		for (alpha = 0; alpha <= 2 * PI; alpha += PI / 15.0)
		{
			x = r* sin(alpha);
			y = r* cos(alpha);
			glVertex3d(x, 0, y);
			x *= w;
			y *= w;
			glVertex3d(x, 0, y);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (alpha = 0; alpha <= 2 * PI; alpha += PI / 15.0)
		{
			x = r* sin(alpha);
			y = r* cos(alpha);
			glVertex3d(x, h, y);
			x *= w;
			y *= w;
			glVertex3d(x, h, y);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (alpha = 0; alpha <= 2 * PI; alpha += PI / 15.0)
		{
			x = r* sin(alpha);
			y = r* cos(alpha);
			glVertex3d(x, 0, y);
			glVertex3d(x, h, y);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (alpha = 0; alpha <= 2 * PI; alpha += PI / 15.0)
		{
			x = r* sin(alpha);
			y = r* cos(alpha);
			x *= w;
			y *= w;
			glVertex3d(x, 0, y);
			glVertex3d(x, h, y);
		}
		glEnd();
	}
}
