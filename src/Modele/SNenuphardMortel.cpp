#include "SNenuphardMortel.hpp"

namespace grenouilloland{
  /*Constructeur*/
  SNenuphardMortel::SNenuphardMortel(){
    type_(RougeMortel);
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
