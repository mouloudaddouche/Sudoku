#ifndef __SUDOKU_H
#define __SUDOKU_H

//Declaration des types

typedef struct _list ListeSimple;
typedef struct element_liste elt;

//strecture d'un element du SUDOKU
struct element_sudoku{
	int dt;
	int val;
	elt* valpos;


};
typedef struct element_sudoku eltsdk;

//La strecture SUDOKU
struct sudoku {
	eltsdk sdk [9][9];

};
typedef struct sudoku SUDOKU;


//Strecture Pile SUDOKU
typedef struct PileSudoku eltpile;

struct PileSudoku{
	SUDOKU val;
	eltpile* suiv;
	
};

//Les Fonctions

//Fonction qui permet de génére une liste contenant les valeurs de [0-9]
elt* Listes_Valeurs_Possibles(elt* l,int k);

//Fonction qui permet d'initialiser tout les cases du sudoku par 0 ( le champ valeur )
void Initialiser_Sudoku(SUDOKU *S);

//Cette fonction sera appellé aprés la lecture d'un sudoku a partir d'un fichier pour généré une liste des valeurs possibles provisoir
SUDOKU Sudoku_Valeurs_Possibles(SUDOKU S);

//Fonction qui permet de supprimer tout les valeurs possibles pour chaque case du sudoku
SUDOKU Supprimer_Valeurs_Possibles(SUDOKU S);

void Sudoku_Pret(SUDOKU *S);

//Cette fonction permet de sauvgarder les cordonnés des cases vides pour les afficher par une couleur differente lors de l'affichage de la solution
int** Sauvgarder_Cases_Vides(SUDOKU S);

//Fonction qui permet d'actualiser le sudoku de depart ( les valeurs possibles pour chaque cases... )
SUDOKU Actualiser_Sudoku_Depart(SUDOKU S);

//Fonction qui verifie si on peut ajouter une valeur dans une case ( par rapport a la ligne , colonne et le box )
int Possible_Dajouter(SUDOKU S,int val,int l,int c);

//Fonction qui permet de copier le sudoku actuel dans un autre sudoku
SUDOKU Copier_Sudoku(SUDOKU S);

//Fonction qui permet d'empiler le sudoku actuel dans la pile sudoku
eltpile* Do(eltpile *PS,SUDOKU S);

//Fonction qui permet de recuperer l'etat precedante du sudoku ( avant la derniere modification )
eltpile* Undo(eltpile* PS);

//Fonction qui permet de verifier si le jeu est terminé
int Sudoku_Termine(SUDOKU S);

//Fonction qui permet de definir la bonne valeur pour une case ( utilisé dans la resolution du sudoku )
int Est_Valide (SUDOKU *S, ListeSimple* position);

// Calcule le nombre de valeurs possibles pour une case vide ( utilisé dans la resolution su sudoku )
int Nb_Possibles (SUDOKU S, int i, int j);

//Fonction qui permet de resoudre un sudoku
int Resolution_Sudoku (SUDOKU *S);

//Fonction qui permet de modifier une case ( jouer )
SUDOKU Modifier_Case(SUDOKU S,int ligne,int colonne);

//Fonction qui permet d'actualiser le sudoku acutel
SUDOKU Actualiser_Sudoku(SUDOKU S,int val,int l,int c,int SA);

#endif
