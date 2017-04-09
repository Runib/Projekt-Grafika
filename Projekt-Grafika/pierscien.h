#pragma once
#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include <math.h>
class pierscien
{
private:
	double x, y, alpha, PI = 3.14;
public:
	pierscien();
	~pierscien();
	void pierscien_rysuje(double r, double h, double w);
};

