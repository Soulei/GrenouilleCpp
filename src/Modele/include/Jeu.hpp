#ifndef Jeu_hpp
#define Jeu_hpp

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <gtkmm.h>

#include "Grenouille.hpp"
#include "Case.hpp"

#include "Eau.hpp"
#include "NenupharImmortel.hpp"
#include "Nenuphar.hpp"
#include "NenupharMortel.hpp"
#include "NenupharNutritif.hpp"
#include "NenupharVeneneux.hpp"
#include "NenupharDopant.hpp"

namespace grenouilloland {

/**
 * @class Jeu Jeu.hpp
 * @brief Jeu du Jeu Grenouilloland.
 *
 * Declaration de la classe Jeu réprésentant le plateau du jeu Grenouilloland.
 */
class Jeu
{		
	public :
		/**
		 * Constructeur logique du jeu.
		 *
		 * @param[in] n - taille du plateau de dimension n*n.
		 */
		Jeu(const int& n);
		
	public:
		
		/**
		 * Accesseur de la dimension du plateau.
		 *
		 * @return la valeur de @ref _n.
		 */
		const int& lireDimension() const;
		
		/**
		 * Accesseur du compteur.
		 *
		 * @return la valeur de @ref _compteur.
		 */
		const unsigned int& lireCompteur() const;
		
		/**
		 * Accesseur d'une case du plateau.
		 *
		 * @param[in] ligne - ligne de la case du plateau.
		 * @param[in] colonne - colonne de la case du plateau.
		 *
		 * @return référence constante sur une case du plateau.
		 */
		const Case& lireCase(const int& ligne, const int& colonne) const;
		
		/**
		 * Accesseur du nombre de pv de la grenouille.
		 *
		 * @return nombre de pv de la grenouille.
		 */
		const unsigned int& lirePvGrenouille() const;
		
		/**
		 * Accesseur de l'état de santé de la grenouille.
		 *
		 * @return la valeur de l'état de santé de la grenouille.
		 */
		bool grenouilleMalade() const;
		
		/**
		 * Test de la présence de la grenouille sur une case du plateau.
		 *
		 * @return true si la grenouille est présente sur la case.
		 */
		bool presenceGrenouille(const unsigned int& ligne, const unsigned int& colonne) const;
		
		/**
		 * Accesseur de l'état de fin du jeu.
		 *
		 * @return la valeur de @ref _end.
		 */
		bool end() const;

		/**
		 * Calcul aléatoire d'un nénuphar.
		 *
		 * @return un pointeur sur un type de nénuphar.
		 */
		Element* nenupharAleatoire() const;

	protected :

		/**
		 * Réinitialisation du plateau de jeu.
		 */
		void reinitialiser();
		
		/**
		 * Lancement de la partie.
		 */
		void lancerPartie();
		
		/**
		 * Déplacement de la grenouille.
		 *
		 * @param[in] x - position de la grenouille sur l'axe x.
		 * @param[in] y - position de la grenouille sur l'axe y.
		 *
		 * @return true si le déplacement a été effectué, false sinon.
		 */
		bool deplacerGrenouille(const int& x, const int& y);

		/**
		 * Création de chemins entre la grenouille et la case d'arrivée.
		 */
		void creerChemin();
		
		/**
		 * Vérification de l'état de la grenouille.
		 *
		 * @return true si la grenouille est en vie, false sinon.
		 */
		bool verifEtat();
		
		/**
		 * Calcul du vieillissement des éléments du plateau.
		 *
		 * @return false si la partie est terminée, true sinon.
		 */
		bool vieillissement();

	protected :
		/**
		 * La grenouille appartenant au jeu.
		 */
		Grenouille _grenouille;
		
		/**
		 * Ensemble des cases composant le plateau du jeu.
		 */
		std::vector<Case> _plateau;
		
		/**
		 * Dimension du plateau de jeu.
		 */
		int _n;
		
		/**
		 * Etat de la fin de partie.
		 */
		bool _end;
		
		/**
		 * Compteur du jeu.
		 */
		unsigned int _compteur;

	public:
		
		/**
		 * @class Deleguation
		 * @brief Deleguation du Jeu.
		 *
		 * Declaration de la classe Deleguation de la classe Jeu communiquant avec
		 * le Presentateur ami.
		 */		
		class Deleguation
		{
		
		public :
			friend class Presentateur;			

		private :

			static void reinitialiser(Jeu& jeu)
			{
				jeu.reinitialiser();
			}

			static void lancerPartie(Jeu& jeu)
			{
				jeu.lancerPartie();
			}

			static bool deplacerGrenouille(Jeu& jeu, const int& x, const int& y)
			{
				return jeu.deplacerGrenouille(x, y);
			}

			static void creerChemin(Jeu& jeu)
			{
				jeu.creerChemin();
			}

			static bool vieillissement(Jeu& jeu)
			{
				return jeu.vieillissement();
			}
		};
};

}

#endif
