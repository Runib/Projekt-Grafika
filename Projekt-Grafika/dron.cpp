#include "dron.h"



dron::dron()
{
	naboki = nachyl = 0;
	wysokosc = 0;
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



