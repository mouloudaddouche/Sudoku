#include <stdio.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "gestion_sudoku.h"
#include "listecircu.h"

//Fonction qui permet d'initialisé la fenetre graphique
void initialiser_fenetre_graphique() {
	init_graphics(LARGEUR,HAUTEUR);
	affiche_auto_on();
}

//Affichage de l'interface Menu Principale
void Afficher_Menu_Principale(){
	COULEUR couleur;
	couleur= couleur_RGB(21,183,209);
	fill_screen(couleur);
	POINT P1,P2;
	P1.x=150;P1.y=810;
	couleur= couleur_RGB(255,33,5);
	char* s0="S U D O K U";
	aff_pol(s0, 90, P1, couleur);
	P1.x=100;P1.y=545;
	P2.x=750;P2.y=630;
	couleur= couleur_RGB(251,251,252);
	draw_fill_rectangle(P1,P2,couleur);
	P1.x=100;P1.y=425;
	P2.x=750;P2.y=510;
	draw_fill_rectangle(P1,P2,couleur);
	P1.x=100;P1.y=305;
	P2.x=750;P2.y=390;
	draw_fill_rectangle(P1,P2,couleur);
	P1.x=100;P1.y=185;
	P2.x=750;P2.y=270;
	draw_fill_rectangle(P1,P2,couleur);
	couleur= couleur_RGB(0,57,211);
	char *s1="1 - NOUVELLE PARTIE";
	char *s2="2 - REPRENDE LA PARTIE";
	char *s3="3 - AIDE";
	char *s4="4 - QUITTER";
	P1.x=150;P1.y=620;
	aff_pol(s1, 41, P1, couleur);
	P1.x=150;P1.y=498;
	aff_pol(s2, 41, P1, couleur);
	P1.x=150;P1.y=380;
	aff_pol(s3, 41, P1, couleur);
	P1.x=150;P1.y=260;
	aff_pol(s4, 41, P1, couleur);
}

//Fonction qui permet de recuperer le choix de l'utilisateur dans l'interface Menu Principale
int Choix_Menu_Principale(POINT P){
	if (P.x>=100 && P.x<=750){
		if (P.y>=545 && P.y<=630 ) return 1;
		if (P.y>=425 && P.y<=510 ) return 2;
		if (P.y>=305 && P.y<=390 ) return 3;
		if (P.y>=185 && P.y<=270 ) return 4;
		else return 0;
	}
	else return 0;
}

//Affichage de l'interface Choix De Difficulté
void Afficher_Menu_Difficulte(){
	COULEUR couleur;
	couleur= couleur_RGB(255,192,167);
	fill_screen(couleur);
	POINT P1,P2;
	P1.x=130;P1.y=855;
	pol_style(GRAS);
	pol_style(GRAS);
	couleur= couleur_RGB(209,80,68);
	char* s0="S U D O K U";
	aff_pol(s0, 95, P1, couleur);
	/////////////
	P1.x=179;P1.y=730;
	char* s5="CHOIX DE NIVEAU";
	aff_pol(s5, 53, P1, couleur);
	couleur= couleur_RGB(241,233,215);
	P1.x=100;P1.y=550;
	P2.x=750;P2.y=630;
	draw_fill_rectangle(P1,P2,couleur);
	P1.x=100;P1.y=420;
	P2.x=750;P2.y=500;
	draw_fill_rectangle(P1,P2,couleur);
	P1.x=100;P1.y=290;
	P2.x=750;P2.y=370;
	draw_fill_rectangle(P1,P2,couleur);
	char *s1="1 - FACILE";
	char *s2="2 - MOYEN";
	char *s3="3 - DIFFICLE";
	couleur= couleur_RGB(72,32,26);
	P1.x=160;P1.y=620;
	aff_pol(s1, 45, P1, couleur);
	P1.x=160;P1.y=492;
	aff_pol(s2, 45, P1, couleur);
	P1.x=160;P1.y=362;
	aff_pol(s3, 45, P1, couleur);
	P1.x=420; P1.y=200;
	couleur= couleur_RGB(223,159,155);
	draw_circle(P1,53,couleur);
	draw_circle(P1,54,couleur);
	draw_circle(P1,55,couleur);
	draw_circle(P1,56,couleur);
	draw_circle(P1,57,couleur);
	draw_circle(P1,58,couleur);
	P1.x=375; P1.y=215;
	s3="RETOUR";
	aff_pol(s3, 22, P1, noir);	
}

//Fonction qui permet de recuperer le choix de l'utilisateur dans l'interface Difficulté
int Choix_Difficulte(POINT P){
	if (P.x>=100 && P.x<=750){
		if (P.x>=365 && P.x<=472){
		if (P.y >= 147 && P.y <= 255) return 4;
		}
		if (P.y>=550 && P.y<=630 ) return 1;
		if (P.y>=420 && P.y<=500 ) return 2;
		if (P.y>=290 && P.y<=370 ) return 3;
		else return 0;
		}
		
	else return 0;
}

