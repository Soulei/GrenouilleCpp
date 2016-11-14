/*********************************************
* Definition de la classe CelluleGraphique. *
*********************************************/

#include "Presentateur.hpp"
#include "Etat.hpp"

using namespace grenouille;

/*********************
* CelluleGraphique. *
*********************/

CelluleGraphique::CelluleGraphique(GrenouilleGraphique& grenouilleGraphique,
			   const int& colonne,
			   const int& ligne):
ptrGrenouilleGraphique(&grenouilleGraphique),
ligne(ligne),
colonne(colonne) {

// Obtention de la vue.
const VueGrenouille& vue = _ptrGrenouilleGraphique->lireVue();

// Obtention du presentateur.
const Presentateur& presentateur = vue.lirePresentateur();

// Creation des pixmaps representants les etats d'une cellule.
{

// Renommage de type local.
typedef std::unique_ptr< Gtk::Image > PtrImage;

// Grandes	

// L'élément de la cellule est Eau.
_etats[0] = PtrImage(new Gtk::Image(vue.lireImage("eau")));

// L'élément de la cellule est Nenuphar.
_etats[1] = PtrImage(new Gtk::Image(vue.lireImage("nen")));

// L'élément de la cellule est NenupharDopant.
_etats[2] = PtrImage(new Gtk::Image(vue.lireImage("nen_dopant")));

// L'élément de la cellule est NenupharImmortel.
_etats[3] = PtrImage(new Gtk::Image(vue.lireImage("nen")));

// L'élément de la cellule est NenupharMortel.
_etats[4] = PtrImage(new Gtk::Image(vue.lireImage("nen_dopant")));

// L'élément de la cellule est NenupharNutritif.
_etats[5] = PtrImage(new Gtk::Image(vue.lireImage("nen_nutritif")));

// L'élément de la cellule est NenupharVeneneux.
_etats[6] = PtrImage(new Gtk::Image(vue.lireImage("nen_veneneux")));

// Moyennes	

// L'élément de la cellule est Eau.
_etats[7] = PtrImage(new Gtk::Image(vue.lireImage("eau")));

// L'élément de la cellule est Nenuphar.
_etats[8] = PtrImage(new Gtk::Image(vue.lireImage("nen_moyen")));

// L'élément de la cellule est NenupharDopant.
_etats[9] = PtrImage(new Gtk::Image(vue.lireImage("nen_dopant_moyen")));

// L'élément de la cellule est NenupharImmortel.
_etats[10] = PtrImage(new Gtk::Image(vue.lireImage("nen")));

// L'élément de la cellule est NenupharMortel.
_etats[11] = PtrImage(new Gtk::Image(vue.lireImage("nen_dopant_moyen")));

// L'élément de la cellule est NenupharNutritif.
_etats[12] = PtrImage(new Gtk::Image(vue.lireImage("nen_nutritif_moyen")));

// L'élément de la cellule est NenupharVeneneux.
_etats[13] = PtrImage(new Gtk::Image(vue.lireImage("nen_veneneux_moyen")));

// Petites	

// L'élément de la cellule est Eau.
_etats[14] = PtrImage(new Gtk::Image(vue.lireImage("eau")));

// L'élément de la cellule est Nenuphar.
_etats[15] = PtrImage(new Gtk::Image(vue.lireImage("nen_petit")));

// L'élément de la cellule est NenupharDopant.
_etats[16] = PtrImage(new Gtk::Image(vue.lireImage("nen_dopant_petit")));

// L'élément de la cellule est NenupharImmortel.
_etats[17] = PtrImage(new Gtk::Image(vue.lireImage("nen")));

// L'élément de la cellule est NenupharMortel.
_etats[18] = PtrImage(new Gtk::Image(vue.lireImage("nen_dopant_petit")));

// L'élément de la cellule est NenupharNutritif.
_etats[19] = PtrImage(new Gtk::Image(vue.lireImage("nen_nutritif_petit")));

// L'élément de la cellule est NenupharVeneneux.
_etats[20] = PtrImage(new Gtk::Image(vue.lireImage("nen_veneneux_petit")));

// Avec Grenouille
// L'élément de la cellule est Eau.
_etats[21] = PtrImage(new Gtk::Image(vue.lireImage("gren_eau")));

// L'élément de la cellule est Nenuphar.
_etats[22] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen")));

// L'élément de la cellule est NenupharDopant.
_etats[23] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen_dopant")));

// L'élément de la cellule est NenupharImmortel.
_etats[24] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen")));

// L'élément de la cellule est NenupharMortel.
_etats[25] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen_dopant")));

// L'élément de la cellule est NenupharNutritif.
_etats[26] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen_nutritif")));

// L'élément de la cellule est NenupharVeneneux.
_etats[27] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen_veneneux")));

// Moyennes	

// L'élément de la cellule est Eau.
_etats[28] = PtrImage(new Gtk::Image(vue.lireImage("gren_eau")));

// L'élément de la cellule est Nenuphar.
_etats[29] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen_moyen")));

// L'élément de la cellule est NenupharDopant.
_etats[30] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen_dopant_moyen")));

// L'élément de la cellule est NenupharImmortel.
_etats[31] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen")));

// L'élément de la cellule est NenupharMortel.
_etats[32] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen_dopant_moyen")));

// L'élément de la cellule est NenupharNutritif.
_etats[33] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen_nutritif_moyen")));

// L'élément de la cellule est NenupharVeneneux.
_etats[34] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen_veneneux_moyen")));

// Petites	

// L'élément de la cellule est Eau.
_etats[35] = PtrImage(new Gtk::Image(vue.lireImage("gren_eau")));

// L'élément de la cellule est Nenuphar.
_etats[36] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen_petit")));

// L'élément de la cellule est NenupharDopant.
_etats[37] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen_dopant_petit")));

// L'élément de la cellule est NenupharImmortel.
_etats[38] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen")));

// L'élément de la cellule est NenupharMortel.
_etats[39] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen_dopant_petit")));

// L'élément de la cellule est NenupharNutritif.
_etats[40] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen_nutritif_petit")));

// L'élément de la cellule est NenupharVeneneux.
_etats[41] = PtrImage(new Gtk::Image(vue.lireImage("gren_nen_veneneux_petit")));
}

// Connection du callback associe au click de souris.
{
auto crochet = sigc::mem_fun(*this, &CelluleGraphique::cbClickSouris);
signal_button_press_event().connect(crochet);
}

// Mise a jour de cette cellule graphique.
mettreAJour(presentateur);

}

