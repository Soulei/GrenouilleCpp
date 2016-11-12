#include "Case.hpp"

/*
Case(const Element & elt);
virtual ~Case();
void remplaceElt(Element const & e);
Coordonnee getPosition();
void setPosition(Coordonnee & coord) const;
Element e_;
Coordonnee pos_;
*/
/*Constructeur Case*/
Case::Case(const Element & elt){
  e_(elt);
};

/*Destructeur Case*/
Case:: ~Case(){};

/*RemplacerElt*/
Case::remplaceElt(Element const & e){
  e_ = *e;
};

/*Position*/
Case::getPosition(){
  return pos_;
};

const Element
Case::getElement(){
  return e_;
};

/*Set position*/
Case::setPosition(Coordonnee & coord){
  pos_ = *coord;
};
