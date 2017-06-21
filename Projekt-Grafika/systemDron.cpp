#include "systemDron.h"

SYSTEMB::SYSTEMB()
{
	x = y = 0; z = 1;
	katX = katY = katZ = y2 = z2 = x2 = speed = 0; obrot = 1;
}

void SYSTEMB::MoveCamera() {
	float rad = (katZ*PI) / 180;
	float rady = (katY*PI) / 180;
	if (speed > 0)
	{
		z -= (cos(rad)*speed)*(cos(rady)*speed);
	}
	else
	{
		z += (cos(rad)*speed)*(cos(rady)*speed);
	}
	x -= sin(rad)*speed;
	y += sin(rady)*speed;
}

void SYSTEMB::latanie(float obrot, float pochyl, float goradol, bool collision)
{
	if (katX > 360)
	{
		katX = 0;
	}
	else if (katX < -360)
	{
		katX = 0;
	}
	if (!collision || speed < 0)
	{
		MoveCamera();

	}
	glTranslatef(x, y, z); //przesuniecie dronu
	glRotatef(-katX, 0, 1, 0);
	glRotatef(pochyl * 25, 1, 0, 0);
	glRotatef(obrot * 25, 0, 1, 1);//pochylenie
}