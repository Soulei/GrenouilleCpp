#ifndef Presentateur_hpp
#define Presentateur_hpp

#include "Jeu.hpp"
#include "VueGrenouille.hpp"

namespace grenouilloland {

/**
 * @class Presentateur Presentateur.hpp
 * @brief Presentateur de grenouilloland.
 * @author Luc FONTAINE
 * @author Choukri SOULEIMAN IMAN
 * @author Charlie MARECHAL
 * @author Xiaoge YAN
 *
 * Declaration de la classe Presentateur (Modele MVP)
 *
 * @note une instance de cette classe ne peut etre dupliquee.
 */
class Presentateur {

public:

  /**
   * Constructeur logique.
   *
   * @param[in] dimMin - la valeur de @ref _dimMin.
   * @param[in] dimMax - la valeur de @ref _dimMax.
   * @param[in] dimension - la resolution initiale.
   */
  Presentateur(const int& dimMin,
	       const int& dimMax,
	       const int& resolution);

public:

  /**
   * Retourne la dimension du modele associe a ce presentateur.
   *
   * @return la dimension du modele associe a ce presentateur.
   */
  const int& dimension() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _dimMin.
   */
  const int& lireDimMin() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _dimMax.
   */
  const int& lireDimMax() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _ptrModele.
   */
  const Jeu& lireModele() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _ptrVue.
   */
  const VueGrenouille& lireVue() const;



public:
  /**
   * Lance ce presentateur.
   */
  void demarrer();

protected:

  /**
   * Lance une nouvelle partie du Jeu.
   */
  void lancerPartie();

  /**
   * Change le modele associe a ce presentateur.
   *
   * @param[in] dimension - la dimension souhaitee.
   */
  void nouveauModele(const int& dimension);

  /**
   * Déplace la grenouille dans le Jeu.
   *
   * @param[in] ligne - la ligne souhaitee.
   * @param[in] colonne - la colonne souhaitee.
   */
  bool deplacerGrenouille(const int& ligne, const int& colonne);

  /**
   * Lance le vieillissement des éléments du Jeu.
   */
  bool vieillissement();

private:
  /**
   * Constructeur par recopie.
   *
   * @param[in] autre - l'instance a recopier.
   */
  Presentateur(const Presentateur& autre) = delete;

  /**
   * Operateur d'affectation.
   *
   * @param[in] autre - l'instance à recopier.
   * @return cette instance apres recopie.
   */
  Presentateur& operator=(const Presentateur& autre) = delete;

protected:

  /**
   * Dimension minimum du modele.
   */
  const int _dimMin;

  /**
   * Dimension maximum du modele.
   */
  const int _dimMax;

  /**
   * Modele associe a ce presentateur.
   */
  std::unique_ptr< Jeu > _ptrModele;

  /**
   * VueGrenouille associee a ce presentateur.
   */
  std::unique_ptr< VueGrenouille > _ptrVue;

  /**
   * Connecteur de slot à un évènement.
   */
  sigc::connection _conn;

  /**
   * Slot qui sera attaché à la méthode vieillissement.
   */
  const sigc::slot<bool> _vieillissement;

public:

	/**
	 * @class DeleguationVue
	 * @brief DeleguationVue du Presentateur du Jeu Grenouilloland.
	 *
	 * Declaration de la classe DeleguationVue de la classe Presentateur
	 * communiquant avec la classe VueGrenouille amie.
	 */
	class DeleguationVue
	{

		public :

			friend class VueGrenouille;

		private :

			static void lancerPartie(Presentateur& presentateur)
			{
				presentateur.lancerPartie();
			}

			static void nouveauModele(Presentateur& presentateur, const int& dimension)
			{
				presentateur.nouveauModele(dimension);
			}
	};

	/**
	 * @class DeleguationCaseGraphique
	 * @brief DeleguationCaseGraphique du Presentateur du Jeu Grenouilloland.
	 *
	 * Declaration de la classe DeleguationCaseGraphique de la classe Presentateur
	 * communiquant avec la classe CaseGraphique amie.
	 */
	class DeleguationCaseGraphique
	{

		public :

			friend class CaseGraphique;

		private :

			static bool deplacerGrenouille(Presentateur& presentateur, const int& ligne, const int& colonne)
			{
				return presentateur.deplacerGrenouille(ligne, colonne);
			}
	};

};
}

#endif
