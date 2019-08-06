#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int A[30];
	int i,donnee,n;
	do{
	/* derniere occurence */
		printf("Entrer la taille n : ");
		scanf("%d",&n);
	}while (n<1||n>30);
	for (i=0;i<n;i++)
	{printf("Saisir T[%d]:",i);
	scanf("%d", &A[i]);
	}
	printf("Entrer votre donnee:");
	scanf("%d",&donnee);i=n;
	for(i=n-1;i>=0&&A[i]!=donnee; i--);
	/* ou bien avec while */
	if	(i==0) printf("Donnée inéxistante \n");
	else printf("%d se trouve pour la derniere fois en i=%d \n",donnee ,i);
		system("pause");
		return 0;
}
