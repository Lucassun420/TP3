
#include "ocean.h"
#include "Liste.h"
//#include "ocean.h"


/******************************************************************************/
/*  POISSON.H                                                                 */
/*  Module utilitaire qui permet de maintenir la liste des poissons vivants   */
/*  Conception : Lucas Log�                                                   */
/******************************************************************************/
#if !defined (LIB_POISSON)
#define LIB_POISSON 1

#define MAX_POISSON 1000 //nombre maximal de poissons avant la surpopulation
#define MAX_AGE_POISSON 150 //�ge maximal du poisson
#define NB_JRS_PUB_POISSON 30 //nombre de jours avant la pubert�
#define NB_JRS_GEST_POISSON 15 //nombre de jours de gestation
#define ENERGIE_INIT_POISSON 3 //valeur initiale d'�nergie



/*
Re�oit la liste de poissons, l'ocean, nb de poissons voulu et g�n�re autant de poissons
que n�cessaire chacun dans une case VIDE
*/

void init_liste_p(t_liste* liste_p,t_ocean ocean, int nb_p_vlu);//ocean

/*
	D�place le poisson vers 1 case vide adjacente de l'oc�an
	Re�oit l'ocean & le pointeur du noeud du poisson concern� & modifie les donn�es px & py de celui-ci vers la nouvelle case
	Retourne 1 si l'op�ration foncitonne sinon retourne 0
*/

int deplace_poisson(t_noeud* poisson,t_ocean ocean);

/*
	Ajoute un nouveau b�b�-poisson � la liste dans une case vide de l'oc�an
	Re�oit la liste des poissons, l'oc�an et le pointeur attribu� au poisson-parent
*/
int ajout_bb_p(t_liste* liste,t_ocean ocean,t_noeud* p_parent);

/*
	Retire un poisson de la liste_poisson & vide sa case attribu�e de l'oc�an
*/
void retirer_poisson(t_liste* liste,t_ocean ocean);


/*
	Structure speciale pour transmettre les informations autour d'un poisson & la direction disponible choisie
*/
typedef struct {
	t_contenu case_adj[3][3];	//etat des cases autout d'une coordonnee de l'ocean
	int plein;					//indique si toutes les cases sont pleines(1) ou non(0)
	int bordx;					//indique si l'emplacement se trouve completement a gauche(1) ou a droite(2) ou normal(0)
	int bordy;					//indique si l'emplacement se trouve completement en haut(1) ou en bas(2) ou normal(0)
	t_direction dir_dispo;		//indique une direction disponible vide ou envoyer un element
	int n_y;					//indique le y de la nouvelle case
	int n_x;					//indique le x de la nouvelle case
}t_info_adj;

/*
	Fonction fourre-tout qui retourne une structure avec:
		le tableau de cases adj
		si toutes les cases sont pleines (int 1 ou 0)
		si on se trouve sur un des bords de l'ocean
		quelle direction a ete selectionnee comme nouvelle position
		les coordonnees de la nouvelle case
*/
t_info_adj* case_adj_vides(t_noeud* poisson, t_ocean ocean);


#endif