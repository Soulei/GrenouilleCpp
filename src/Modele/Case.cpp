#include "Case.hpp"

namespace grenouilloland{
  /*Constructeur Case*/
  Case::Case(const Coordonnee * c): pos_(c){
  };

  /*RemplacerElt*/
  Case::remplaceElt(Element const * e){
    e_ = e;
  };

  /*Position*/
  Case::getPosition(){
    return pos_;
  };

  const Element
  Case::getElement(){
    return e_;
  };

  const Element
  Case::setElement(Element * e){
    e_ = e;
  };

  void
  Case::vieillirElt(){
    e_.vieillir();
  }
  Couleur const
  Case::couleurElt() const{
    return e_.getCouleur();
  }
  /*Set position*/
  Case::setPosition(Coordonnee & coord){
    pos_ = coord;
  };
}
