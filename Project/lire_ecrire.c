#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_sudoku.h"
#include "listecircu.h"

#define NOUVELLE_PARTIE 1
#define REPRENDRE_PARTIE 2

// Lire un sudoku a partir d'un fichier .txt
SUDOKU lire_fichier (char *nom) {
	SUDOKU S;
	FILE* F;
	F=fopen(nom,"r");
	if (F!=NULL){
	int caractereactuelle=0;

	for (int i=0;i<9;i++){
		for (int j=0;j<10;j++){ 
			caractereactuelle=fgetc(F);
			if (caractereactuelle!='\n'){
			if (caractereactuelle =='*' ){   
				S.sdk[i][j].dt=0;
				S.sdk[i][j].val=fgetc(F)-'0';
				S.sdk[i][j].valpos=malloc(sizeof(elt*));
				S.sdk[i][j].valpos->val=0;
				S.sdk[i][j].valpos->suiv=NULL;
				
			} 
			else if(caractereactuelle =='.') {  
				S.sdk[i][j].dt=0;
				S.sdk[i][j].val=0;
				S.sdk[i][j].valpos=malloc(sizeof(elt*));
				S.sdk[i][j].valpos->val=0;
				S.sdk[i][j].valpos->suiv=NULL;
				
				}
				
			else{	
				S.sdk[i][j].dt=1;
				S.sdk[i][j].val=caractereactuelle-'0';
				S.sdk[i][j].valpos=malloc(sizeof(elt*));
				S.sdk[i][j].valpos->val=0;
				S.sdk[i][j].valpos->suiv=NULL;
					
				}
				
						}
					}	
				}
				
		fclose(F);
		}
	return S;
}


// Ecriture du sudoku dans un fichier
void ecrire_fichier(SUDOKU S,char* nom,int TypePartie) {
	char *s;
	FILE* F;
	if (strcmp(nom,"exemple.sudoku.txt")==0){
		
		if(TypePartie == NOUVELLE_PARTIE) s="exemple.sudoku.txt";
		else s="exemple.001.sudoku.txt";
		
		//Ecriture dans le fichier
	F=fopen(s,"w");
	if (F!=NULL){
		if (TypePartie ==1){
			Sudoku_Pret(&S);
			}
			
		for (int i=0;i<9;i++){
		for (int j=0;j<9;j++){ 
			if(S.sdk[i][j].dt==0){
				if(S.sdk[i][j].val==0)
					fprintf(F,".");
				else{
					fprintf(F,"*");
					fprintf(F,"%d",S.sdk[i][j].val);
				}
			}
			else
			fprintf(F,"%d",S.sdk[i][j].val);
	   }
	fprintf(F,"\n");
   }
  }
	fclose(F);
  }
  
	//Le nom du fichier different de "exemple.sudoku.txt"
	else{
		char num[4];
		num[3]='\0';
		int j=0;
		for(int i=8;i<11;i++){ //Recuperer le numero depuis la chaine
			num[j]=nom[i];
			j++;	
		}
		int nb=atoi(num);
		
		if (nb>0 && nb<999) nb++;
		
		char nbm[4];
		nbm[3]='\0';
		j=2;
		
		//Recopier le numero apres l'incrémentation dans la chaine
		while (nb!=0){
			nbm[j]=nb%10+'0';
			nb=nb/10;
			j--;
		}
		while(j>=0){
			nbm[j]='0';
			j--;}
			
		//Composé le nom du fichier
		char s1[50];char s2[50];
		strcpy(s1,"exemple.");
		strcpy(s2,".sudoku.txt");
		strcat(s1,nbm);
		strcat(s1,s2);
		
		//Ecriture dans le fichier
		F=fopen(s1,"w");
		if (F!=NULL){
		for (int i=0;i<9;i++){
		  for (int j=0;j<9;j++){ 
			if(S.sdk[i][j].dt==0){
				if(S.sdk[i][j].val==0)
					fprintf(F,".");
				else{
					fprintf(F,"*");
					fprintf(F,"%d",S.sdk[i][j].val);
					}
			     }
			else
			fprintf(F,"%d",S.sdk[i][j].val);
	   }
	fprintf(F,"\n");
	 }
    }
	fclose(F);
   }
  }

