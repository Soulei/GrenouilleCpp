#include "Jeu.hpp"
#include <iostream>
using namespace grenouilloland;

Jeu::Jeu(const int& n) : _grenouille(Grenouille(0,n-1)), _n(n), _end(true), _compteur(60)
{
	if (n == 0)
	{
		throw;
	}
	else
	{
		srand(time(NULL));

		for (int i=0; i<(n*n); i++)
		{
			_plateau.push_back(Cellule(i%n,i/n));
		}
		_plateau[n-1].changerElement(new NenupharImmortel());
		_plateau[(n-1)*n].changerElement(new NenupharImmortel());
	}
}

void
Jeu::reinitialiser()
{
	_end = true;

	for (int i=0; i <(_n*_n); i++)
	{
		_plateau[i].changerElement(new Eau());
	}

	_plateau[_n-1].changerElement(new NenupharImmortel());
	_plateau[(_n-1)*_n].changerElement(new NenupharImmortel());
}

void Jeu::lancerPartie()
{
		_compteur = 60;
		_end = false;
		Grenouille::DeleguationPosition::reinitialiser(_grenouille, _n-1);
}

void Jeu::creerChemin()
{
	if (!_end)
	{
		int x = _grenouille.getX();
		int y = _grenouille.getY();

		for (int i = x; i < _n; i++)
		{
			if (_plateau[y*_n+i].lireElement().isEau())
			{
				_plateau[y*_n+i].changerElement(nenupharAleatoire());
			}
			if (y != 0)
			{
				if (_plateau[i].lireElement().isEau())
				{
					_plateau[i].changerElement(nenupharAleatoire());
				}
			}
		}

		for (int j = y; j > 0; j--)
		{
			if (_plateau[j*_n+x].lireElement().isEau())
			{
				_plateau[j*_n+x].changerElement(nenupharAleatoire());
			}
			if (x != _n-1)
			{
				if (_plateau[(_n-1)+_n*j].lireElement().isEau())
				{
					_plateau[(_n-1)+_n*j].changerElement(nenupharAleatoire());
				}
			}
		}
	}
}

bool Jeu::verifEtat()
{
	return _end = (_grenouille.getPv()==0) ? true : false;
}

bool Jeu::vieillissement()
{
	if (!_end)
	{
		_compteur--;

		if (_compteur > 0 && (_grenouille.getX() != (_n-1) || _grenouille.getY() != 0))
		{
			bool morte = false;
			for (int i = 0; i < (_n*_n); i++) _plateau[i].vieillirElement();

			creerChemin();

			for (int i = 0; i < (_n*_n); i++)
			{
				if (_plateau[i].lireElement().lireEtat() == Etat::Mort)
				{
					_plateau[i].changerElement(new Eau());

					if ((_grenouille.getX() + (_grenouille.getY() * _n)) == i)
					{
						Element::Delegation::appliquerStrategie(_plateau[i].lireElement(),_grenouille);
						if (verifEtat()) {
							morte = true;
						}
					}
				}
			}
			if(morte)
				return false;
			return true;
		}
		else
		{
			_end = true;
			return false;
		}
	}

	return false;
}

bool Jeu::deplacerGrenouille(const int& x, const int& y)
{
	if (!_end)
	{
		int r_x = static_cast<int>(_grenouille.getX()) - x;
		int r_y = static_cast<int>(_grenouille.getY()) - y;

		if (((r_x * r_x) == 1 && r_y == 0) || ((r_y * r_y) == 1 && r_x == 0))
		{
			Grenouille::DeleguationPosition::setX(_grenouille,x);
			Grenouille::DeleguationPosition::setY(_grenouille,y);

			Element::Delegation::appliquerStrategie(_plateau[x+(_n*y)].lireElement(),_grenouille);
			verifEtat();

			return true;
		}
	}
	return false;
}

const int&
Jeu::lireDimension() const {
	return _n;
}

const unsigned int&
Jeu::lireCompteur() const {
	return _compteur;
}

const Cellule&
Jeu::lireCellule(const int& ligne, const int& colonne) const {
  	return _plateau[ligne * _n + colonne];
}

const unsigned int&
Jeu::lirePvGrenouille() const {
	return _grenouille.getPv();
}

bool
Jeu::grenouilleMalade() const {
	return _grenouille.getMalade();
}

bool
Jeu::presenceGrenouille(const unsigned int& ligne, const unsigned int& colonne) const {
	return (ligne == _grenouille.getY() && colonne == _grenouille.getX());
}

bool
Jeu::end() const {
	return _end;
}

Element*
Jeu::nenupharAleatoire() const
{
	switch (rand()%5)
	{
		case 1 :
			return new NenupharDopant();
		case 2 :
			return new NenupharMortel();
		case 3 :
			return new NenupharNutritif();
		case 4 :
			return new NenupharVeneneux();
		default :
			return new Nenuphar();
	}
}
