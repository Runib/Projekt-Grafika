#pragma once
#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include <math.h>

#define GL_PI 3.14
class stozek
{
private:
	double x, y, angle;
public:
	stozek();
	~stozek();
	void Stozek_rysuje(double r, double h);
};

