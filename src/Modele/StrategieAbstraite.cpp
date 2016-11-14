#include "include/StrategieAbstraite.hh"
using namespace grenouilloland;

void StrategieAbstraite::appliquerStrategie(Grenouille& g) const
{
	unsigned int pv = g.getPv();
	bool malade = g.getMalade();
	
	this->appliquerEffet(pv,malade);
	
	Grenouille::MandataireEtat::setPv(g,pv);
	Grenouille::MandataireEtat::setMalade(g,malade);
}
