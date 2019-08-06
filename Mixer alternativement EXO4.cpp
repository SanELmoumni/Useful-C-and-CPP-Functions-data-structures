#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int A[100],B[100],C[200],a=0,b=0,c=0,i=0,ib,ia,ic;
	do{
		printf("saisir la taille de A \n");
		scanf("%d",&a);
	}while(a<=0 || a>100);
	do{
		printf("saisir la taille de B \n");
		scanf("%d",&b);
	}while(b<=0 || b>100);
	for(i=0;i<a;i++)
	{
		printf("saisir l'element A[%d] : ",i);
		scanf("%d",&A[i]);
	}
	for(i=0;i<b;i++)
	{
		printf("saisir l'element B[%d] : ",i);
		scanf("%d",&B[i]);
	}
	ia=0;ib=0;ic=0;
	while(ia<a && ib<b)
	{
		C[ic]=A[ia];
		ic++;ia++;
		C[ic]=B[ib];
		ic++;ib++;
	}
	while(ib<b){
		C[ic]=B[ib];
		ic++;ib++;
	}
	while(ia<a){
		C[ic]=A[ia];
		ic++;ia++;
	}
	for(i=0;i<ic;i++){
	printf("C[%d]=%d \n",i+1 ,C[i]);}
}
