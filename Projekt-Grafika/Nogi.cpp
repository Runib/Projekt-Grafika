#include "Nogi.h"



Nogi::Nogi()
{
}


Nogi::~Nogi()
{
}

void Nogi::Nogi_rysuje(void)
{
	


	glPushMatrix();
	walczyk.Walec_do_rysowania(7, 20);
	stoz.Stozek_rysuje(5, -10);
	glTranslated(0.0, 5.0, 0.0);
	glRotated(45.0, 0.0, 1.0, 0.0);
	prostotrojkat.prostoTrojkat_rysuje(7, 40);
	glRotated(-45.0, 0.0, 1.0, 0.0);
	glRotated(58.0, 1.0, 0.0, 0.0);
	walczyk.Walec_do_rysowania(0.75, 33);
	glRotated(-58.0, 1.0, 0.0, 0.0);
	glRotated(120.0, 0.0, 1.0, 0.0);
	glRotated(58.0, 1.0, 0.0, 0.0);
	walczyk.Walec_do_rysowania(0.75, 33);
	glRotated(-58.0, 1.0, 0.0, 0.0);
	glRotated(120.0, 0.0, 1.0, 0.0);
	glRotated(58.0, 1.0, 0.0, 0.0);
	walczyk.Walec_do_rysowania(0.75, 33);
	glRotated(-58.0, 1.0, 0.0, 0.0);
	glRotated(-240.0, 0.0, 1.0, 0.0);

	glTranslated(0.0, 15.0, 0.0);
	walczyk.Walec_do_rysowania(5, 10);
	glTranslated(0.0, 1.0, 0.0);
	smiglo.smiglo_rysuje(25, 8);
	pierscionek.pierscien_rysuje(28, 4, 1.01);
	glTranslated(0.0, 9.0, 0.0);
	kulka.kula_rysuje(5);
	glTranslated(0.0, -30.0, 0.0);//cofamy do poczatku
	glPopMatrix();
	//-------------------NOGA ZE SMIGLEM 2
	glPushMatrix();
	glTranslated(80.0, 0.0, 0.0);
	walczyk.Walec_do_rysowania(7, 20);
	stoz.Stozek_rysuje(5, -10);
	glTranslated(0.0, 5.0, 0.0);
	glRotated(315.0, 0.0, 1.0, 0.0);
	prostotrojkat.prostoTrojkat_rysuje(7, 40);
	glRotated(-315.0, 0.0, 1.0, 0.0);

	glRotated(58.0, 1.0, 0.0, 0.0);
	walczyk.Walec_do_rysowania(0.75, 33);
	glRotated(-58.0, 1.0, 0.0, 0.0);
	glRotated(120.0, 0.0, 1.0, 0.0);
	glRotated(58.0, 1.0, 0.0, 0.0);
	walczyk.Walec_do_rysowania(0.75, 33);
	glRotated(-58.0, 1.0, 0.0, 0.0);
	glRotated(120.0, 0.0, 1.0, 0.0);
	glRotated(58.0, 1.0, 0.0, 0.0);
	walczyk.Walec_do_rysowania(0.75, 33);
	glRotated(-58.0, 1.0, 0.0, 0.0);
	glRotated(-240.0, 0.0, 1.0, 0.0);

	glTranslated(0.0, 15.0, 0.0);
	walczyk.Walec_do_rysowania(5, 10);
	glTranslated(0.0, 1.0, 0.0);
	smiglo.smiglo_rysuje(25, 8);
	pierscionek.pierscien_rysuje(28, 4, 1.01);
	glTranslated(0.0, 9.0, 0.0);
	kulka.kula_rysuje(5);
	glTranslated(-80.0, -30.0, 0.0);//cofamy do poczatku
	glPopMatrix();
	//-------------------NOGA ZE SMIGLEM 3
	glPushMatrix();
	glTranslated(80.0, 0.0, 80.0);
	walczyk.Walec_do_rysowania(7, 20);
	stoz.Stozek_rysuje(5, -10);
	glTranslated(0.0, 5.0, 0.0);
	glRotated(225.0, 0.0, 1.0, 0.0);
	prostotrojkat.prostoTrojkat_rysuje(7, 40);
	glRotated(-225.0, 0.0, 1.0, 0.0);

	glRotated(58.0, 1.0, 0.0, 0.0);
	walczyk.Walec_do_rysowania(0.75, 33);
	glRotated(-58.0, 1.0, 0.0, 0.0);
	glRotated(120.0, 0.0, 1.0, 0.0);
	glRotated(58.0, 1.0, 0.0, 0.0);
	walczyk.Walec_do_rysowania(0.75, 33);
	glRotated(-58.0, 1.0, 0.0, 0.0);
	glRotated(120.0, 0.0, 1.0, 0.0);
	glRotated(58.0, 1.0, 0.0, 0.0);
	walczyk.Walec_do_rysowania(0.75, 33);
	glRotated(-58.0, 1.0, 0.0, 0.0);
	glRotated(-240.0, 0.0, 1.0, 0.0);

	glTranslated(0.0, 15.0, 0.0);
	walczyk.Walec_do_rysowania(5, 10);
	glTranslated(0.0, 1.0, 0.0);
	smiglo.smiglo_rysuje(25, 8);
	pierscionek.pierscien_rysuje(28, 4, 1.01);
	glTranslated(0.0, 9.0, 0.0);
	kulka.kula_rysuje(5);
	glTranslated(-80.0, -30.0, -80.0);//cofamy do poczatku
	glPopMatrix();
	//-------------------NOGA ZE SMIGLEM 4
	glPushMatrix();
	glTranslated(0.0, 0.0, 80.0);
	walczyk.Walec_do_rysowania(7, 20);
	stoz.Stozek_rysuje(5, -10);
	glTranslated(0.0, 5.0, 0.0);
	glRotated(135.0, 0.0, 1.0, 0.0);
	prostotrojkat.prostoTrojkat_rysuje(7, 40);
	glRotated(-135.0, 0.0, 1.0, 0.0);

	glRotated(58.0, 1.0, 0.0, 0.0);
	walczyk.Walec_do_rysowania(0.75, 33);
	glRotated(-58.0, 1.0, 0.0, 0.0);
	glRotated(120.0, 0.0, 1.0, 0.0);
	glRotated(58.0, 1.0, 0.0, 0.0);
	walczyk.Walec_do_rysowania(0.75, 33);
	glRotated(-58.0, 1.0, 0.0, 0.0);
	glRotated(120.0, 0.0, 1.0, 0.0);
	glRotated(58.0, 1.0, 0.0, 0.0);
	walczyk.Walec_do_rysowania(0.75, 33);
	glRotated(-58.0, 1.0, 0.0, 0.0);
	glRotated(-240.0, 0.0, 1.0, 0.0);

	glTranslated(0.0, 15.0, 0.0);
	walczyk.Walec_do_rysowania(5, 10);
	glTranslated(0.0, 1.0, 0.0);
	smiglo.smiglo_rysuje(25, 8);
	pierscionek.pierscien_rysuje(28, 4, 1.01);
	glTranslated(0.0, 9.0, 0.0);
	kulka.kula_rysuje(5);
	glTranslated(0.0, -30.0, -80.0);//cofamy do poczatku
	glPopMatrix();
}
