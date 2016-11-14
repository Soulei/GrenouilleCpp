#include "NenupharNutritif.hh"
using namespace grenouilloland;

NenupharNutritif::NenupharNutritif() : ElementMortel(GestStrat<StrategieNutritive>::strategie)
{
}

NenupharNutritif::~NenupharNutritif()
{
}

const int&
NenupharNutritif::lireId() const {
	return _ID;
}

const int NenupharNutritif::_ID(5);
