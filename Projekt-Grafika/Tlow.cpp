#include "Tlow.h"



Tlow::Tlow()
{
}


Tlow::~Tlow()
{
}

void Tlow::Tlow_rysuje()
{
	glPushMatrix();
	glTranslated(40.0, 0.0, 10.0);
	padloscian.Prostopadloscian_rysuje(30, 20, 60);
	glTranslated(0.0, 20.0, 0.0);
	glRotated(90, 1.0, 0.0, 0.0);
	walczyk.Walec_do_rysowania(7, 20);
	glTranslated(0.0, 20.0, 0.0);
	glTranslated(0.0, -20.0, 0.0);
	glRotated(180, 1.0, 0.0, 0.0);
	glTranslated(8.0, 0.0, -20.0);
	ostroslupek.Ostroslup_rysuje(13, 10);
	glTranslated(-16.0, 0.0, 0.0);
	ostroslupek.Ostroslup_rysuje(13, 10);
	glRotated(-270, 1.0, 0.0, 0.0);
	glTranslated(8.0, 1.0, 55.0);
	walczyk.Walec_do_rysowania(15, 18);
	//rysuje oczy i kamerke
	glTranslated(-6.0, 14.0, 13.0);
	kulka.kula_rysuje(4);
	glTranslated(12.0, 0.0, 0.0);
	kulka.kula_rysuje(4);
	glRotated(-90, 1.0, 0.0, 0.0);
	glTranslated(-6.0, -4.0, -7.0);
	kamerka.kamerka_rysuje(3, 4, 3);
	glTranslated(-45.0, -1.0, -70.0);//cofamy do poczatku
	glPopMatrix();

	//antenka
	glPushMatrix();
	glTranslated(30, 20, 20);
	walczyk.Walec_do_rysowania(1.5, 30);
	glTranslated(0, 30, 0);
	kulka.kula_rysuje(4);
	glTranslated(-30, -50, -20);
	glPopMatrix();

	//trapezy z tylu tulowia
	glPushMatrix();
	glTranslated(25.0, 0.0, 10.5);
	glRotated(90.0, 0.0, 1.0, 0.0);
	trapezik.trapez_rysuje();
	glTranslated(0.0, 0.0, 30.0);
	trapezik.trapez_rysuje();;
	glTranslated(-25.0, 0.0, -40.5);
	glPopMatrix();
}
