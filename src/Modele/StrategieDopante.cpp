#include "include/StrategieDopante.hpp"
using namespace grenouilloland;

void StrategieDopante::appliquerEffet(unsigned int& pv, bool& malade) const
{
	pv*=2;
	malade=false;
}

StrategieDopante::StrategieDopante()
{
}
