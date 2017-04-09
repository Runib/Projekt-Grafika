#include "kula.h"



kula::kula()
{
}


kula::~kula()
{
}

void kula::kula_rysuje(double r)
{
	GLUquadricObj*obj;
	obj = gluNewQuadric();
	gluQuadricTexture(obj, GL_TRUE);
	//glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glColor3d(0.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	gluSphere(obj, r, 15, 7);
	glDisable(GL_TEXTURE_2D);
}
