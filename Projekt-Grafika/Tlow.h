#pragma once
#include "Walec.h"
#include "kamerka.h"
#include "kula.h"
#include "Ostroslup.h"
#include "Prostopadloscian.h"
#include "trapez.h"
class Tlow
{
private:
	Walec walczyk;
	kamerka kamerka;
	kula kulka;
	Ostroslup ostroslupek;
	Prostopadloscian padloscian;
	trapez trapezik;
public:
	Tlow();
	~Tlow();
	void Tlow_rysuje(void);
};

