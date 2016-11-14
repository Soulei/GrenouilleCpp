#include "include/StrategieVeneneuse.hh"
using namespace grenouilloland;

void StrategieVeneneuse::appliquerEffet(unsigned int& pv, bool& malade) const
{
	if (malade)
	{
		pv=0;
	}
	else
	{
		pv/=2;
		malade=true;
	}
}

StrategieVeneneuse::StrategieVeneneuse()
{
}
