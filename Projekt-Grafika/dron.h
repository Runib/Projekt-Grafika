#pragma once
#include "glut.h"
#include "Nogi.h"
#include "Tlow.h"
class dron
{
public:
	dron();
	~dron();
	float naboki, nachyl, wysokosc;		//nachylenie drona przod/tyl, wysokosc i zmienna obliczania do kata nachylenia drona
	void dron_rysuje();


};

