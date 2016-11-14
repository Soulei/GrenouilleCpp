#include "Nenuphar.hpp"
#include "StrategieNeutre.hpp"
using namespace grenouilloland;

Nenuphar::Nenuphar() : ElementMortel(GestStrat<StrategieNeutre>::strategie)
{

}

Nenuphar::~Nenuphar()
{
}

const int&
Nenuphar::lireId() const {
	return _ID;
}

const int Nenuphar::_ID(1);
