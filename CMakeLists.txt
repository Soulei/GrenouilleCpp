# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )

# Chemin du répertoire contenant les binaires.
SET( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

# Modules nécessaires.
FIND_PACKAGE( PkgConfig REQUIRED )
FIND_PACKAGE( Doxygen REQUIRED )
PKG_CHECK_MODULES( GTKMM gtkmm-3.0 )

# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES( src/Modele/include
		     src/Presentateur/include
		     src/Vue/include
		     ${GTKMM_INCLUDE_DIRS}
)

# Option du compilateur pour supporter C++ 2011.
SET( CMAKE_CXX_FLAGS "-std=c++0x")

# Options de l'éditeur de lien pour supporter cmath.
set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lm" )

# Librairies nécessaires à l'édition de liens.
LINK_DIRECTORIES( ${GTKMM_LIBRARY_DIRS} )

# Création des exécutables.
ADD_EXECUTABLE( grenouilloland
		src/client/grenouilloland.cpp
		src/Modele/Jeu.cpp
		src/Modele/Cellule.cpp
		src/Modele/Eau.cpp
		src/Modele/Element.cpp
		src/Modele/ElementMortel.cpp
		src/Modele/Etat.cpp
		src/Modele/Grenouille.cpp
		src/Modele/Nenuphar.cpp
		src/Modele/NenupharDopant.cpp
		src/Modele/NenupharImmortel.cpp
		src/Modele/NenupharMortel.cpp
		src/Modele/NenupharNutritif.cpp
		src/Modele/NenupharVeneneux.cpp
		src/Modele/StrategieAbstraite.cpp
		src/Modele/StrategieDopante.cpp
		src/Modele/StrategieMort.cpp
		src/Modele/StrategieNutritive.cpp
		src/Modele/StrategieVeneneuse.cpp
		src/Modele/StrategieNeutre.cpp
		src/Presentateur/Presentateur.cpp
		src/Vue/VueGrenouille.cpp
		src/Vue/GrenouilleGraphique.cpp
		src/Vue/CelluleGraphique.cpp
		src/Vue/Chronometre.cpp
		src/Vue/Dimension.cpp
		src/Vue/PointDeVie.cpp
)

TARGET_LINK_LIBRARIES( grenouilloland ${GTKMM_LIBRARIES} )

# Faire parler le make.
set( CMAKE_VERBOSE_MAKEFILE off )
