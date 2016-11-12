#include "Grenouille.hpp"


/*Constructeur*/
Grenouille::Grenouille(){
  pointVie_ = 1;
}

/*Deplacer la grenouille vers le case voisine nord*/
void
Grenouille::deplacerNord(){
  int y = posCour_.getY();
  posCour_.setY(y-1);
};

/*Deplacer la grenouille vers le case voisine sud*/
void
Grenouille::deplacerSud(){
  int y = posCour_.getY();
  posCour_.setY(y+1);
};

/*Deplacer la grenouille vers le case voisine est*/
void
Grenouille::deplacerEst(){
  int x = posCour_.getX();
  posCour_.setX(y+1);
};

/*Deplacer la grenouille vers le case voisine ouest*/
void
Grenouille::deplacerOuest(){
  int x = posCour_.getX();
  posCour_.setX(y-1);
};

void
Grenouille::reduirePtvie(const Element & e){
  Couleur t = e->getCouleur();
  switch (t) {
    case Rose:
      pointVie_++;
      guerir();
      break;
    case RougeDopant:
      pointVie_ = pointVie_*2;
      if(malade_){
        guerir();
      }
      break;
    case RougeMortel:
      pointVie_ = 0;
      break;
    case Jaune:
      if(!malade_){
        rendreMalade();
        pointVie_ = pointVie_/2;
      }
      else{
        pointVie_ = 0;
      }
      break;
      /*Eau, Nenuphard immortel et normal aucun effet sur la grenouille*/
    default:
  }
};

int
Grenouille::getVie(){
  return pointVie_;
};

void
Grenouille::rendreMalade(){
  if(malade_){
    pointVie_ = 0;
  }
  else
    malade_ = true;
};

void
Grenouille::guerir(){
  malade_ = false;
};
