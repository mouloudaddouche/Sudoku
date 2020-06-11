#include <stdlib.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "afficher.h"
#include "gestion_sudoku.h"
#include "lire_ecrire.h"
#include "gestion_sudoku.h"
#include "listecircu.h"
#include "generateur_sudoku.h"
#include <time.h>

#define EST_TOUCHE 2
#define EST_CLIC 3

////////////////// Varibles Globales Utilisé Dans La Résolution //////////////////
int ESL[9][9];
int ESC[9][9];
int ESB[9][9];

//Cette fonction permet de jouer au Sudoku
SUDOKU jouer(SUDOKU S,char* nom,POINT *P) {
		int ligne;
		int colonne;
		ligne=8-((P->y-30)/94);
		colonne=P->x/94;
		S=Modifier_Case(S,ligne,colonne);
return S;
}

int main (int argc, char *argv[]) {
	//Les Declarations
	
	eltpile* PS; // La pile du sudoku
    SUDOKU S; // Le Sudoku
    
    //Les arguments de la fonction wait_key_arrow_clic
    
	char* touche=NULL;
	int* fleche=NULL;
	POINT* P=NULL;
	touche=(char*)malloc(sizeof(char));
	fleche=(int*)malloc(sizeof(int));
	P=(POINT*)malloc(sizeof(POINT));
	
    srand(time(NULL)); // Pour Les Nombres Aléatoires
    initialiser_fenetre_graphique(); // Inistialiser la fenetre graphique 
    
		int choix=0; // Variable permet de savoir si l'utilisateur a appuyé sur la souris ou sur le clavier
		int fermer=0;// Varibale Qui permet de savoir si l'utilisateur demande la fermeture du programme
		POINT P2;
		
	etiq1 : do{
			Afficher_Menu_Principale();
			P2=wait_clic();
			choix=Choix_Menu_Principale(P2);
			}while (choix==0);
		
		switch(choix){
			
			//Nouvelle Partie
			case 1: {
				int ChoixDifficult;
				do{
				Afficher_Menu_Difficulte();
				P2=wait_clic();
				ChoixDifficult=Choix_Difficulte(P2);
			}while(ChoixDifficult==0);
			
				SUDOKU T;
				Initialiser_Sudoku(&T);
				
		switch(ChoixDifficult){
			//Choix De Difficulté
			  case 1:{	
					Generateur_Du_Sudoku(&T,1);
					ecrire_fichier(T,"exemple.sudoku.txt",1);	
					break;	
				}
				
			  case 2:{
					Generateur_Du_Sudoku(&T,2);
					ecrire_fichier(T,"exemple.sudoku.txt",1);	
					break;	
				}
				
			  case 3:{
					Generateur_Du_Sudoku(&T,3);
					ecrire_fichier(T,"exemple.sudoku.txt",1);	
				break;
					
				}
				
			  case 4 :{ goto etiq1; break;}
				
			}
			PS=NULL;
			S = lire_fichier("exemple.sudoku.txt");
			S=Sudoku_Valeurs_Possibles(S);
			S=Actualiser_Sudoku_Depart(S); 
			PS=Do(PS,S);
			Sudoku_Afficher(S,argv[1],0,NULL);
			
			while (fermer==0){
				
			 choix=wait_key_arrow_clic(touche,fleche,P);
		    
			  if (choix == EST_CLIC){
				 
				S=jouer(S,argv[1],P);
				PS=Do(PS,S);
				Sudoku_Afficher(S,argv[1],0,NULL);
				
				 if (Sudoku_Termine(S)){
					 
					do{
					Affichage_Gagne();
					P2=wait_clic();
					choix=Choix_Gagne(P2);
					}while(choix==0);
					
					if (choix==1) goto etiq1;
					else fermer=1;
									 	
							}			
				}
				
		    else if (choix == EST_TOUCHE){ 
				//UNDO
				if (touche[0] =='U') { 
					PS=Undo(PS);
					S=PS->val;
					S=Sudoku_Valeurs_Possibles(S);
					S=Actualiser_Sudoku_Depart(S); 
					Sudoku_Afficher(S,argv[1],0,NULL);			  
						}
						
				//Resolution
				else if (touche[0] == 'V'){
					int** temp=Sauvgarder_Cases_Vides(S);
					int k=Resolution_Sudoku(&S);
				
				//Le Cas ou Le Sudoku Admet Une Solution
				if (k==1){
				    S=Supprimer_Valeurs_Possibles(S);
				    
			
			etiq2:	Sudoku_Afficher(S,argv[1],1,temp);
					attendre(7000);
					Affichage_Apres_Solution();
					do{
					P2=wait_clic();
					choix=Choix_Apres_Solution(P2);
					}while(choix==0);
					
					if (choix==1) goto etiq1;
					else if(choix==2) goto etiq2;
					else  fermer=1;
					  
				 }
				 //Le Cas ou Le Sudoku N'admet Pas De Solution
				else{
					do{
					Affichage_Defaite();
					P2=wait_clic();
					choix=Choix_Defaite(P2);
					}while (choix==0);
					
					if (choix ==1) goto etiq1;
					else fermer=1;
					}
			}
				//Sauvgarde Dans Un Fichier
				else if (touche[0] == 'S'){
				    ecrire_fichier(S,"exemple.sudoku.txt",2);	
						}
						
				//Quitter		
				else if (touche[0] == 'Q'){
					fermer=1;
					}	
			}
		}
			break;	
		}
		
		//Reprendre La Partie
		case 2:{
			PS=NULL;
			S = lire_fichier(argv[1]);
			S=Sudoku_Valeurs_Possibles(S);
			S=Actualiser_Sudoku_Depart(S); 
			PS=Do(PS,S);
			Sudoku_Afficher(S,argv[1],0,NULL);
			
		while (fermer==0){
			
		    choix=wait_key_arrow_clic(touche,fleche,P);
		    
		   if (choix == EST_CLIC){
				S=jouer(S,argv[1],P);
				PS=Do(PS,S);
				Sudoku_Afficher(S,argv[1],0,NULL);
				if (Sudoku_Termine(S)){
					
					do{
					Affichage_Gagne();
					P2=wait_clic();
					choix=Choix_Gagne(P2);
					}while(choix==0);
					
					if (choix==1) goto etiq1;
					else fermer=1; 	
								 }					 	
							}			
		
		  else if (choix == EST_TOUCHE){ 
			  
			 //UNDO
			 if (touche[0] =='U') { 
					PS=Undo(PS);
					S=PS->val;
					S=Sudoku_Valeurs_Possibles(S);
					S=Actualiser_Sudoku_Depart(S); 
					Sudoku_Afficher(S,argv[1],0,NULL);
						 }
				
		     //Resolution
		     else if (touche[0] == 'V'){
				int** temp=Sauvgarder_Cases_Vides(S);
				int k=Resolution_Sudoku(&S);
				
				//Le Cas ou Le Sudoku Admet Une Solution
				if (k==1){
				    S=Supprimer_Valeurs_Possibles(S);
			etiq3 : Sudoku_Afficher(S,argv[1],1,temp);
					attendre(7000);
					Affichage_Apres_Solution();
					do{
					P2=wait_clic();
					choix=Choix_Apres_Solution(P2);
					}while(choix==0);
					
					if (choix==1) goto etiq1;
					else if(choix==2) goto etiq3;
					else  fermer=1;
				 }
				 
				 //Le Cas ou Le Sudoku N'admet Pas De Solution
				else{
					do{
					Affichage_Defaite();
					P2=wait_clic();
					choix=Choix_Defaite(P2);
					}while (choix==0);
					
					if (choix ==1) goto etiq1;
					else break;
				}
			}
			
			 //Sauvgarde Dans Un Fichier
			 else if (touche[0] == 'S'){
			   ecrire_fichier(S,argv[1],2);	
				}
				
			 //Quitter
			 else if (touche[0] == 'Q'){
				fermer=1;
				}	
		   } 
		 }
			break;
		}
		
		//Aide
		case 3 : {
			int temp;
			do{Afficher_Aide(); 
			P2=wait_clic();
			temp=Choix_Aide(P2);
			}while(temp==0);
			
			goto etiq1;
			break;}
		
		//Quitter
		case 4: break;
  }
}
