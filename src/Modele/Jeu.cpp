#include "Jeu.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>
/*
Jeu(const int & dimension);
void initialiser();

void construireChemin();
void lancerJeu();
Grenouille * grenouille_;
const int dimension_;
Grille mare_;
*/
/*Constante Nenuphard*/
const N = 6;
const xstart = 0;
const ystart = 0;

/*Constructeur*/
Jeu::Jeu(const int & dimension) : dimension_(dimension){
  *grenouille_ = new Grenouille();
  mare_ = new Grille(dimension_);
}

void
Jeu::initialiser(){
  std::srand(std::time(0)); // use current time as seed for random generator
  int random_variable = 0;
  for(int i; i< dimension_; i++){
    for(int j; j< dimension_; j++){
      if((i == 0 && j == dimension_-1) || (i == dimension_-1 && j == 0)){
        mare_(i,j) = new Case(new SNenuphardImmortel());
      }
      random_variable = (std::rand()%N)+1;
      switch (random_variable) {
        case Rose:
          mare_(i,j) = new Case(new SNenuphardNutritif());
          break;
        case RougeDopant:
          mare_(i,j) = new Case(new SNenuphardDopant());
          break;
        case RougeMortel:
          mare_(i,j) = new Case(new SNenuphardMortel());
          break;
        case Jaune:
          mare_(i,j) = new Case(new SNenuphardVeneneux());
          break;
          /*Eau, Nenuphard immortel et normal aucun effet sur la grenouille*/
        case None:
          mare_(i,j) = new Case(new Eau());
          break;
        case Vert:
            mare_(i,j) = new Case(new SNenuphardNormal());
          break;
      }
    }
  }
};

/*Lancer le jeu*/
void
Jeu::lancerJeu(){
  /*Set la position de la grenouille*/
  grenouille_.setPosition(new Coordonnee(dimension_, ystart));
  int nextPos;
  while(true){
    std::cout << "Directions : " << std::endl;
    std::cout << "<8> : nord" << std::endl;
    std::cout << "<2> : esud" << std::endl;
    std::cout << "<6> : est" << std::endl;
    std::cout << "<4> : ouest" << std::endl;
    std::cout << "Entrez la direction : " << std::endl;
    std::cin >> nextPos;
    

  }
}

/*Construire un nouveau chemin pour la grenouille quand les nenuphards
des cases voisines sont morts*/
void
Grille::construireChemin(){
  /*1er cas : construire un chemin sur une ligne entre pos de la grenouille et le Nenuphard immortel*/

}