//Affichage de l'interface Aide
void Afficher_Aide(){
	POINT P1;
	COULEUR couleur;
	couleur= couleur_RGB(227,195,189);
	fill_screen(couleur);
	couleur= couleur_RGB(246,114,128);
	P1.x=150;P1.y=820;
	char* s0="S U D O K U";
	aff_pol(s0, 95, P1, couleur);
	P1.x=20;P1.y=640;
	couleur= couleur_RGB(150,92,80);
	char *s1="* Un sudoku classique contient neuf lignes et neuf ";
	aff_pol(s1, 28, P1, couleur);
	P1.x=20;P1.y=600;
	s1="colonnes, donc 81 cases au total.";
	aff_pol(s1, 28, P1, couleur);
	P1.x=20;P1.y=550;
	s1="* Le but du jeu est de remplir ces cases avec des chiffres";
	aff_pol(s1, 28, P1, couleur);
	P1.x=20;P1.y=510;
	s1="allant de 1 "agrave" 9 en veillant toujours "agrave" ce qu'un m"ecirc"me";
	aff_pol(s1, 28, P1, couleur);
	P1.x=20;P1.y=470;
	s1="chiffre ne figure qu'une seule fois par colonne, une seule";
	aff_pol(s1, 28, P1, couleur);
	P1.x=20;P1.y=430;
	s1="fois par ligne, et une seule fois par carr"eacute" de neuf cases.";
	aff_pol(s1, 28, P1, couleur);
	couleur= couleur_RGB(223,159,155);
	P1.x=420; P1.y=200;
	draw_circle(P1,53,couleur);
	draw_circle(P1,54,couleur);
	draw_circle(P1,55,couleur);
	draw_circle(P1,56,couleur);
	draw_circle(P1,57,couleur);
	draw_circle(P1,58,couleur);
	P1.x=375; P1.y=215;
	char *s3="RETOUR";
	aff_pol(s3, 22, P1, noir);
		
}

//Fonction qui permet de recuperer le choix de l'utilisateur dans l'interface Aide
int Choix_Aide(POINT P){
	if (P.y >= 147 && P.y <= 255){
	if (P.x>=365 && P.x<=472) return 1;
	else return 0;}
	else return 0;
}

//Affichage du message pas de solution
void Sudoku_Pas_De_Solution(){
	POINT P;
		P.x=182;P.y=623;
		char *S="PAS DE SOLUTION";
	aff_pol(S, 50, P,rouge);
	
}

//Affichage de l'interface defaite	
void Affichage_Defaite(){
	COULEUR couleur;
	POINT P1;
	couleur= couleur_RGB(217,216,217);
	fill_screen(couleur);
	couleur= couleur_RGB(162,43,95);
	P1.x=130;P1.y=790;
	char* s0="S U D O K U";
	aff_pol(s0, 95, P1, couleur);
	Sudoku_Pas_De_Solution();
	couleur= couleur_RGB(58,66,90);
	P1.x=180; P1.y=400;
	draw_circle(P1,58,couleur);
	draw_circle(P1,59,couleur);
	draw_circle(P1,60,couleur);
	draw_circle(P1,61,couleur);
	draw_circle(P1,62,couleur);
	draw_circle(P1,63,couleur);
	P1.x=150; P1.y=427;
	char *s3="Menu";
	aff_pol(s3, 22, P1, noir);
	P1.x=127; P1.y=402;
	s3="Principale";
	aff_pol(s3, 22, P1, noir);
	P1.x=650; P1.y=400;
	draw_circle(P1,58,couleur);
	draw_circle(P1,59,couleur);
	draw_circle(P1,60,couleur);
	draw_circle(P1,61,couleur);
	draw_circle(P1,62,couleur);
	draw_circle(P1,63,couleur);
	P1.x=601; P1.y=417;
	s3="QUITTER";
	aff_pol(s3, 22, P1, noir);
}	

//Fonction qui permet de recuperer le choix de l'utilisateur dans l'interface Defaite
int Choix_Defaite(POINT P){
	if (P.y>=345 && P.y<=458){
		if(P.x>=122 && P.x<=237) return 1;
		if(P.x>=592 && P.x<=706) return 2;
		else return 0;}
	else return 0;
}

