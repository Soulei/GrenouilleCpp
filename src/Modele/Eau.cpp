#include "include/Eau.hh"
using namespace grenouilloland;

Eau::Eau() : Element(GestStrat<StrategieMort>::strategie)
{
}

Eau::~Eau()
{
}

bool Eau::isEau() const
{
	return true;
}

const int&
Eau::lireId() const {
	return _ID;
}

const int Eau::_ID(0);
