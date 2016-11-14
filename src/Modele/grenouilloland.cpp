/**
 * @mainpage
 *
 * Jeu de la grenouille
 *
 * @author Choukri SOULEIMAN IMAN
 */

#include "Jeu.hpp"
#include <iostream>
#include <map>
#include <cstdlib>
#include <sstream>


/**
 * Programme principal.
 *
 * @return @c EXIT_SUCCESS en cas d'exécution réussie ou @c EXIT_FAILURE sinon.
 */
int
main(int argc, char* argv[]){
  if(argc <= 1){
    std::cout << "Usage: <\\." << argv[0] << "> <dimension de la mare>";
    return EXIT_FAILURE;
  }
  else{
    int dim;
    std::istringstream entree(argv[1]);
    entree >> dim;
    if(dim <= 0 || dim <2){
      std::cout << "Taille incorrect du plateau" << std::endl;
      return EXIT_FAILURE;
    }
    else{
      grenouilloland::Jeu * j = new grenouilloland::Jeu(dim);
      j->initialiser();
      j->lancerJeu();
    }

  }
  return EXIT_SUCCESS;
}