//Affichage de l'interface gagné
void Affichage_Gagne(){
	COULEUR couleur;
	POINT P1;
	couleur= couleur_RGB(126,204,248);
	fill_screen(couleur);
	P1.x=130;P1.y=790;
	couleur= couleur_RGB(24,39,61);
	char* s0="S U D O K U";
	aff_pol(s0, 95, P1, couleur);
	P1.x=270;P1.y=650;
	char *S="GAGN"Egrave"";
	aff_pol(S, 80, P1, blanc);
	couleur= couleur_RGB(242,60,80);
	P1.x=180; P1.y=400;
	draw_circle(P1,58,couleur);
	draw_circle(P1,59,couleur);
	draw_circle(P1,60,couleur);
	draw_circle(P1,61,couleur);
	draw_circle(P1,62,couleur);
	draw_circle(P1,63,couleur);
	P1.x=150; P1.y=427;
	char *s3="Menu";
	aff_pol(s3, 22, P1, noir);
	P1.x=127; P1.y=402;
	s3="Principale";
	aff_pol(s3, 22, P1, noir);
	P1.x=650; P1.y=400;
	draw_circle(P1,58,couleur);
	draw_circle(P1,59,couleur);
	draw_circle(P1,60,couleur);
	draw_circle(P1,61,couleur);
	draw_circle(P1,62,couleur);
	draw_circle(P1,63,couleur);
	P1.x=601; P1.y=417;
	s3="QUITTER";
	aff_pol(s3, 22, P1, noir);
}

//Fonction qui permet de recuperer le choix de l'utilisateur dans l'interface Gagné
int Choix_Gagne(POINT P){
	if (P.y>=345 && P.y<=458){
		if(P.x>=122 && P.x<=237) return 1;
		if(P.x>=592 && P.x<=706) return 2;
		else return 0;}
	else return 0;
}

//Affichage qui suit l'affichage de la resolution de sudoku
void Affichage_Apres_Solution(){
	COULEUR couleur;
	POINT P1;
	couleur= couleur_RGB(243,243,243);
	fill_screen(couleur);
	P1.x=130;P1.y=790;
	couleur= couleur_RGB(111,62,118);
	char* s0="S U D O K U";
	aff_pol(s0, 95, P1, couleur);
	P1.x=140; P1.y=400;
	draw_circle(P1,58,couleur);
	draw_circle(P1,59,couleur);
	draw_circle(P1,60,couleur);
	draw_circle(P1,61,couleur);
	draw_circle(P1,62,couleur);
	draw_circle(P1,63,couleur);
	P1.x=108; P1.y=430;
	char *s3="Menu";
	aff_pol(s3, 22, P1, noir);
	P1.x=88; P1.y=405;
	s3="Principale";
	aff_pol(s3, 22, P1, noir);
	P1.x=440; P1.y=400;
	draw_circle(P1,58,couleur);
	draw_circle(P1,59,couleur);
	draw_circle(P1,60,couleur);
	draw_circle(P1,61,couleur);
	draw_circle(P1,62,couleur);
	draw_circle(P1,63,couleur);
	P1.x=407; P1.y=435;
	s3="Revoir";
	aff_pol(s3, 22, P1, noir);
	P1.x=425; P1.y=412;
	s3="La";
	aff_pol(s3, 22, P1, noir);
	P1.x=395; P1.y=388;
	s3="Solution";
	aff_pol(s3, 22, P1, noir);
	P1.x=720; P1.y=400;
	draw_circle(P1,58,couleur);
	draw_circle(P1,59,couleur);
	draw_circle(P1,60,couleur);
	draw_circle(P1,61,couleur);
	draw_circle(P1,62,couleur);
	draw_circle(P1,63,couleur);
	P1.x=671; P1.y=412;
	s3="QUITTER";
	aff_pol(s3, 22, P1, noir);
}

//Fonction qui permet de recuperer le choix de l'utilisateur dans l'interface Apres Solution
int Choix_Apres_Solution(POINT P){
	if (P.y>=343 && P.y<=459){
		if(P.x>=82 && P.x<=195) return 1;
		if(P.x>=382 && P.x<=497) return 2;
		if(P.x>=661 && P.x<=777) return 3;
		else return 0;}
	else return 0;
}


