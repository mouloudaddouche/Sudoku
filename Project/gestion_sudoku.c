#include <stdlib.h>
#include <stdio.h>
#include "gestion_sudoku.h"
#include "listecircu.h"
#include "liste.h"
#include "sudoku.h"
#include "generateur_sudoku.h"


//Fonction qui permet de génére une liste contenant les valeurs de [0-9]
elt* Listes_Valeurs_Possibles(elt* l,int k){
	elt *tetetemp;
	l=malloc(sizeof(elt));
    l->val=0;
    l->suiv=NULL;
	tetetemp=l;
	for (int i=1;i<=k;i++){
		elt *temp;
		temp=malloc(sizeof(elt));
		temp->val=i;
		tetetemp->suiv=temp;
		tetetemp=temp;
	}
	tetetemp->suiv=l;
	return(l);
}

//Fonction qui permet d'initialiser tout les cases du sudoku par 0 ( le champ valeur )
void Initialiser_Sudoku(SUDOKU *S){
	for(int i=0;i<9;i++){				 
		for (int j=0;j<9;j++){
			S->sdk[i][j].val=0;
			}
		}
}

//Cette fonction sera appellé aprés la lecture d'un sudoku a partir d'un fichier pour généré une liste des valeurs possibles provisoir
SUDOKU Sudoku_Valeurs_Possibles(SUDOKU S){ 
	for(int i=0;i<9;i++){				 
		for (int j=0;j<9;j++){
			if(S.sdk[i][j].dt==0)
			S.sdk[i][j].valpos=Listes_Valeurs_Possibles(NULL,9);
			else
			S.sdk[i][j].valpos=NULL;
		}
	}
	return(S);
} 


//Fonction qui permet de supprimer tout les valeurs possibles pour chaque case du sudoku
SUDOKU Supprimer_Valeurs_Possibles(SUDOKU S){
	for(int i=0;i<9;i++){			
		for (int j=0;j<9;j++){
			S.sdk[i][j].valpos=NULL;
			}
		}
		return S;
	}
	
	
void Sudoku_Pret(SUDOKU *S){
		 for(int i=0;i<9;i++){				 
		   for (int j=0;j<9;j++){
			  if(S->sdk[i][j].val==0) S->sdk[i][j].dt=0;
			  else S->sdk[i][j].dt=1;}
			}
		}
  
//Cette fonction permet de sauvgarder les cordonnés des cases vides pour les afficher par une couleur differente lors de l'affichage de la solution
int** Sauvgarder_Cases_Vides(SUDOKU S){
	int** mat;
	
	//Allocation dynamique de la matrice
	mat=malloc(9*sizeof(int*));
	for(int i=0;i<9;i++){
		mat[i]=malloc(9*sizeof(int));
	}
	
	//Initialisation de la matrice
	for(int i=0;i<9;i++){				
		for (int j=0;j<9;j++){
			mat[i][j]=0;
				}
			}
	//Sauvgarder les cases vides
	for(int i=0;i<9;i++){				
		for (int j=0;j<9;j++){
			if(S.sdk[i][j].val==0)
			mat[i][j]=1;
			}
		}
		
	return mat;
}

//Fonction qui permet d'actualiser le sudoku de depart ( les valeurs possibles pour chaque cases... )
SUDOKU Actualiser_Sudoku_Depart(SUDOKU S){
	for(int i=0;i<9;i++){				
		for (int j=0;j<9;j++){
		    S=Actualiser_Sudoku(S,S.sdk[i][j].val,i,j,0);
					}
				}
	for(int i=0;i<9;i++){				
		for (int j=0;j<9;j++){
				if (S.sdk[i][j].valpos!=NULL)
		         S.sdk[i][j].valpos=ElementSuiv( S.sdk[i][j].valpos,S.sdk[i][j].val);
				}
	 }
   return S;
}

