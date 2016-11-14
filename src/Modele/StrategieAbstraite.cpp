#include "include/StrategieAbstraite.hpp"
using namespace grenouilloland;

void StrategieAbstraite::appliquerStrategie(Grenouille& g) const
{
	unsigned int pv = g.getPv();
	bool malade = g.getMalade();
	
	this->appliquerEffet(pv,malade);
	
	Grenouille::DeleguationEtat::setPv(g,pv);
	Grenouille::DeleguationEtat::setMalade(g,malade);
}
