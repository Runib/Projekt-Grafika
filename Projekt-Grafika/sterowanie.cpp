#include "sterowanie.h"



sterowanie::sterowanie()
{
	x = y = 0; z = 1;
	katX = 0;
	katY = 0;
	katZ = 0;
	y2 = 0;
	z2 = 0;
	x2 = 0;
	szybkosc = 0;
	obrot = 1;
}


sterowanie::~sterowanie()
{
}

void sterowanie::RuchKamery()
{
	float zmianaKata = (katZ*PI) / 180;
	float zmianaKatay = (katY*PI) / 180;
	if (szybkosc > 0)
	{
		z -= (cos(zmianaKata)*szybkosc)*(cos(zmianaKatay)*szybkosc);
	}
	else
	{
		z += (cos(zmianaKata)*szybkosc)*(cos(zmianaKatay)*szybkosc);
	}
	x -= sin(zmianaKata)*szybkosc;
	y += sin(zmianaKatay)*szybkosc;
}

void sterowanie::Poruszanie(float obrot, float pochylenie, float wysokosc, bool collision)
{
	if (katX > 360)
	{
		katX = 0;
	}
	else if (katX < -360)
	{
		katX = 0;
	}
	if (!collision || szybkosc < 0)
	{
		RuchKamery();

	}
	glTranslatef(x, y, z); 
	glRotatef(-katX, 0, 1, 0);
	glRotatef(pochylenie * 25, 1, 0, 0);
	glRotatef(obrot * 25, 0, 1, 1);
}
