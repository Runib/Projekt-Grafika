#pragma once
#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include <math.h>

class Walec
{
private:
	double x, y, alpha, pi = 3.14;
public:
	Walec();
	~Walec();
	void Walec_do_rysowania(double r, double h);
};

