#include "SNenuphardDopant.hpp"

namespace grenouilloland{
  /*Constructeur*/
  SNenuphardDopant::SNenuphardDopant(){
    type_(RougeDopant);
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
