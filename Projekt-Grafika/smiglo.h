#pragma once
#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include <math.h>
class smiglo
{
public:
	smiglo();
	~smiglo();
	void smiglo_rysuje(double le, double h);
};