//Fonction qui verifie si on peut ajouter une valeur dans une case ( par rapport a la ligne , colonne et le box )
int Possible_Dajouter(SUDOKU S,int val,int l,int c){
	for (int i=0;i<9;i++){
		if (S.sdk[i][c].val==val) return 0;
		}
	
	for (int j=0;j<9;j++){
	if (S.sdk[l][j].val==val) return 0;
	    }
	
	switch(l/3){
		case 0:
			switch (c/3){
				case 0:
					for(int i=0;i<3;i++){
						for(int j=0;j<3;j++){
									   if (S.sdk[i][j].val==val) return 0;
		
											}
										}
					break;

				case 1:
					for(int i=0;i<3;i++){
						for(int j=3;j<6;j++){
									 if (S.sdk[i][j].val==val) return 0;
		
											}
										}
					break;
					
				case 2:
					for(int i=0;i<3;i++){
						for(int j=6;j<9;j++){
									 if (S.sdk[i][j].val==val) return 0;
		
											}
										}
					break;
			}
		break;
		
		case 1:
			switch (c/3){
				case 0:
					for(int i=3;i<6;i++){
						for(int j=0;j<3;j++){
									 if (S.sdk[i][j].val==val) return 0;
						}
					}
					break;
				
				case 1:
					for(int i=3;i<6;i++){
						for(int j=3;j<6;j++){
									 if (S.sdk[i][j].val==val) return 0;
						}
					}
					break;
				
				case 2:
					for(int i=3;i<6;i++){
						for(int j=6;j<9;j++){
									 if (S.sdk[i][j].val==val) return 0;
						}
					}
					break;
			}
		break;
		
		case 2:
			switch (c/3){
				case 0:
					for(int i=6;i<9;i++){
						for(int j=0;j<3;j++){
							 if (S.sdk[i][j].val==val) return 0;					
						}
					}
					break;

				case 1:
					for(int i=6;i<9;i++){
						for(int j=3;j<6;j++){
							 if (S.sdk[i][j].val==val) return 0;
										
						}
					}
					break;
				
				case 2:
					for(int i=6;i<9;i++){
						for(int j=6;j<9;j++){
							 if (S.sdk[i][j].val==val) return 0;
										
						}
					}
					break;
			}
		break;
	}
	return 1;
}

//Fonction qui permet d'empiler le sudoku actuel dans la pile sudoku
eltpile* Do(eltpile *PS,SUDOKU S){
	if (PS==NULL){
		PS=malloc(sizeof(eltpile));
		PS->val=S;
		PS->suiv=NULL;
		
	}
	else{
	eltpile *temp;
	temp=malloc(sizeof(eltpile));
	temp->val=S;
	temp->suiv=PS;
	PS=temp;
	}
	return PS;
}


//Fonction qui permet de recuperer l'etat precedante du sudoku ( avant la derniere modification )
eltpile* Undo(eltpile* PS){
	if (PS->suiv != NULL){
		eltpile* temp2;
		temp2=PS;
		PS=PS->suiv;
		free(temp2);
		return PS;
	}
  else return PS;	
}

//Fonction qui permet de verifier si le jeu est terminé
int Sudoku_Termine(SUDOKU S){
	int i,j;
	i=0;
	j=0;
	  while(i<9){
		  while (j<9){
					if (S.sdk[i][j].val==0)
						return 0;
					else j++;
							}
				j=0;
				i++;
					 }						
	return 1;
}

//Fonction qui permet de definir la bonne valeur pour une case ( utilisé dans la resolution du sudoku )
int Est_Valide (SUDOKU *S, ListeSimple* position){
    if (position == NULL)
        return 1;

    int i = position->i, j = position->j;
    for (int k=0; k < 9; k++) {
        // Vérifie dans les tableaux si la valeur est déjà présente
        if ( !ESL[i][k] && !ESC[j][k] && !ESB[3*(i/3)+(j/3)][k] )
        {
            // Ajoute k aux valeurs enregistrées
            ESL[i][k] = ESC[j][k] = ESB[3*(i/3)+(j/3)][k] = 1;

            if ( Est_Valide(S, position->next) )
            {
                // Ecrit le choix valide dans la grille
                S->sdk[i][j].val = k+1;
                return 1;
            }
            // Supprime k des valeurs enregistrées
           ESL[i][k] = ESC[j][k] = ESB[3*(i/3)+(j/3)][k] = 0;
        }
    }

    return 0;
}

