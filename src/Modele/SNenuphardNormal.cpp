#include "SNenuphardNormal.hpp"

namespace grenouilloland{
  /*Constructeur*/
  SNenuphardNormal::SNenuphardNormal(){
    type_(Vert);
    pntvie_(60);
  };
  /*Vieillir mais pas utilisé ici*/
  void
  Eau::vieillir(){
    (this.pntvie_)--;
  };
  Couleur const
  Eau::getCouleur() const{
    return this.type_;
  };

  /*getVie*/
  int
  Eau::getvie(){
    return this.pntvie_;
  };
}
