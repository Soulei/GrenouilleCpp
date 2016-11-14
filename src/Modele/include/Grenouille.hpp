#ifndef Grenouille_hpp
#define Grenouille_hpp

namespace grenouilloland {

/**
 * @class Grenouille Grenouille.hpp
 * @brief Grenouille du Jeu Grenouilloland.
 *
 * Declaration de la classe Grenouille réprésentant la grenouille du jeu Grenouilloland.
 */
class Grenouille
{		
	public :
		/**
		 * Constructeur logique de la grenouille.
		 *
		 * @param[in] x - position de la grenouille sur l'axe x.
		 * @param[in] y - position de la grenouille sur l'axe y.
		 */
		Grenouille(const unsigned int& x, const unsigned int& y);		

		/**
		 * Accesseur du nombre de pv de la grenouille.
		 *
		 * @return la valeur de @ref _pv.
		 */
		const unsigned int& getPv() const;
		
		/**
		 * Accesseur de l'état de santé de la grenouille.
		 *
		 * @return la valeur de @ref _malade.
		 */
		const bool& getMalade() const;
		
		/**
		 * Accesseur de la position de la grenouille sur l'axe x.
		 *
		 * @return la valeur de @ref _x.
		 */
		const unsigned int& getX() const;
		
		/**
		 * Accesseur de la position de la grenouille sur l'axe y.
		 *
		 * @return la valeur de @ref _y.
		 */
		const unsigned int& getY() const;
		
	private :

		/**
		 * Réinitialisation de la grenouille.
		 *
		 * @param[in] n - taille du plateau de dimension n*n.
		 */
		void reinitialiser(const int& n);

		/**
		 * Modifie le nombre de pv de la grenouille.
		 *
		 * @param[in] pv - nouveau nombre de pv de la grenouille.
		 *
		 * @return la valeur de @ref _pv.
		 */	
		unsigned int setPv(const unsigned int& pv);
		
		/**
		 * Modifie l'état de santé de la grenouille.
		 *
		 * @param[in] malade - nouvel état de santé de la grenouille.
		 *
		 * @return la valeur de @ref _malade.
		 */
		bool setMalade(const bool& malade);
		
		/**
		 * Modifie la position de la grenouille sur l'axe x.
		 *
		 * @param[in] x - nouvelle position de la grenouille sur l'axe x.
		 *
		 * @return la valeur de @ref _x.
		 */
		unsigned int setX(const unsigned int& x);
		
		/**
		 * Modifie la position de la grenouille sur l'axe y.
		 *
		 * @param[in] y - nouvelle position de la grenouille sur l'axe y.
		 *
		 * @return la valeur de @ref _y.
		 */
		unsigned int setY(const unsigned int& y);

	protected :
		/**
		 * Nombre de pv de la grenouille.
		 */
		unsigned int _pv;
		
		/**
		 * Etat de santé de la grenouille.
		 */
		bool _malade;
		
		/**
		 * Position de la grenouille sur l'axe x.
		 */
		unsigned int _x;
		
		/**
		 * Position de la grenouille sur l'axe y.
		 */
		unsigned int _y;
				
	public :
		/**
		 * @class DeleguationEtat
		 * @brief DeleguationEtat de Grenouille du Jeu Grenouilloland.
		 *
		 * Declaration de la classe DeleguationEtat de la classe Grenouille communiquant avec la classe StrategieAbstraite.
		 */
		class DeleguationEtat
		{
			public :
				friend class StrategieAbstraite;
				
			private :
				/**
				 * Modifie le nombre de pv d'une grenouille.
				 *
				 * @param[in] g - la grenouille qui sera modifiée.
				 * @param[in] pv - nouvelle valeur des pv de la grenouille.
				 *
				 * @return la valeur des pv de la grenouille.
				 */				
				static unsigned int setPv(Grenouille& g, const unsigned int& pv)
				{
					return g.setPv(pv);
				}
				
				/**
				 * Modifie l'état de santé d'une grenouille.
				 *
				 * @param[in] g - la grenouille qui sera modifiée.
				 * @param[in] malade - nouvel état de santé de la grenouille.
				 *
				 * @return l'état de santé de la grenouille.
				 */
				static bool setMalade(Grenouille& g, const bool& malade)
				{
					return g.setMalade(malade);
				}	
		};

		/**
		 * @class DeleguationPosition
		 * @brief DeleguationPosition de Grenouille du Jeu Grenouilloland.
		 *
		 * Declaration de la classe DeleguationPosition de la classe Grenouille communiquant avec la classe Jeu.
		 */		
		class DeleguationPosition
		{
			public :
				friend class Jeu;
				
			private :
				
				/**
		 		* Réinitialisation de la grenouille.
		 		*
		 		* @param[in] n - taille du plateau de dimension n*n.
		 		*/
				static void reinitialiser(Grenouille& g, const int& n) {
					g.reinitialiser(n);
				}

				/**
				 * Modifie la position de la grenouille sur l'axe x.
				 *
				 * @param[in] g - la grenouille qui sera modifiée.
				 * @param[in] x - nouvelle position de la grenouille sur l'axe.
				 *
				 * @return la position de la grenouille sur l'axe x.
				 */
				static unsigned int setX(Grenouille& g, const unsigned int& x)
				{
					return g.setX(x);
				}

				/**
				 * Modifie la position de la grenouille sur l'axe y.
				 *
				 * @param[in] g - la grenouille qui sera modifiée.
				 * @param[in] y - nouvelle position de la grenouille sur l'axe.
				 *
				 * @return la position de la grenouille sur l'axe y.
				 */				
				static unsigned int setY(Grenouille& g, const unsigned int& y)
				{
					return g.setY(y);
				}
		};
};

}

#endif
