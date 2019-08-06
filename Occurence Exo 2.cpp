#include<stdio.h>
#include<stdlib.h>
int main ()
{
 int T[50],i,x,cpt,indice,n,N;
 do{
 	printf("Saisir la taille du tableau :\n");
 	scanf("%d",&n);
 }while(n<1||n>50);
 for(i=0;i<n;i++){
 	do{
 		printf("Saisir la valeur T[%d] \n",i);
 		scanf("%d",&T[i]);
	 }while(T[i]<0);
				 }
	printf("saisir la valeur que vous rechercher : ");
	scanf("%d",&x);
	printf("saisir l'occurence que vous souhaiter avoir sa position : ");
	scanf("%d",&N);
	i=0; cpt=0;
	while(i<n && cpt!=N) {
		if(T[i]==x)
		{
			indice=i;
			cpt++;   //Cmt_le_résultat_va_afficher_l'indice?
		}i++;
		}
	 if(i==n && cpt!=N)
	 {
	 	printf("L'occurence %d n'existe pas \n",x);
	 }
	 else
	 printf("L'occurence %d existe dans l'indice %d" ,x ,indice);
}
