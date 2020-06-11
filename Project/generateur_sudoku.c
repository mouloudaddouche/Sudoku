#include <stdlib.h>
#include <math.h>
#include "generateur_sudoku.h"
#include <time.h>

//Fonction Permet de verifier si une valeur existe dans un box ou pas ( box == carreau )
int Non_Utilise_En_Box(SUDOKU S, int LigneDebut, int ColonneDebut, int val){ 
        for (int i = 0; i<SRN; i++) 
            for (int j = 0; j<SRN; j++) 
                if (S.sdk[LigneDebut+i][ColonneDebut+j].val == val) 
                    return 0; 
  
   return 1; 
} 
    
//Fonction Permet de verifier si une valeur existe dans une ligne ou pas   
int Non_Utilise_En_Linge (SUDOKU S,int l,int val){ 
        for (int j = 0; j<N; j++) 
           if (S.sdk[l][j].val == val) 
                return 0; 
     return 1; 
} 
  
//Fonction Permet de verifier si une valeur existe dans une colonne ou pas  
int Non_Utilise_En_Colonne (SUDOKU S,int c,int val){ 
        for (int i = 0; i<N; i++) 
            if (S.sdk[i][c].val == val) 
                return 0; 
        return 1; 
} 

//Fonction qui permet de verifier si on peut ajouter une valeur
int Verifier_Ajout (SUDOKU S,int i,int j,int val){ 
        return (Non_Utilise_En_Linge(S,i, val) && 
                Non_Utilise_En_Colonne(S,j, val) && 
                Non_Utilise_En_Box(S,i-i%SRN, j-j%SRN, val)); 
} 


    
//Fonction qui permet de généré des nombres aleatoires
int Generateur_Aleatoire_Entier(int max) { 
	return (rand()%9 +1);
}


//Fonction qui permet de remplire un box ( un carré )
void Remplir_Le_Box(SUDOKU *S,int ligne,int colonne) { 
        int val=0;
        for (int i=0; i<SRN; i++) { 
            for (int j=0; j<SRN; j++) { 
                do{ 
                    val=Generateur_Aleatoire_Entier(N);
                } 
                while (!Non_Utilise_En_Box(*S,ligne, colonne, val)); 
                
                S->sdk[ligne+i][colonne+j].val = val; 
            
					} 
			} 
    } 

//Fonction qui permet de remplire les box de la diagonale
void Remplir_La_Diagonale(SUDOKU *S) { 
	for (int i = 0; i<N; i=i+SRN){
        Remplir_Le_Box(S,i,i);}
    } 


//Fonction qui permet de remplire les cases vides restantes    
 int Remplir_Les_Cases_Restantes(SUDOKU *S,int l, int c) { 
        if (c>=N && l<N-1) 
        { 
            l = l + 1; 
            c = 0; 
        } 
        if (l>=N && c>=N) 
            return 1; 
  
        if (l < SRN) 
        { 
            if (c < SRN) 
                c = SRN; 
        } 
        else if (l < N-SRN) 
        { 
            if (c==(int)(l/SRN)*SRN) 
                c =  c + SRN; 
        } 
        else
        { 
            if (c == N-SRN) 
            { 
                l = l + 1; 
                c = 0; 
                if (l>=N) 
                    return 1; 
            } 
        } 
  
        for (int num = 1; num<=N; num++) 
        { 
            if (Verifier_Ajout(*S,l, c, num)) 
            { 
                S->sdk[l][c].val = num; 
                if (Remplir_Les_Cases_Restantes(S,l, c+1)) 
                    return 1; 
  
                S->sdk[l][c].val=0; 
            } 
        } 
        return 0; 
    } 
 
   
    
//Fonction qui permet de supprimer K elements de la grille 
void Supprimer_Element_Du_Sudoku(SUDOKU *S,int difficulte) { 
	int cmpt;
	switch (difficulte){
		case 1 : cmpt=60; break;
		case 2:  cmpt=67;  break;
		case 3:  cmpt=74;  break;
					   }
		
        while (cmpt != 0) 
        { 
            int ligne = Generateur_Aleatoire_Entier(N)-1;
            int colonne = Generateur_Aleatoire_Entier(N)-1;  
            if (S->sdk[ligne][colonne].val != 0) { 
                cmpt--; 
                S->sdk[ligne][colonne].val = 0; 
			} 
        } 
   } 
    
//Fonction qui permet de généré des sudoku
void Generateur_Du_Sudoku(SUDOKU *S, int difficulte){
		 
        // Remplire La Diagonale 
       Remplir_La_Diagonale(S); 
  
        // Remplir Les Cases Restantes
         Remplir_Les_Cases_Restantes(S,0,SRN); 
  
         //Supprimer K elements du Sudoku
        Supprimer_Element_Du_Sudoku(S,difficulte); 
  } 
    
   
