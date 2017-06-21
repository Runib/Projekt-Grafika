#pragma once
#include "glut.h"
#include <math.h>
#define	PI	 3.1415926
class SYSTEMB {
public:
	float x, y, z, speed, katX, katY, katZ, y2, z2, x2;
	int obrot;
	SYSTEMB();
	void MoveCamera();
	void latanie(float obrot,float pochyl, float goradol, bool collision);
};