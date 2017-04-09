#pragma once
#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include <math.h>
class kamerka
{
private:
	double x1, y1, x2, y2, alpha, pi = 3.14;
public:
	kamerka();
	~kamerka();
	void kamerka_rysuje(double r, double R, double h);
};

