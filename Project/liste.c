#include <stdlib.h>
#include "liste.h"


//Fonction qui permet de retourner un nouvel élément initialisé
ListeSimple* Nouveau_Element(int i, int j, int n){
    ListeSimple* ret = malloc(sizeof* ret);
    if (ret != NULL)
        ret->i = i, ret->j = j, ret->nbValeursPossibles = n, ret->next = NULL;
    return ret;
}

//Fonction qui permet de supprimer intégralement une liste chainée
void Supprimer_Une_Liste (ListeSimple** l){
    ListeSimple* tmp;
    while ( (tmp = *l) != NULL){
        *l = (*l)->next;
        free(tmp);
	}
}

//Fonction qui permet d'ajouter un element dans la tete de liste dont la valeur est donné en parametre
void Ajouter_Element_En_Tete_De_Liste (ListeSimple** l, int i, int j, int n){
    ListeSimple* elem = Nouveau_Element (i, j, n);
    if (elem != NULL)
        elem->next = *l, *l = elem;
}

//Fonction qui permet d'insére une element  dans une liste triée
void Insertion_Liste (ListeSimple** l, ListeSimple* elem){
    if (*l == NULL){
        *l = elem;
        elem->next = NULL;
        }
        
    else if ((*l)->nbValeursPossibles < elem->nbValeursPossibles)
        Insertion_Liste (&(*l)->next, elem);
    else{
        elem->next = *l;
         *l = elem;
	 }
}

// tri insertion sur liste chainée
ListeSimple* Tri_Insertion_Liste (ListeSimple* l1){
    ListeSimple *curr, *l2 = NULL, *temp;
    for (curr = l1; curr != NULL; curr = temp)
    {
        temp = curr->next;
        Insertion_Liste (&l2, curr);
    }
    return l2;
}
