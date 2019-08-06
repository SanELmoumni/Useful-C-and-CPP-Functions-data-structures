#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct {
	int jour;
	int mois;
	int annee;
}d;
typedef struct {
 char nom[50];
 char pays[50];
 d date;
}per;
typedef struct {
	char titre[50];
	char theme[50];
	per realisateur;
	int ann;
	int nbract;
	per acteurs[100];
}film;
typedef struct {
	film tab[100];
	int nbrf;
}video;
// prototype
void afficherdate(d date); 

// la saisie

per saisie_pers()
{ per pers;
	printf("veillez saisir le nom : \n");
	scanf("%s",pers.nom);
		printf("veillez saisir le pays:\n");
	scanf("%s",pers.pays);
	printf("saisir la date:");
	scanf("%d%d%d",&pers.date.jour,&pers.date.mois,&pers.date.annee);
	return(pers);} 
////////////// Saisie du film 

film saisief(){
film f;
printf("saisir le titre:\n");
scanf("%s",f.titre);
printf("saisir le theme:\n");
scanf("%s",f.theme);
printf("Informations sur le realisateur:\n");
f.realisateur=saisie_pers();
printf("saisir l'annee de sortie:\n");
scanf("%d",&f.ann);

//////// POURQUOI ON A PAS SAISIS LES ACTEURS ICI ?? /////////

return(f);
}

video v;

void saisie_videotheque(int nb){

	int i;
	for(i=0;i<nb;i++)                   // { 	v.tab[v.nbrf+i]=saisief();
	v.tab[v.nbrf+i]=saisief();   		//		v.nbrf++;   }
    v.nbrf=v.nbrf+nb;
}

int rechercher(char nom[])
{
	int i;
	for(i=0;i<v.nbrf;i++){
	if (strcmp(v.tab[i].titre,nom)==0)
	return i;
						}
	
	return -1;
}


void remplissage_act(char nom[],int nbract)
{int i, x=rechercher(nom);
if (x!=-1){
for(i=0;i<nbract;i++)
v.tab[x].acteurs[i]=saisie_pers();
v.tab[x].nbract=nbract;
		}
else 
printf("le film n'existe pas:");
}

	
void afficherpers(per p){
	printf("%s\n",p.nom);
	printf("le pays est %s:\n",p.pays);
	afficherdate(p.date);
}
 void afficherfilm(film f){
 		int i;
 		printf("le titre du film est %s\n",f.titre);
 		printf("le theme du film est %s\n",f.theme);
 		printf("le film a pour realisateur :\n");
 		afficherpers(f.realisateur);
 		printf("annee de sortie est:\n",f.ann);
 		for(i=0;i<f.nbract;i++)
 		{
 			afficherpers(f.acteurs[i]);
		 }
 }
 
 
 void afficherdate(d date ){
 	printf("%d/%d/%d\n",date.jour,date.mois,date.annee);
 }
 
 
 void affichervideo(){
 	int i;
 	for(i=0;i<v.nbrf;i++)
 	afficherfilm(v.tab[i]);
 }
 
 
void affichertheme(char* theme)
{
	int i,cpt=0;
printf("\n----------affichage theme:--------------\n");
printf("%d",v.nbrf);
	for(i=0;i<v.nbrf;i++)
	if(strcmp(v.tab[i].theme,theme)==0){
	afficherfilm(v.tab[i]);
	cpt++;
}

if(cpt==0)
printf("aucun film de ce theme :");
}


void afficherActeurFilm(char titre[])
{
	int trouver,i;
	trouver=rechercher(titre);
	if(trouver==-1)
		printf("le film n'existe pas\n");
	else
			for(i=0;i<v.tab[trouver].nbract;i++)
			{
				afficherpers(v.tab[trouver].acteurs[i]);
			}
}


void afficherFilmActeur(char nom[])
{
	int i,j;
	for(i=0;i<v.nbrf;i++)
		for(j=0;j<v.tab[i].nbract;j++)
			if(strcmp(v.tab[i].acteurs[j].nom,nom)==0)
				afficherfilm(v.tab[i]);
}

void modifierListeActeurs(char titre[])
{
	int n;
	printf("saisir le nombre d'acteurs");
	scanf("%d",&n);
	remplissage_act(titre,n);	
}

void supprimer(char titre[])
{
	int i,trouver=rechercher(titre);
	if(trouver==-1)
		printf("n'existe pas\n");
	else
	{
		for(i=trouver;i<v.nbrf-1;i++)
			v.tab[i]=v.tab[i+1];
	v.nbrf--;
	}
}

int menu()
{
int choix = 0;
while (choix <1 || choix > 9)
{
printf("Menu :\n");
printf("1 : Ajouter des films \n")  ;
printf("2 : remplissage de la liste des acteurs d'un film \n");
printf("3 : afficher un film par theme\n");
printf("4 : afficher la liste des acteurs d'un film'  \n");
printf("5 : afficher un film par acteur\n");
printf("6 : supprimer un film\n");
printf("7 : modifier la liste des acteurs d'un film \n");
printf("8 : affichage de la videotheque : \n");
printf("9 : Charger \n");
printf("10 : Quitter \n");
printf("Votre choix ? ");
scanf("%d", &choix);
}
return choix;
}


void charger(video *ptr) // equivalent exporter
{
	
	FILE* Flux = NULL;
	Flux = fopen("test.txt", "w");
	
	if(Flux != NULL)
	{
		int indice = 0;
		for(indice;indice<ptr->nbrf; indice++)
		{
			fprintf(Flux, "%s %s ", (*ptr).tab[indice].theme,(*ptr).tab[indice].titre);
		}
				fclose(Flux);
	}
	
}



int main(int argc, char *argv[]) {
	int nf,nact;
	char titre[30];
	int ctl=menu();
	while (ctl!=9){

	switch (ctl)
      {
           case 1:
                printf("Opération d'ajout: \n");
    			printf("saisirla videotheque:\n ");
				printf("entrer le nombre que vous desirer :");
				scanf("%d",&nf);
				saisie_videotheque(nf);
               break;
            case 2:
                 printf("remplissage de la liste des acteurs d'un film: \n");
                 printf("saisir le titre du film:");
			   	 scanf("%s",titre);
                 printf("entrer le nombre d'acteur  :");
				 scanf("%d",&nact);
				 remplissage_act(titre,nact);
              	break;
             case 3:
	                  printf("Opération d'affichage par theme : \n");
                  printf("saisir le theme du film:");
			   	  scanf("%s",titre);
                  affichertheme(titre);
              	break;
            case 4:
                  printf(":afficher la liste des acteurs par film \n");
                  printf("saisir le titre du film:");
			   	  scanf("%s",titre);
                  afficherActeurFilm(titre);
              	break;
            case 5:
                  printf("afficher les films par acteur: \n");
                  printf("saisir le nom d'acteur':");
			   	  scanf("%s",titre);
                  afficherFilmActeur(titre);
              	break;
            case 6:
                  printf("Opération de suppression: \n");
                  printf("saisir le titre du film:");
			   	  scanf("%s",titre);
			   	  supprimer(titre);
              	break;
            case 7:
                  printf("Opération de modification de la liste des acteurs: \n");
                  printf("saisir le titre du film:");
			   	  scanf("%s",titre);
			   	  modifierListeActeurs(titre);
              	break;
            case 8:
                  printf("affichage de la videotheque: \n");
                  affichervideo();
              	break;
            case 9:
                  printf("Chargement de la videotheque: \n");
                  charger(&v);
              	break;
            }
            ctl=menu();
        }
	return 0;
}
