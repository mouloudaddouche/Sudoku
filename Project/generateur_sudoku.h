#include "gestion_sudoku.h" //Permet d'inclure la strecture Sudoku

#define N 9 
#define SRN 3

//Les Fonctions 

//Fonction Permet de verifier si une valeur existe dans un box ou pas ( box == carreau )
int Non_Utilise_En_Box(SUDOKU S, int LigneDebut, int ColonneDebut, int val);

//Fonction Permet de verifier si une valeur existe dans une ligne ou pas   
int Non_Utilise_En_Linge (SUDOKU S,int l,int val) ;

//Fonction Permet de verifier si une valeur existe dans une colonne ou pas 
int Non_Utilise_En_Colonne (SUDOKU S,int c,int val);

//Fonction qui permet de verifier si on peut ajouter une valeur
int Verifier_Ajout (SUDOKU S,int i,int j,int val);

//Fonction qui permet de généré des nombres aleatoires
int Generateur_Aleatoire_Entier(int max);

//Fonction qui permet de remplire un box ( un carré )
void Remplir_Le_Box(SUDOKU *S,int ligne,int colonne); 

//Fonction qui permet de remplire les box de la diagonale
void Remplir_La_Diagonale(SUDOKU *S);

//Fonction qui permet de remplire les cases vides restantes  
int Remplire_Les_Cases_Restantes(SUDOKU *S,int l, int c);

//Fonction qui permet de supprimer K elements de la grille 
void Supprimer_Element_Du_Sudoku(SUDOKU *S,int difficulte);

//Fonction qui permet de généré des sudoku
void Generateur_Du_Sudoku(SUDOKU *S, int difficulte);
