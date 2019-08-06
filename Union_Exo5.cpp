#include<stdlib.h>
#include<stdio.h>
int main()
{
	int ia,ib,ic,a,b,c,C[60],A[30],B[30];
	do{
		printf("saisir la taille de A : ");
		scanf("%d",&a);
	}while(a<1 || a>30);
	for(ia=0;ia<a;ia++)
	{
		printf("saisir A[%d] :",ia);
		scanf("%d",&A[ia]);
	}
	do{
		printf("saisir la taille de B : ");
		scanf("%d",&b);
	}while(b<1 || b>30);
	for(ib=0;ib<b;ib++)
	{
		printf("saisir B[%d] :",ib);
		scanf("%d",&B[ib]);
	}		
	ia=0; ib=0; ic=0;
	while(ia<a && ib<b)
		{
			for(ib=0;ib<b;ib++){
			if(A[ia]==B[ib])
				{
					C[ic]=A[ia];
					ia++;
					ic++;
				}
	   		   }
			else
				{
					C[ic]=A[ia];
					ic++;
					ia++;
					C[ic]=B[ib];
					ic++;
					ia++;
				}
		}
	while(ib<b)
		{
			C[ic]=B[ib];
			ic++;
			ib++;
		}
	while(ia<a)
		{
			C[ic]=A[ia];
			ia++;
			ic++;
		}
	c=ic;
	for(ic=0;ic<c;ic++){
		printf("C[%d]= %d \n",ic ,C[ic]);
}system("pause");}
