#include "Jeu.hpp"

namespace grenouilloland{
  /*Constructeur*/
  Grenouille::Grenouille(Coordonnee & c): posCour_(c){
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
    posCour_.setX(x+1);
  };

  /*Deplacer la grenouille vers le case voisine ouest*/
  void
  Grenouille::deplacerOuest(){
    int x = posCour_.getX();
    posCour_.setX(x-1);
  };

  void
  Grenouille::reduirePtvie(const Element & e){
    Couleur t = e.getCouleur();
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

  bool
  Grenouille::estVivante(){
    return pointVie_ == 0?false:true;
  };

  Coordonnee &
  Grenouille::getPosCour(){
    return posCour_;
  }

  bool
  Grenouille::cheminExiste(Jeu & jeu) const{
    int dim = jeu.lireDimension();
    int x = posCour_.getX();
    int y = posCour_.getY();
    if(x == 0 && y == 0){
      if((jeu.lireGrille())[(x+1)*dim+y].couleurElt() == None){
        if((jeu.lireGrille())[x*dim+y+1].couleurElt() == None)
          return true;
      }
    }
    if(x >0 && y == 0 && x < jeu.lireDimension()){
      if((jeu.lireGrille())[(x+1)*dim+y].couleurElt() == None){
        if((jeu.lireGrille())[(x+1)*dim+y].couleurElt() == None){
          if((jeu.lireGrille())[(x-1)*dim+y].couleurElt() == None)
            return true;
        }
      }
    }
    if(x ==0 && y > 0 && y < jeu.lireDimension()){
      if((jeu.lireGrille())[x*dim+y+1].couleurElt() == None){
        if((jeu.lireGrille())[(x+1)*dim+y].couleurElt() == None){
          if((jeu.lireGrille())[x*dim+y-1].couleurElt() == None)
            return true;
        }
      }
    }

    if(x > 0 && y > 0 || x < jeu.lireDimension() && y < jeu.lireDimension()){
      if((jeu.lireGrille())[x*dim+y+1].couleurElt() == None){
        if((jeu.lireGrille())[(x+1)*dim+y].couleurElt() == None){
          if((jeu.lireGrille())[x*dim+y-1].couleurElt() == None){
            if((jeu.lireGrille())[(x-1)*dim+y].couleurElt() == None){
              return true;
            }
          }
        }
      }
    }
    return false;
  }
}
