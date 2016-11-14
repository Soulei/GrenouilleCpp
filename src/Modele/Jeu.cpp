#include "Jeu.hpp"
#include "SNenuphardDopant.hpp"
#include "SNenuphardImmortel.hpp"
#include "SNenuphardMortel.hpp"
#include "SNenuphardNormal.hpp"
#include "SNenuphardNutritif.hpp"
#include "SNenuphardVeneneux.hpp"
#include "Eau.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>



namespace grenouilloland{
  /*Constante Nenuphard*/
  const int N = 6;
  const int xstart = 0;
  const int ystart = 0;

  /*Constructeur*/
  Jeu::Jeu(const int & dimension) : dimension_(dimension){
    Coordonnee g = Coordonnee(dimension, ystart);
    grenouille_ = new Grenouille(g);
    for (int i = 0; i < dimension; i ++) {
      for (int j = 0; j < dimension; j ++) {
        grille_.push_back(Case(new Coordonnee(i, j)));
      }
    }
  }

  void
  Jeu::initialiser(){
    std::srand(std::time(0)); // use current time as seed for random generator
    int random_variable = 0;
    for(int i = 0; i< dimension_; i++){
      for(int j = 0; j< dimension_; j++){
        if((i == 0 && j == dimension_-1) || (i == dimension_-1 && j == 0)){
          grille_[i * dimension_ + j].setElement(new SNenuphardImmortel());
        }
        random_variable = (std::rand()%N)+1;
        switch (random_variable) {
          case Rose:
            grille_[i * dimension_ + j].setElement(new SNenuphardNutritif());
            break;
          case RougeDopant:
            grille_[i * dimension_ + j].setElement(new SNenuphardDopant());
            break;
          case RougeMortel:
            grille_[i * dimension_ + j].setElement(new SNenuphardMortel());
            break;
          case Jaune:
            grille_[i * dimension_ + j].setElement(new SNenuphardVeneneux());
            break;
            /*Eau, Nenuphard immortel et normal aucun effet sur la grenouille*/
          case None:
            grille_[i * dimension_ + j].setElement(new Eau());
            break;
          case Vert:
              grille_[i * dimension_ + j].setElement(new SNenuphardNormal());
            break;
        }
      }
    }
  };

