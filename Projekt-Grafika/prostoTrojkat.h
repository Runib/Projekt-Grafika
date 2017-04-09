#pragma once
#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include <math.h>
class prostoTrojkat
{
private:
	double x, y, z;
public:
	prostoTrojkat();
	~prostoTrojkat();
	void prostoTrojkat_rysuje(double a, double h);
};
