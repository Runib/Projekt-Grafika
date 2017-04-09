#pragma once
#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include <math.h>
#include "Walec.h"
#include "smiglo.h"
#include "stozek.h"
#include "kula.h"
#include "pierscien.h"
#include "prostoTrojkat.h"
class Nogi
{
private:
	Walec walczyk;
	stozek stoz;
	smiglo smiglo;
	kula kulka;
	pierscien pierscionek;
	prostoTrojkat prostotrojkat;
public:
	Nogi();
	~Nogi();
	void Nogi_rysuje(void);
};

