#include "NenupharVeneneux.hpp"
using namespace grenouilloland;

NenupharVeneneux::NenupharVeneneux() : ElementMortel(GestStrat<StrategieVeneneuse>::strategie)
{
}

NenupharVeneneux::~NenupharVeneneux()
{
}

const int&
NenupharVeneneux::lireId() const {
	return _ID;
}

const int NenupharVeneneux::_ID(6);