// Calcule le nombre de valeurs possibles pour une case vide ( utilisé dans la resolution su sudoku )
int Nb_Possibles (SUDOKU S, int i, int j){
    int ret = 0;
    for (int k=0; k < 9; k++)
        if ( !ESL[i][k] && !ESC[j][k] && !ESB[3*(i/3)+(j/3)][k] )
            ret++;
    return ret;
}

//Fonction qui permet de resoudre un sudoku
int Resolution_Sudoku (SUDOKU *S){
    // Initialise les tableaux
    for (int i=0; i < 9; i++)
        for (int j=0; j < 9; j++)
           ESL[i][j] = ESC[i][j] = ESB[i][j] = 0;

   // Enregistre dans les tableaux toutes les valeurs déjà présentes 
    int k;
    for (int i=0; i < 9; i++)
        for (int j=0; j < 9; j++)
            if ( (k = S->sdk[i][j].val) != 0)
               ESL[i][k-1] = ESC[j][k-1] = ESB[3*(i/3)+(j/3)][k-1] = 1;

    // crée et remplit une liste pour les cases vides à visiter
    ListeSimple* positions = NULL;
    for (int i=0; i < 9; i++)
        for (int j=0; j < 9; j++)
            if ( S->sdk[i][j].val == 0 )
                Ajouter_Element_En_Tete_De_Liste ( &positions, i, j, Nb_Possibles(*S, i, j) );

    // Trie la liste (ordre croissant)
    positions = Tri_Insertion_Liste (positions);

    // Appelle la fonction de backtracking récursive estValide()
    int ret = Est_Valide (S, positions);
    
    // Détruit la liste
    Supprimer_Une_Liste (&positions);
    // retourne le resultat
    
    return ret;
}

//Fonction qui permet de modifier une case ( jouer )
SUDOKU Modifier_Case(SUDOKU S,int ligne,int colonne){
	if ((ligne >=0 && ligne <9) && ( colonne >=0 && colonne <9)){
			if(S.sdk[ligne][colonne].dt==0){
			int temp;
			temp=S.sdk[ligne][colonne].val;
			S.sdk[ligne][colonne].valpos=ElementSuiv(S.sdk[ligne][colonne].valpos,S.sdk[ligne][colonne].val);
			S.sdk[ligne][colonne].val= S.sdk[ligne][colonne].valpos->val;
			if (temp != 0) S=Actualiser_Sudoku(S,temp,ligne,colonne,1);
			if (S.sdk[ligne][colonne].val !=0 ) S=Actualiser_Sudoku(S,S.sdk[ligne][colonne].val,ligne,colonne,0);
			}
		}	
	return(S);	
}

