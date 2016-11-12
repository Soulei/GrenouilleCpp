#include "SNenuphardImmortel.hpp"
/*
virtual void vieillir();
virtual Couleur getCouleur();
virtual int getvie();
Couleur type_;
 int pntvie_;*/

/*Constructeur*/
SNenuphardImmortel::SNenuphardNormal(){
  type_(Vert);
  pntvie_(60);
};
/*Vieillir mais pas utilisé ici*/
void
Eau::vieillir(){
};

Couleur
Eau::getCouleur(){
  return this.type_;
};

/*getVie*/
int
Eau::getvie(){
};
