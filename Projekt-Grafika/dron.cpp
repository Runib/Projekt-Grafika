#include "dron.h"



dron::dron()
{
	obrotL = obrotP = ster = nachyl = 0;
	goradol = 0;
}


dron::~dron()
{
}

void dron::dron_rysuje()
{
	Tlow tlow;
	Nogi nogi;
	tlow.Tlow_rysuje();
	nogi.Nogi_rysuje();

}



