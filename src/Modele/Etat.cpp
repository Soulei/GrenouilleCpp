#include "Etat.hh"
using namespace grenouilloland;

Etat::Etat(const Enum& e) : _etat(e)
{}

bool Etat::operator==(const Enum& e) const {
	return _etat==e;
}
