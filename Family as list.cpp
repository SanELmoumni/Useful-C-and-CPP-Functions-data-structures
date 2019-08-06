#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	struct celenf
			{       				
				int age; 
				char prenom[20];
				struct celenf *next; 
			};
	typedef struct celenf *penf;
	
	struct cellule
			{       				
				char nom[20]; 
				int parents;
				penf enfants;
				struct cellule *suivant;
			};
	typedef struct cellule *liste;
									//AJOUT BEBE
	void ajout(liste l, char nomf[], char bb[]){
		liste q=l;
		penf nouveau,p;
		while(q!=NULL && strcmp(nomf,q->nom)!=0)	q=q->suivant;
		if(q!=NULL){
			nouveau=(penf)malloc(sizeof(celenf));
			strcpy(nouveau->prenom,bb);
			nouveau->age=0;
			nouveau->next=NULL;
			p=q->enfants;
		}
		if(p==NULL)
		q->enfants=nouveau;
		else{
			while(p->next!=NULL)
			p=p->next;
		p->next=nouveau;	}
	}
	
	int nbrparents(liste l){
		if(l==NULL)
		return 0;
		else
		if(l->parents==2)
			return (1+nbrparents(l->suivant));
			return (nbrparents(l->suivant));
	}
	penf creer_enf(liste *l,int b){
		int i;
		
		for(i=0;i<b;i++){
			
		}
	}
	
	
	liste creer_fam(int n){
		int i,b;
		liste l=NULL,p=NULL;
		for(i=0;i<n;i++){
			l=(liste)malloc(sizeof(cellule));
			printf("Veuillez saisir le nom de la famille SVP \n");
			scanf("%s",l->nom);
			printf("Veuillez saisir le nombre de parents de la famille SVP \n");
			scanf("%d",&(l->parents));
			printf("Veuillez saisir le nombre de parents de la famille SVP \n");
			scanf("%d",&b);
			creer_enf(&l,b);

		}
		
		
		
	}
	
	
	
	
	
	
	
	
