# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )

# Chemin du répertoire contenant les binaires.
SET( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

# Modules nécessaires.
FIND_PACKAGE( PkgConfig REQUIRED )
PKG_CHECK_MODULES( GTKMM gtkmm-3.0 )

# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES( src/Modele/include
		     #src/Presentateur/include
		     #src/Vue/include
		     ${GTKMM_INCLUDE_DIRS}
)

# Option du compilateur pour supporter C++ 2011.
SET( CMAKE_CXX_FLAGS "-std=c++11")

# Librairies nécessaires à l'édition de liens.
LINK_DIRECTORIES( ${GTKMM_LIBRARY_DIRS} )

# Création des exécutables.
ADD_EXECUTABLE( grenouilloland
		src/Modele/grenouilloland.cpp
    src/Modele/Jeu.cpp
		src/Modele/Grenouille.cpp
		src/Modele/Case.cpp
		src/Modele/Coordonnee.cpp
		src/Modele/Eau.cpp
		src/Modele/SNenuphardMortel.cpp
		src/Modele/SNenuphardImmortel.cpp
		src/Modele/SNenuphardNutritif.cpp
		src/Modele/SNenuphardDopant.cpp
		src/Modele/SNenuphardVeneneux.cpp
		src/Modele/SNenuphardNormal.cpp


)

TARGET_LINK_LIBRARIES( grenouilloland ${GTKMM_LIBRARIES} )

# Faire parler le make.
set( CMAKE_VERBOSE_MAKEFILE off )
