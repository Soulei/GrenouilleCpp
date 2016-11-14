#include "NenupharImmortel.hpp"
using namespace grenouilloland;

NenupharImmortel::NenupharImmortel() : Element(GestStrat<StrategieNeutre>::strategie)
{
}

NenupharImmortel::~NenupharImmortel()
{
}

const int&
NenupharImmortel::lireId() const {
	return _ID;
}

const int NenupharImmortel::_ID(3);
