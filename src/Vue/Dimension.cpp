/****************************
* Definition de la classe. *
****************************/

#include "Presentateur.hpp"
#include "Dimension.hpp"

using namespace grenouille;

/**************
* Dimension. *
**************/

Dimension::Dimension(const Glib::ustring& titre, VueGrenouille& vue):
Gtk::Frame(titre),
ptrVue(&vue),
listeDim(false)
{

// Obtention du presentateur.
const Presentateur& presentateur = vue.lirePresentateur();

// Récupération des valeurs minimale, maximale et initiale de la dimension
// du jeu.
const int min = presentateur.lireDimensionMinimum();
const int max = presentateur.lireDimensionMaximum();
const int init = presentateur.dimension();

std::ostringstream conversion;

// Création des champs du menu déroulant.  	
for(int i = min; i <= max; i++) {
conversion << i;
listeDim.append(conversion.str());
conversion.str("");
}

conversion << init;

// Dimension initiale en champs sélectionné.
listeDim.set_active_text(conversion.str());

add(listeDim);

// Connection de l'évènement changement de champs sélectionné sur 
// la méthode cbChangementDeValeur.
listeDim.signal_changed().connect(sigc::mem_fun(*this, &Dimension::cbChangementDeValeur));

}

/************
* lireVue. *
************/

const Vue& 
Dimension::lireVue() const {
return *ptrVue;
}

/***********
* valeur. *
***********/

int 
Dimension::valeur() const {
Glib::ustring text = listeDim.get_active_text();
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
ptrVue->cbChangerModele();

}
