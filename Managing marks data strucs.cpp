#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

	struct cellule
			{       				
				int CNE;
				float s1;
				float s2;
				struct cellule *suivant;
			};
	typedef struct cellule *liste;
	
	int validation_itr(liste l){
		liste p=l;
		int nbr=0;
		while(p!=NULL){
			if(p->s1>=10 && p->s2>=10)
			nbr++;
		p=p->suivant;}
		return (nbr);
		}
		//CREATION AVEC INSERTION EN TETE 
	liste creer_tete(int n){
		liste p,l=NULL;
		int i;
		for(i=0;i<n;i++){
		p=(liste)malloc(sizeof(cellule));
		printf("saisir le CNE");
		scanf("%d",&(p->CNE)); 
		printf("saisir la note du s1");
		scanf("%f",&(p->s1));
		printf("saisir la note du s2");
		scanf("%f",&(p->s2));
		p->suivant=l;
		l=p;
						}
		return(p);
		}
			//CREATION AVEC INSERTION EN QUEU
		liste creer_q(int n){
			liste l,nouveau,dernier;
			int i=0;
			l=(liste)malloc(sizeof(cellule));
			printf("saisir le CNE \n CNE : ");
			scanf("%d",&(l->CNE)); 
			printf("saisir la note du s1 \n Note S1 : ");
			scanf("%f",&(l->s1));
			printf("saisir la note du s2 \n Note S2 : ");
			scanf("%f",&(l->s2));	
			l->suivant=NULL;
			dernier=l;		
			printf("hello1");

			for(i=0;i<n-1;i++){
				printf("hello2");
				nouveau=(liste)malloc(sizeof(cellule));
				printf("saisir le CNE \n CNE : ");
				scanf("%d",&(nouveau->CNE)); 
				printf("saisir la note du s1 \n Note S1 : ");
				scanf("%f",&(nouveau->s1));
				printf("saisir la note du s2 \n Note S2 : ");
				scanf("%f",&(nouveau->s2));
				dernier->suivant=nouveau;
				nouveau->suivant=NULL;
				dernier=nouveau;
			}
								}
		
		
		int validation_rec(liste l){
			if(l=NULL)
			return(0);
			else 
			if(l->s1>=10 && l->s2>=10)
			return (1+validation_rec(l->suivant));
			else
			return (validation_rec(l->suivant));
		}
		
		
		int validation_s2_it(liste l){
		liste p=l;
		int nbr=0;
		while(p!=NULL){
			if(p->s1<10 && p->s2>=10)
			nbr++;
		}
		p=p->suivant;
		return (nbr);
		}
		
		int validation_s2_rec(liste l){
			if(l=NULL)
			return(0);
			else 
			if(l->s1<10 && l->s2>=10)
			return (1+validation_rec(l->suivant));
			else
			return (validation_rec(l->suivant));
		}
		
//VALIDATION S2 UNIQUEMENT RESULTATS DANS UNE LISTE !
									//Sa structure !
		struct cel2{
			int CNE;
			struct cel2 *suiv;
		};
		typedef struct cel2 *list2;
		
		//Sa fonction ! 
		
		list2 Validation_S2(liste l){
			liste p=l;
			list2 premier=NULL,nouveau;
			while(p!=NULL){
				if(p->s1<10 && p->s2>=10){
					nouveau=(list2)malloc(sizeof(cel2));
				}
			}
		}

		
	main(){
		liste l,p;
		int i,n;
		printf("saisir le nombre d'etudiants \n n=");
		scanf("%d",&n);
		l=creer_tete(n);

		n=validation_rec(l);
		printf("voila : %d",n);
		}
		
	
	
	
	
	
	
	
