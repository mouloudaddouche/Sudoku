
//Strecure d'un element de la liste simple
typedef struct _list
{
    int i, j;
    int nbValeursPossibles;
    struct _list *next;
} ListeSimple;

//Les Fonctions

//Fonction qui permet de retourner un nouvel élément initialisé
ListeSimple* Nouveau_Element(int i, int j, int n);

//Fonction qui permet de supprimer intégralement une liste chainée
void Supprimer_Une_Liste (ListeSimple** l);

//Fonction qui permet d'ajouter un element dans la tete de liste dont la valeur est donné en parametre
void Ajouter_Element_En_Tete_De_Liste (ListeSimple** list, int i, int j, int n);

//Fonction qui permet d'insére une element  dans une liste triée
void Insertion_Liste (ListeSimple** l, ListeSimple* elem);

//Tri insertion sur liste chainée
ListeSimple* Tri_Insertion_Liste (ListeSimple* l1);
