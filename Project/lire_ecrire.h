#ifndef __LIRE_ECRIRE_H
#define __LIRE_ECRIRE_H

// Lire un sudoku a partir d'un fichier .txt
SUDOKU lire_fichier (char *nom);


// Ecriture d'un sudoku dans un fichier
void ecrire_fichier(SUDOKU S,char* nom,int TypePartie);

#endif
