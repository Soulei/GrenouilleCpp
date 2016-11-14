#include "ElementMortel.hh"
using namespace grenouilloland;

ElementMortel::ElementMortel(const StrategieAbstraite& strategie) : Element(strategie)
{
}

ElementMortel::~ElementMortel()
{
}

Etat ElementMortel::vieillir()
{
	if(_etat == Etat::Grand)
		return _etat = Etat::Moyen;
	else if(_etat == Etat::Moyen)
		return _etat = Etat::Petit;
	else
		return _etat = Etat::Mort;
}
