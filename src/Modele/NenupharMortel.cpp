#include "NenupharMortel.hh"
using namespace grenouilloland;

NenupharMortel::NenupharMortel() : ElementMortel(GestStrat<StrategieMort>::strategie)
{
}

NenupharMortel::~NenupharMortel()
{
}

const int&
NenupharMortel::lireId() const {
	return _ID;
}

const int NenupharMortel::_ID(4);
