#include "gestion_sudoku.h"

#ifndef __AFFICHER_H
#define __AFFICHER_H

//Fonction a appeler au début poour créer la fenêtre grapĥique
void initialiser_fenetre_graphique();

//Affichage de l'interface Menu Principale
void Afficher_Menu_Principale();

//Fonction qui permet de recuperer le choix de l'utilisateur dans l'interface Menu Principale
int Choix_Menu_Principale(POINT P);

//Affichage de l'interface Choix De Difficulté
void Afficher_Menu_Difficulte();

//Fonction qui permet de recuperer le choix de l'utilisateur dans l'interface Difficulté
int Choix_Difficulte(POINT P);

//Affichage de l'interface Aide
void Afficher_Aide();

//Fonction qui permet de recuperer le choix de l'utilisateur dans l'interface Aide
int Choix_Aide(POINT P);

//Affichage du message pas de solution
void Sudoku_Pas_De_Solution();

//Affichage de l'interface defaite	
void Affichage_Defaite();

//Fonction qui permet de recuperer le choix de l'utilisateur dans l'interface Defaite
int Choix_Defaite(POINT P);

//Affichage de l'interface gagné
void Affichage_Gagne();

//Fonction qui permet de recuperer le choix de l'utilisateur dans l'interface Gagné
int Choix_Gagne(POINT P);

//Affichage qui suit l'affichage de la resolution de sudoku
void Affichage_Apres_Solution();

//Fonction qui permet de recuperer le choix de l'utilisateur dans l'interface Apres Solution
int Choix_Apres_Solution(POINT P);

//Fonction qui permettre d'afficher la liste des valeurs possibles pour une case donné
void Afficher_Valeurs_Possibles(SUDOKU S,int i,int j,POINT P1);

// Fonction qui affiche l'état courant du sudoku                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
void Sudoku_Afficher(SUDOKU S,char* titre,int choix,int** mat);


#endif
