#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int A[30];
	int i,donnee,n;
	do{
		printf("Entrer la taille n : ");
		scanf("%d",&n);
	}while (n<1||n>30);
	for (i=0;i<n;i++)
	{printf("Saisir T[%d]:",i);
	scanf("%d", &A[i]);
	}
	printf("Entrer votre donnée:");
	scanf("%d",&donnee);i=0;
	while(i<n && A[i]!=donnee) i++;
	if	(i==n) printf("Donnée inéxistante \n");
	else printf("%d se trouve pour la premiere fois en i=%d \n",donnee ,i);
	system("pause");
}
