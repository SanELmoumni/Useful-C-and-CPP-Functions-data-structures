#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,j,i;
//ajouter etudiant, modification etudiant, supprimer, modifier
// rechercher etudiant et renvoyer position
float s;
	typedef struct Etudiant Etudiant;
		struct Etudiant
		{
			char nom[20];
			char prenom[20];
			float note[3];
			float moyenne;
		}e;
		//CREER ETUDIANT ! 
	Etudiant creer(){
		printf("saisir le nom de l'etudiant \n Nom : ");
		scanf("%s",e.nom);
		printf("saisir le prenom de l'etudiant \n Prenom : ");
		scanf("%s",e.prenom);
		printf("saisir les 3 notes de l'etudiant \n");
		s=0;
		for(j=0;j<3;j++){
			printf("Note : \n");
			scanf("%f",&e.note[j]);
			s+=e.note[j];
		}
		e.moyenne=s/3;
	return(e);
	}

//AFFICHER ETUDIANT : AFFICHE LE NOM ET LA MOYENNE
	
	void afficher_etu(Etudiant e){
		printf("%s %s \nMoyenne : %f \n" ,e.nom ,e.prenom ,e.moyenne);
	}
	
	nbr_effectif=0;
	Etudiant Tab[30];
	
	//REMPLISSAGE
	void remplissage(int n){
		int i;
		for(i=0;i<n;i++){
			Tab[i+nbr_effectif]=creer();
			nbr_effectif++;
		}
	}



void afficher_tableau(){
	int i;
	for(i=0;i<nbr_effectif;i++)
	afficher_etu(Tab[i]);
}



	int recherche(char nom[], char prenom[],int n){
		int i;
		for(i=0;i<nbr_effectif;i++)
		{
			if((strcmp(Tab[i].nom,nom)==0 )&& (strcmp(Tab[i].prenom,prenom)==0))
			return i;
		}
		if(i==nbr_effectif)
		return -1;
		
	}

Etudiant *T=NULL;
	
int main(int argc, char *argv[]) {
	int position;
	char nom[20],prenom[20];
	
	do{
		printf("saisir combien d'etudiants a traiter \n n=");
		scanf("%d",&n);
	}while(n<1||n>30);
	T=malloc(n*sizeof(Etudiant));
	if(T==NULL)
	exit(0);
	else {
		Etudiant et;
		remplissage(n);
		afficher_tableau();
		}
		printf("saisir le nom de l'etudiant \n Nom : ");
		scanf("%s",nom);
		printf("saisir le prenom de l'etudiant \n Prenom : ");
		scanf("%s",prenom);
		position=recherche(nom,prenom,n);
		if(position==-1)
		printf("Etudiant inexistant ! ");
		else 
		afficher_etu(Tab[position]);
		
	return 0;
}
