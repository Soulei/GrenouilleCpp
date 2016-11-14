/************************************
 * Definition de la classe Cellule. *
 ************************************/

#include "Jeu.hpp"
using namespace grenouilloland;

/************
 * Cellule. *
 ************/

Cellule::Cellule(const int& colonne, const int& ligne):
  _ligne(ligne),
  _colonne(colonne),
  _element(new Eau()) {
}

/**************
 * lireLigne. *
 **************/

const int&
Cellule::lireLigne() const {
  return _ligne;
}

/****************
 * lireColonne. *
 ****************/

const int&
Cellule::lireColonne() const {
  return _colonne;
}

/****************
 * lireElement. *
 ****************/

const Element&
Cellule::lireElement() const {
	return *_element;
}

/****************
 * changerElement. *
 ****************/

void
Cellule::changerElement(Element* element) {
	_element.reset(element);
}

/****************
 * vieillirElement. *
 ****************/

Etat
Cellule::vieillirElement() {
	return Element::Delegation::vieillir(*_element);
}
