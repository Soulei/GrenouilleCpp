#include "SNenuphardVeneneux.hpp"
/*
virtual void vieillir();
virtual Couleur getCouleur();
virtual int getvie();
Couleur type_;
 int pntvie_;*/

/*Constructeur*/
SNenuphardVeneneux::SNenuphardVeneneux(){
  type_(Jaune);
  pntvie_(60);
};
/*Vieillir mais pas utilisé ici*/
void
Eau::vieillir(){
  (this.pntvie_)--;
};
Couleur
Eau::getCouleur(){
  return this.type_;
};

/*getVie*/
int
Eau::getvie(){
  return this.pntvie_;
};
