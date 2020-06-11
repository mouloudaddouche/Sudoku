#ifndef __LISTECIRCU_H
#define __LISTECIRCU_H

//Declaration
typedef struct element_liste elt;

//Strecure d'un element de la liste circulaire
struct element_liste{
	int val;
	elt* suiv;
};

//Les Fonctions

//Fonction qui permet de vérifie si une valeur existe dans la liste Circulaire
int ExisteDansLaListe(elt* l,int val);

//Fonction qui permet de retourner une liste trié a partir d'une liste circulairement trié passé en parametre
elt* MinListe(elt *l);

//Fonction qui permet d'ajouter un element dans la liste circulaire
elt* AjouterElementListe(elt* l, int val);

//Fonction qui permet de cree un element de type liste dans la valeur est donné dans les paramétres	
elt* CreeElement(int val);

//Fonction qui permet de copier une liste circulaire dans une autre liste circulaire
elt* CopieListe(elt* tete_l1);

//Cette fonction permet de supprimer une valeur d'une liste circulaire
elt* SupprimerDeLaListe(elt* l,int val);

//Cette fonction retourne la valeur maximale de la liste circulaire
int MaxListe(elt* l);

//Cette Fonction permet de retourner l'element suivant de l'element qui a comme valeur la valeur donné e
elt* ElementSuiv(elt* l,int val);

#endif