//Fonction qui permet d'actualiser le sudoku acutel
SUDOKU Actualiser_Sudoku(SUDOKU S,int val,int l,int c,int SA){
	for (int i=0;i<9;i++){
		if (SA==0)
		S.sdk[i][c].valpos=SupprimerDeLaListe(S.sdk[i][c].valpos,val);
		else{
			if (Possible_Dajouter(S,val,i,c)==1)
			S.sdk[i][c].valpos=AjouterElementListe(S.sdk[i][c].valpos,val);
		}
	}
	for (int j=0;j<9;j++){
		if (SA==0)
		S.sdk[l][j].valpos=SupprimerDeLaListe(S.sdk[l][j].valpos,val);
		else{
		if (Possible_Dajouter(S,val,l,j)==1)
			S.sdk[l][j].valpos=AjouterElementListe(S.sdk[l][j].valpos,val);
		}
	}
	switch(l/3){
		case 0:
			switch (c/3){
				case 0:
					for(int i=0;i<3;i++){
						for(int j=0;j<3;j++){
									if (SA==0)
									S.sdk[i][j].valpos=SupprimerDeLaListe(S.sdk[i][j].valpos,val);
												
									else{
									if (Possible_Dajouter(S,val,i,j)==1)
									S.sdk[i][j].valpos=AjouterElementListe(S.sdk[i][j].valpos,val);		}   
		
											}
										}
					break;

				case 1:
					for(int i=0;i<3;i++){
						for(int j=3;j<6;j++){
									if (SA==0)
									S.sdk[i][j].valpos=SupprimerDeLaListe(S.sdk[i][j].valpos,val);											
									else{
									if (Possible_Dajouter(S,val,i,j)==1)
									S.sdk[i][j].valpos=AjouterElementListe(S.sdk[i][j].valpos,val);		}  
		
											}
										}
					break;
					
				case 2:
					for(int i=0;i<3;i++){
						for(int j=6;j<9;j++){
									if (SA==0)
									S.sdk[i][j].valpos=SupprimerDeLaListe(S.sdk[i][j].valpos,val);												
									else{
									if (Possible_Dajouter(S,val,i,j)==1)
									S.sdk[i][j].valpos=AjouterElementListe(S.sdk[i][j].valpos,val);		}  
		
											}
										}
					break;
			}
		break;
		
		case 1:
			switch (c/3){
				case 0:
					for(int i=3;i<6;i++){
						for(int j=0;j<3;j++){
									if (SA==0)
									S.sdk[i][j].valpos=SupprimerDeLaListe(S.sdk[i][j].valpos,val); 
								else{
									if (Possible_Dajouter(S,val,i,j)==1)
									S.sdk[i][j].valpos=AjouterElementListe(S.sdk[i][j].valpos,val);		}  
						}
					}
					break;
				
				case 1:
					for(int i=3;i<6;i++){
						for(int j=3;j<6;j++){
									if (SA==0)
									S.sdk[i][j].valpos=SupprimerDeLaListe(S.sdk[i][j].valpos,val); 
									else{
									if (Possible_Dajouter(S,val,i,j)==1)
									S.sdk[i][j].valpos=AjouterElementListe(S.sdk[i][j].valpos,val);		}  
						}
					}
					break;
				
				case 2:
					for(int i=3;i<6;i++){
						for(int j=6;j<9;j++){
									if (SA==0)
									S.sdk[i][j].valpos=SupprimerDeLaListe(S.sdk[i][j].valpos,val); 
									else{
									if (Possible_Dajouter(S,val,i,j)==1)
									S.sdk[i][j].valpos=AjouterElementListe(S.sdk[i][j].valpos,val);		}  
						}
					}
					break;
			}
		break;
		
		case 2:
			switch (c/3){
				case 0:
					for(int i=6;i<9;i++){
						for(int j=0;j<3;j++){
							if (SA==0)
									S.sdk[i][j].valpos=SupprimerDeLaListe(S.sdk[i][j].valpos,val);
									else{
									if (Possible_Dajouter(S,val,i,j)==1)
									S.sdk[i][j].valpos=AjouterElementListe(S.sdk[i][j].valpos,val);		}  							
						}
					}
					break;

				case 1:
					for(int i=6;i<9;i++){
						for(int j=3;j<6;j++){
							if (SA==0)
									S.sdk[i][j].valpos=SupprimerDeLaListe(S.sdk[i][j].valpos,val);
									else{
									if (Possible_Dajouter(S,val,i,j)==1)
									S.sdk[i][j].valpos=AjouterElementListe(S.sdk[i][j].valpos,val);		}        
										
						}
					}
					break;
				
				case 2:
					for(int i=6;i<9;i++){
						for(int j=6;j<9;j++){
							if (SA==0)
									S.sdk[i][j].valpos=SupprimerDeLaListe(S.sdk[i][j].valpos,val);
									else{
									if (Possible_Dajouter(S,val,i,j)==1)
									S.sdk[i][j].valpos=AjouterElementListe(S.sdk[i][j].valpos,val);		}  
										
						}
					}
					break;
			}
		break;
	}
	return S;
}
