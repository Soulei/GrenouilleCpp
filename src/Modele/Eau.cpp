#include "Eau.hpp"

/*
virtual void vieillir();
virtual Couleur getCouleur();
virtual int getvie();
Couleur type_;
 int pntvie_;*/

/*Constructeur*/
Eau::Eau(){
  type_(None);
}
/*Vieillir mais pas utilisé ici*/
Eau::vieillir(){
}

Couleur
Eau::getCouleur(){
  return this.type_;
};

/*getVie*/
Eau::getvie(){
};
