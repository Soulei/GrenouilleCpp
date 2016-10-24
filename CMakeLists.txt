# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
 
# Chemin du répertoire contenant les binaires.
SET( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

# Modules nécessaires.
FIND_PACKAGE( PkgConfig REQUIRED )
PKG_CHECK_MODULES( GTKMM gtkmm-3.0 )

# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES( src/exercice/modele/include 
		     src/exercice/presentateur/include
		     src/exercice/vue/include
		     ${GTKMM_INCLUDE_DIRS}
)

# Option du compilateur pour supporter C++ 2011.
SET( CMAKE_CXX_FLAGS "-std=c++11")

# Librairies nécessaires à l'édition de liens.
LINK_DIRECTORIES( ${GTKMM_LIBRARY_DIRS} )

# Création des exécutables.
ADD_EXECUTABLE( jeudelavie
		src/exercice/client/jeudelavie.cpp
		src/exercice/modele/JeuDeLaVie.cpp
		src/exercice/modele/Cellule.cpp
		src/exercice/modele/Iterateur.cpp
		src/exercice/presentateur/Presentateur.cpp
		src/exercice/vue/Vue.cpp
		src/exercice/vue/JeuDeLaVieGraphique.cpp
		src/exercice/vue/CelluleGraphique.cpp
		src/exercice/vue/Dimension.cpp
)

TARGET_LINK_LIBRARIES( jeudelavie ${GTKMM_LIBRARIES} )

# Faire parler le make.
set( CMAKE_VERBOSE_MAKEFILE off )

