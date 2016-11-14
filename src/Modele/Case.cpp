/************************************
 * Definition de la classe Case. *
 ************************************/

#include "Jeu.hpp"
using namespace grenouilloland;

/************
 * Case. *
 ************/

Case::Case(const int& colonne, const int& ligne):
  _ligne(ligne),
  _colonne(colonne),
  _element(new Eau()) {
}

/**************
 * lireLigne. *
 **************/

const int& 
Case::lireLigne() const {
  return _ligne;
}

/****************
 * lireColonne. *
 ****************/

const int& 
Case::lireColonne() const {
  return _colonne;
}

/****************
 * lireElement. *
 ****************/

const Element&
Case::lireElement() const {
	return *_element;
}

/****************
 * changerElement. *
 ****************/

void
Case::changerElement(Element* element) {
	_element.reset(element);
}

/****************
 * vieillirElement. *
 ****************/

Etat
Case::vieillirElement() {
	return Element::Mandataire::vieillir(*_element);
}
