#pragma once
#include "glut.h"
#include <math.h>
#define	PI	 3.1415926
class sterowanie
{
public:
	sterowanie();
	~sterowanie();
	float x, y, z, szybkosc, katX, katY, katZ, y2, z2, x2;
	int obrot;
	void RuchKamery();
	void Poruszanie(float obrot, float pochylenie, float wysokosc, bool collision);
};

