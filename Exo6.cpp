#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,n,j,m,T[30],Tab[30];
	const float Pi =3.5;
 do{
 	printf("saisir la taille de votre tableau : ");
 	scanf("%d",&n);
 }while(n<1||n>30);
 for(i=0;i<n;i++){
 	printf("saisir T[%d]",i);
 	scanf("%d",&T[i]);
	 }	
	 Tab[0]=T[0];
		m=1;
for(i=0;i<m;i++)
for(j=1;j<n;j++)
	{
			if(T[j]!=Tab[i]){
			m++;
	       	Tab[i+1]=T[j];	
			}
			}
	for(i=0;i<m;i++){
		printf("Tab[%d]=%d \n",i ,Tab[i]);
	}
	printf("%f",Pi);
		}
	
	

