#include "Grille.hpp"

/*Constructeur*/
Grille::Grille(const int & dimension): dimension_(dimension){
  grille_ = new Matrix mat(dimension_, dimension_);
};

/*Destructeur*/
Grille::~Grille(){};

void
Grille::afficher(){
  for(int i=0; i < dimension_; i++){
    for(int j=0; j < dimension_; j++){
      std::cout << grille(i,j).getElement().getCouleur() << "\t";
    }
    std::cout << std::endln;
  }
};