/****************************
* lireGrenouilleGraphique. *
****************************/

const GrenouilleGraphique& 
CelluleGraphique::lireGrenouilleGraphique() const {
return *ptrGrenouilleGraphique;
}

/****************
* lireColonne. *
****************/

const int& 
CelluleGraphique::lireColonne() const {
return colonne;
}

/**************
* lireLigne. *
**************/

const int& 
CelluleGraphique::lireLigne() const {
return ligne;
}

/****************
* mettreAJour. *
****************/

void 
CelluleGraphique::mettreAJour(const Presentateur& presentateur) {

// Obtention du nouvel etat de la cellule du modele correspondante via le 
// presentateur.
const int id = presentateur.lireModele().lireCase(_ligne,_colonne).lireElement().lireId();
Etat etat = presentateur.lireModele().lireCase(_ligne,_colonne).lireElement().lireEtat();
int n = 0;
if(etat == Etat::Moyen)
n = 1;
else if(etat == Etat::Petit)
n = 2;

if (presentateur.lireModele().presenceGrenouille(_ligne,_colonne)) n+=3;

// Obtention du pixmap correspondant.
Gtk::Image& image = *_etats[id+n*(_etats.size()/6)];

// Si l'etat de cette cellule n'a pas change, il n'y a rien a faire.
if (&image == get_child()) {
return;
}

// Sinon, suppression de l'ancien pixmap et affichage du nouveau.
remove();
add(image);
image.show();
}

/******************
* cbClickSouris. *
******************/

bool 
CelluleGraphique::cbClickSouris(GdkEventButton* evt) {

// Obtention de la vue modifiable.
VueGrenouille& vue = _ptrGrenouilleGraphique->lireVueModifiable();

// Obtention du presentateur modifiable associe a la vue.
Presentateur& presentateur = vue.lirePresentateurModifiable();

// Verrouillage de la vue.
vue.verrouiller();

Presentateur::MandataireCelluleGraphique::deplacerGrenouille(presentateur, _ligne,_colonne);

// Mise a jour de cette cellule graphique.
_ptrGrenouilleGraphique->mettreAJour(presentateur);

// Deverrouillage de la vue.
vue.deverrouiller();

return true;
}
