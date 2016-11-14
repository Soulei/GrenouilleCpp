#include "NenupharDopant.hpp"
using namespace grenouilloland;

NenupharDopant::NenupharDopant() : ElementMortel(GestStrat<StrategieDopante>::strategie)
{
}

NenupharDopant::~NenupharDopant()
{
}

const int&
NenupharDopant::lireId() const {
	return _ID;
}

const int NenupharDopant::_ID(2);
