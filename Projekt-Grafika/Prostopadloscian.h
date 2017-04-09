#pragma once
#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include <math.h>
class Prostopadloscian
{
private:
	double x;
public:
	Prostopadloscian();
	~Prostopadloscian();
	void Prostopadloscian_rysuje(double a, double b, double c);
};

