#include "Coordonnee.hpp"

namespace grenouilloland{
  Coordonnee::Coordonnee(const int & x, const int & y): x_(x), y_(y){
  }

  int
  Coordonnee::getX(){
    return x_;
  };

  int
  Coordonnee::getY(){
    return y_;
  };

  int
  Coordonnee::setX(int x){
    x_ = x;
  };

  int
  Coordonnee::setY(int y){
    y_ = y;
  };
}