//Fonction qui permettre d'afficher la liste des valeurs possibles pour une case donné
void Afficher_Valeurs_Possibles(SUDOKU S,int i,int j,POINT P1){
	elt *l;
	l=S.sdk[i][j].valpos;
	if(l!=NULL){
	for(int k=1;k<=9;k++){
		if(ExisteDansLaListe(l,k))
		{
			aff_int(k, 8 ,P1, noir);}
			P1.x+=10;
			l=l->suiv;
			}
	if(l==l->suiv && S.sdk[i][j].val==0){
		POINT p1,p2;
		if (j==0 || j==3 || j==6){
			if (i==2 || i==5 || i==8){
				if(i==8){
					p1.x=94*j+3;
					p1.y=783-94*i+1;
					p2.x=p1.x+92-2;
					p2.y=p1.y+92;
					draw_fill_rectangle(p1,p2,rouge);
					
				}
				else{
		p1.x=94*j+3;
		p1.y=783-94*i+3;
		p2.x=p1.x+90;
		p2.y=p1.y+90;
		draw_fill_rectangle(p1,p2,rouge);
			}
			}
		    else{
		p1.x=94*j+3;
		p1.y=783-94*i+1;
		p2.x=p1.x+90;
		p2.y=p1.y+92;
		draw_fill_rectangle(p1,p2,rouge);
		}
	  }
		else{
			if (j==8){
			 if (i==2 || i==5 || i==8){
				 if(i==8){
					p1.x=94*j+1;
					p1.y=783-94*i+1;
					p2.x=p1.x+90;
					p2.y=p1.y+92;
					draw_fill_rectangle(p1,p2,rouge);
					
				}
			else{
			   p1.x=94*j+1;
			   p1.y=783-94*i+3;
			   p2.x=p1.x+91;
		       p2.y=p1.y+90;
			   draw_fill_rectangle(p1,p2,rouge);
		   }
	   }
		else{
			if (i==0){
						 p1.x=94*j+1;
						 p1.y=783-94*i+1;
						 p2.x=p1.x+90;
						 p2.y=p1.y+92;
						 draw_fill_rectangle(p1,p2,rouge);
					
				}
		   p1.x=94*j+1;
		   p1.y=783-94*i+1;
		   p2.x=p1.x+91;
		   p2.y=p1.y+92;
		   draw_fill_rectangle(p1,p2,rouge);	
	  }				
	}
		else{
		   if (i==2 || i==5 || i==8){
			   if(i==8){
					p1.x=94*j+1;
					p1.y=783-94*i+1;
					p2.x=p1.x+92;
					p2.y=p1.y+92;
					draw_fill_rectangle(p1,p2,rouge);
				}
			else{
				p1.x=94*j+1;
				p1.y=783-94*i+3;
				p2.x=p1.x+92;
				p2.y=p1.y+90;
				draw_fill_rectangle(p1,p2,rouge);
		}
	}
		   else{
			p1.x=94*j+1;
			p1.y=783-94*i+1;
			p2.x=p1.x+92;
			p2.y=p1.y+92;
			draw_fill_rectangle(p1,p2,rouge);	
	       }
	      }
	    }
	  }
	}
 }
			
				 
// Fonction qui affiche l'état courant du sudoku                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
void Sudoku_Afficher(SUDOKU S,char* titre,int choix,int** mat){
	
	 fill_screen(COUL_FOND);
	 
	 POINT P1, P2,P3;
	  
	  //Crée les lignes horizontaux
	  P1.x = 0; P1.y = 31;
	  P2.x = 954; P2.y = 31;
	  P3.x=954;
	  for(int i=0;i<10;i++){
		  if (i%3==0){
			   if(i==0) P3.y=P2.y-2;
			   else P3.y=P2.y+2;
		       draw_fill_rectangle(P1,P3,noir);
		       }
		  else  draw_line(P1,P2,noir);
		  P1.y+=TAILLE_CASE;
		  P2.y+=TAILLE_CASE;
	   }
	  
     //Crée les lignes Verticaux
     P1.x=0;P1.y=30;
     P2.x=0;P2.y=876;
       for(int i=0;i<10;i++){
		  if (i%3==0){
			 if(i==9) P3.x=P2.x-2;
			 else P3.x=P2.x+2;
			 draw_fill_rectangle(P1,P3,noir);
			 }
		  else{
		  draw_line(P1,P2,noir);}
		  P1.x+=TAILLE_CASE;
		  P2.x+=TAILLE_CASE;
	  }
	  
	  //Ecrire le nom du fichier en haut
	  P1.x=6;P1.y=935;
	  aff_pol(titre,35, P1, rouge);
	  
	  //Affichage du contenu de Soduku
	   P1.x=30;P1.y=875;
	   P2.x=4;P2.y=800;
			for (int i=0;i<9;i++){
			  for (int j=0;j<9;j++){
				 if (S.sdk[i][j].dt==0 ){
				   if(S.sdk[i][j].val!=0) {
					 if(choix==0) aff_int(S.sdk[i][j].val, TAILLE_POLICE ,P1, orange);
				     else{
					    if (mat[i][j]==1) aff_int(S.sdk[i][j].val, TAILLE_POLICE ,P1, rouge);
						else aff_int(S.sdk[i][j].val, TAILLE_POLICE ,P1, orange);
					    }
					}
				 }
				 else{
				 aff_int(S.sdk[i][j].val, TAILLE_POLICE ,P1, marron);
				     }
				    
			    Afficher_Valeurs_Possibles(S,i,j,P2);
				P2.x+=94;
				P1.x+=TAILLE_CASE;  
			}   
				P1.x=30;
				P1.y-=TAILLE_CASE;
				P2.x=4;
				P2.y-=94;  
	}
}
     
