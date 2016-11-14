/****************************
* Definition de la classe. *
****************************/

#include "Presentateur.hpp"
#include "Dimension.hpp"

using namespace grenouilloland;

/**************
* Dimension. *
**************/

Dimension::Dimension(const Glib::ustring& titre, Vue& vue):
Gtk::Frame(titre),
ptrVue(&vue),
listeDimension(false)
{

// Obtention du presentateur.
const Presentateur& presentateur = vue.lirePresentateur();

// Récupération des valeurs minimale, maximale et initiale de la dimension
// du jeu.
const int minimum = presentateur.lireDimensionMinimum();
const int maximum = presentateur.lireDimensionMaximum();
const int initiale = presentateur.dimension();

std::ostringstream convert;

// Création des champs du menu déroulant.  	
for(int i = minimum; i <= maximum; i++) {
convert << i;
_listeDimension.append(convert.str());
convert.str("");
}

convert << initiale;

// Dimension initiale en champs sélectionné.
_listeDimension.set_active_text(convert.str());

add(_listeDimension);

// Connection de l'évènement changement de champs sélectionné sur 
// la méthode cbChangementDeValeur.
_listeDimension.signal_changed().connect(sigc::mem_fun(*this, &Dimension::cbChangementDeValeur));

}

/************
* lireVue. *
************/

const Vue& 
Dimension::lireVue() const {
return *_ptrVue;
}

/***********
* valeur. *
***********/

int 
Dimension::valeur() const {
Glib::ustring text = _listeDimension.get_active_text();
int value;
std::stringstream(text) >> value;
return value;
}

/*************************
* cbChangementDeValeur. *
*************************/

void 
Dimension::cbChangementDeValeur() {

// Effacement de ce controle pour pouvoir etre reaffichee par sa vue
// proprietaire tout a l'heure.
hide();

// Changement de modele.
_ptrVue->cbChangerModele();

}
