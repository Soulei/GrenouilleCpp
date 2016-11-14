#include "include/Grenouille.hpp"
using namespace grenouilloland;

Grenouille::Grenouille(const unsigned int& x, const unsigned int& y) : _pv(1), _malade(false), _x(x), _y(y)
{
}

const unsigned int& Grenouille::getPv() const
{
	return _pv;
}

unsigned int Grenouille::setPv(const unsigned int& pv)
{
	return _pv = pv;
}

const bool& Grenouille::getMalade() const
{
	return _malade;
}

bool Grenouille::setMalade(const bool& malade)
{
	return _malade = malade;
} 

const unsigned int& Grenouille::getX() const
{
	return _x;
}

unsigned int Grenouille::setX(const unsigned int& x)
{
	return _x = x;
}

const unsigned int& Grenouille::getY() const
{
	return _y;
}

unsigned int Grenouille::setY(const unsigned int& y)
{
	return _y = y;
}

void
Grenouille::reinitialiser(const int& n) {
	_pv = 1;
	_malade = false;
	_x = 0;
	_y = n;
}
