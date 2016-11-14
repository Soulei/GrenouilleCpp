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
_ptrVue(&vue),
_listeDim(false)
{

	// Obtention du presentateur.
	const Presentateur& presentateur = vue.lirePresentateur();

	// Obtention des valeurs min, max et init de la dimension du jeu.
	const int min = presentateur.lireDimensionMinimum();
	const int max = presentateur.lireDimensionMaximum();
	const int init = presentateur.dimension();

	std::ostringstream conversion;

	// Création des champs du menu déroulant.
	for(int i = min; i <= max; i++) {
		conversion << i;
		_listeDim.append(conversion.str());
		conversion.str("");
	}

	conversion << init;

	// Dimension initiale
	_listeDim.set_active_text(conversion.str());
	add(_listeDim);

	// Connection sur la méthode cbChangementDeValeur.
	_listeDim.signal_changed().connect(sigc::mem_fun(*this, &Dimension::cbChangementDeValeur));
}

/************
* lireVue. *
************/

const VueGrenouille&
Dimension::lireVue() const {
	return *_ptrVue;
}

/***********
* valeur. *
***********/

int
Dimension::valeur() const {

	Glib::ustring text = _listeDim.get_active_text();
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
