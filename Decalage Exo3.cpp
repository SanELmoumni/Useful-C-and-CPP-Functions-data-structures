#include<stdio.h>
#include<stdlib.h>
int main ()
{
 int T[30],i,j,n,aux;
 do{
 	printf("Saisir la taille du tableau :\n");
 	scanf("%d",&n);
 }while(n<1||n>30);
 for(i=0;i<n;i++){
 	do{
 		printf("Saisir la valeur %d \n",i+1);
 		scanf("%d",&T[i]);
	 }while(T[i]<0);
				 }
	for(j=0;j<3;j++) {
	aux=T[n-1];
		for(i=n-1;i>0;i--){
			T[i]=T[i-1];}
	T[0]=aux;
	}
	for(i=0;i<n;i++)
		printf("%d \n",T[i]);
			 
	}
