#include "SNenuphardVeneneux.hpp"

namespace grenouilloland{
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
  Couleur const
  Eau::getCouleur(){
    return this.type_;
  };

  /*getVie*/
  int
  Eau::getvie(){
    return this.pntvie_;
  };
}
