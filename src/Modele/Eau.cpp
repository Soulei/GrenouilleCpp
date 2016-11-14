#include "Eau.hpp"

namespace grenouilloland{
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
}
