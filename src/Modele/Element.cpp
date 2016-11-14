#include "Element.hh"
#include "Etat.hh"
#include "StrategieDopante.hh"
using namespace grenouilloland;

Element::Element(const StrategieAbstraite& strategie) : _etat(Etat::Grand), _strategie(&strategie) 
{
}

Element::~Element()
{
}

const Etat&
Element::lireEtat() const {
	return _etat;
}

Etat Element::vieillir()
{
	return this->_etat;
}

void Element::appliquerStrategie(Grenouille& g) const
{
	_strategie->appliquerStrategie(g);
}

bool Element::isEau() const
{
	return false;
}
