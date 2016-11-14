#include "include/StrategieDopante.hh"
using namespace grenouilloland;

void StrategieDopante::appliquerEffet(unsigned int& pv, bool& malade) const
{
	pv*=2;
	malade=false;
}

StrategieDopante::StrategieDopante()
{
}