  /*Lancer le jeu*/
  void
  Jeu::lancerJeu(){
    /*Set la position de la grenouille*/
    int nextPos;
    std::chrono::time_point<std::chrono::system_clock> start;
    start = std::chrono::system_clock::now(); /* start timer */
    while(true){
      int secondsElapsed = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now()-start).count();
      if(secondsElapsed >= 1){ /* 20 seconds elapsed -> faire vieillir les nenuphards */
        for(int i = 0; i<dimension_;i++){
          for(int j = 0; j<dimension_;j++){
            grille_[i * dimension_ + j].vieillirElt();
          }
        }
      }
      std::cout << "Directions : " << std::endl;
      std::cout << "<8> : nord" << std::endl;
      std::cout << "<2> : sud" << std::endl;
      std::cout << "<6> : est" << std::endl;
      std::cout << "<4> : ouest" << std::endl;
      std::cout << "Entrez la direction : " << std::endl;
      std::cin >> nextPos;
      while(nextPos != 8 && nextPos != 2 && nextPos != 6 && nextPos != 4){
        std::cout << "Entrez la direction : " << std::endl;
        std::cin >> nextPos;
      }
      if(grenouille_->cheminExiste(*this)){
        switch (nextPos) {
          case 8:grenouille_->deplacerNord();break;
          case 2:grenouille_->deplacerSud();break;
          case 6:grenouille_->deplacerEst();break;
          case 4:grenouille_->deplacerOuest();break;
        }
        grenouille_->reduirePtvie((grille_[grenouille_->getPosCour().getX() * dimension_ + grenouille_->getPosCour().getY()]).getElement());
        if(!grenouille_->estVivante()){
          break;
        }
      }
      else{
        construireChemin();
      }


    }
  }

  /*Construire un nouveau chemin pour la grenouille quand les nenuphards
  des cases voisines sont morts*/
  void
  Jeu::construireChemin(){
    /*1er cas : construire un chemin sur une ligne entre pos de la grenouille et le Nenuphard immortel*/
    if(grenouille_->getPosCour().getX() == xstart){
      for(int j = grenouille_->getPosCour().getY()+1; j < dimension_; j++){
        int random_variable = (std::rand()%N)+1;
        switch (random_variable) {
          case Rose:
            grille_[xstart * dimension_ + j].remplaceElt(new SNenuphardNutritif());
            break;
          case RougeDopant:
            grille_[xstart * dimension_ + j].remplaceElt(new SNenuphardDopant());
            break;
          case RougeMortel:
            grille_[xstart * dimension_ + j].remplaceElt(new SNenuphardMortel());
            break;
          case Jaune:
            grille_[xstart * dimension_ + j].remplaceElt(new SNenuphardVeneneux());
            break;
          default:
            grille_[xstart * dimension_ + j].remplaceElt(new SNenuphardNormal());
            break;
        }
      }
    }
    /*2eme cas : construire un chemin sur une colonne entre pos de la grenouille et le Nenuphard immortel*/
    if(grenouille_->getPosCour().getY() == dimension_){
      for(int j = grenouille_->getPosCour().getX()+1; j < dimension_; j++){
        int random_variable = (std::rand()%N)+1;
        switch (random_variable) {
          case Rose:
            grille_[dimension_ * dimension_ + j].remplaceElt(new SNenuphardNutritif());
            break;
          case RougeDopant:
            grille_[dimension_ * dimension_ + j].remplaceElt(new SNenuphardDopant());
            break;
          case RougeMortel:
            grille_[dimension_ * dimension_ + j].remplaceElt(new SNenuphardMortel());
            break;
          case Jaune:
            grille_[dimension_ * dimension_ + j].remplaceElt(new SNenuphardVeneneux());
            break;
          default:
            grille_[dimension_ * dimension_ + j].remplaceElt(new SNenuphardNormal());
            break;
        }
      }
    }
    /*3eme cas: Construire un chemin en rectangle entre la grenouille et le Nenuphard immortel*/
    else{
        int x = grenouille_->getPosCour().getX();
        int y = grenouille_->getPosCour().getY();
        for(int j = grenouille_->getPosCour().getX()-1; j >= xstart; j--){
          int random_variable = (std::rand()%N)+1;
          switch (random_variable) {
            case Rose:
              grille_[j * dimension_ + y].remplaceElt(new SNenuphardNutritif());
              grille_[j * dimension_ + (dimension_-1)].remplaceElt(new SNenuphardNutritif());
              break;
            case RougeDopant:
              grille_[j * dimension_ + y].remplaceElt(new SNenuphardDopant());
              grille_[j * dimension_ + (dimension_-1)].remplaceElt(new SNenuphardNutritif());
              break;
            case RougeMortel:
              grille_[j * dimension_ + y].remplaceElt(new SNenuphardMortel());
              grille_[j * dimension_ + (dimension_-1)].remplaceElt(new SNenuphardNutritif());
              break;
            case Jaune:
              grille_[j * dimension_ + y].remplaceElt(new SNenuphardVeneneux());
              grille_[j * dimension_ + (dimension_-1)].remplaceElt(new SNenuphardNutritif());
              break;
            default:
              grille_[j * dimension_ + y].remplaceElt(new SNenuphardNormal());
              grille_[j * dimension_ + (dimension_-1)].remplaceElt(new SNenuphardNutritif());
              break;
          }
        }
        for(int i = grenouille_->getPosCour().getY()+1; i < dimension_; i++){
          int random_variable = (std::rand()%N)+1;
          switch (random_variable) {
            case Rose:
              grille_[x * dimension_ + i].remplaceElt(new SNenuphardNutritif());
              grille_[xstart * dimension_ + i].remplaceElt(new SNenuphardNutritif());
              break;
            case RougeDopant:
              grille_[x * dimension_ + i].remplaceElt(new SNenuphardDopant());
              grille_[xstart * dimension_ + i].remplaceElt(new SNenuphardNutritif());
              break;
            case RougeMortel:
              grille_[x * dimension_ + i].remplaceElt(new SNenuphardMortel());
              grille_[xstart * dimension_ + i].remplaceElt(new SNenuphardNutritif());
              break;
            case Jaune:
              grille_[x * dimension_ + i].remplaceElt(new SNenuphardVeneneux());
              grille_[xstart * dimension_ + i].remplaceElt(new SNenuphardNutritif());
              break;
            default:
              grille_[x * dimension_ + i].remplaceElt(new SNenuphardNormal());
              grille_[xstart * dimension_ + i].remplaceElt(new SNenuphardNutritif());
              break;
          }
        }
      }
  }

  const std::vector< Case > & 
  Jeu::lireGrille(){
    return grille_;
  }

}
