#include <stdlib.h>
#include "listecircu.h"
#include "gestion_sudoku.h"

//Fonction qui permet de vérifie si une valeur existe dans la liste Circulaire
int ExisteDansLaListe(elt* l,int val){ 
	if (l==NULL) return 0;
	else{
	if (l->val == val) return 1;
	else{
		elt* temp;
		temp=l->suiv;
	while (temp!=l && temp->val!=val){
	temp=temp->suiv;}
	if (temp==l) return (0);
	else return (1);
	  }
   }
}

//Fonction qui permet de retourner une liste trié a partir d'une liste circulairement trié passé en parametre
elt* MinListe(elt *l){
  if (l!=NULL){
		elt *min,*p;
		min=l;
		p=l->suiv;
		
		while (p!=l){
		  if (p->val < min->val) min=p;
		  p=p->suiv;
		} 
	 return min;
	}
  else return NULL;
}

//Fonction qui permet d'ajouter un element dans la liste circulaire
elt* AjouterElementListe(elt* l, int val){
	if (l!=NULL){
		
	elt *p,*q,*temp;
	int k=1;
	if (ExisteDansLaListe(l,val)==0){
	
	//Ajouter la valeur a la fin de la liste
	if (MaxListe(l)<val){
		while ((l->suiv)->val!=0) l=l->suiv;
		temp=CreeElement(val);
			temp->suiv=l->suiv;
			l->suiv=temp;
			return temp->suiv;
					}
	else{
	q=MinListe(l);
	p=q->suiv;
	while (k){
		if (p->val>val){ //Ajouter la valeur dans la 2éme position ( car la 1ére ne sera jamais supprimer car c'est la case vide (0) )
			temp=CreeElement(val);
			q->suiv=temp;
			temp->suiv=p;
			k=0;
		 }
		else{
			q=p;
			p=p->suiv;
			}
		  }		
	   }
	 }
	return (l);
  }
 else return l;
}

//Fonction qui permet de cree un element de type liste dans la valeur est donné dans les paramétres	
elt* CreeElement(int val){
	elt* temp;
	temp=malloc(sizeof(elt));
	temp->val=val;
	temp->suiv=NULL;
	return temp;
	
}

//Fonction qui permet de copier une liste circulaire dans une autre liste circulaire
elt* CopieListe(elt* tete_l1){
	if (tete_l1 == NULL ) return NULL;
	else{
	elt *tete_l2,*temp1,*temp2;
	tete_l2=CreeElement(tete_l1->val);
	temp1=tete_l1->suiv;
	temp2=tete_l2;
	 while(temp1 !=tete_l1){
		elt *templ2;
		templ2=CreeElement(temp1->val);
		temp2->suiv=templ2;
		temp2=templ2;
		temp1=temp1->suiv;	
	   }
	   
	temp2->suiv=tete_l2;
	return tete_l2;
  }
}

//Cette fonction permet de supprimer une valeur d'une liste circulaire
elt* SupprimerDeLaListe(elt* l,int val){ 
  if (l==NULL) return NULL;
  else{
	  if (val!=0){	
	     if (ExisteDansLaListe(l,val)){	
	        if (l->val ==val){ //Suppression de la tete
			  elt *temp,*lnouv;
			  temp=l;
			  while(temp->suiv != l) temp=temp->suiv;
			  temp->suiv=l->suiv;
			  lnouv=l->suiv;
			  free(l);
			  return lnouv;
			}
			
			else{
			 elt *p,*q;
			 p=l;
			 while(p->val!=val){
			 q=p;
			 p=p->suiv;}
			 q->suiv=p->suiv;
			free(p);	
			return l;
		  }
	  }							 
        else return l;
	}
      else return l;
  }
}

//Cette fonction retourne la valeur maximale de la liste circulaire
int MaxListe(elt* l){
	if (l!=NULL){
		elt *p;
		int max;
		max=l->val;
		p=l->suiv;
		while (p!=l){
		  if (p->val > max) max=p->val;
		  p=p->suiv;}
		  return max;
			
				}
					}

//Cette Fonction permet de retourner l'element suivant de l'element qui a comme valeur la valeur donné e
elt* ElementSuiv(elt* l,int val){
	elt* f=NULL;
	if (l!=NULL){
	  if (MaxListe(l)<=val){
		while (l->val!=0) l=l->suiv;
		f=l;
						}
	  else{
	  elt *temp;
	  temp=MinListe(l);
	   while(temp->val<val){
	   temp=temp->suiv;}
		if(temp->val==val) f=temp->suiv;
		else f=temp;
	   }
	}
return f;
}
