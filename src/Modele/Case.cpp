#include "Case.hpp"

namespace grenouilloland{
  /*Constructeur Case*/
  Case::Case(const Coordonnee & c): pos_(c){
  };

  /*RemplacerElt*/
  void
  Case::remplaceElt(const Element & e){
    e_ = e;
  };

  /*Position*/
  Coordonnee
  Case::getPosition(){
    return pos_;
  };

  const Element
  Case::getElement(){
    return e_;
  };

  void
  Case::setElement(Element e){
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
  /*Set position
  void
  Case::setPosition(Coordonnee & coord) const{
    pos_ = &coord;
  };*/
}
