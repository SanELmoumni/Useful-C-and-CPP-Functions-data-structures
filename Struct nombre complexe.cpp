#include<stdio.h>
#include<stdlib.h>
main(){
struct comple{
	float Re,Im;
};

float AR[30],AI[30];	
struct comple A[30],Reste[30];

int i,a,c,re,r;
do {
	printf("Saisir la taille de A : a= ");
	scanf("%d",&a);
}while(a<=0 || a>30);
printf("%d",a);
for(i=0;i<a;i++)
{
	printf("Saisir le reel du complexe : \n");
	scanf("%f",&A[i].Re);
	printf("Saisir l'imaginaire du complexe : \n");
	scanf("%f",&A[i].Im);
}
a=0;c=0;re=0;
for(i=0;i<a;i++){
	if(A[i].Im==0){
		AR[r]=A[i].Re;
		r++;
	}
	else if(A[i].Re==0){
		AI[c]=A[i].Im;
		c++;
	}
	else{
		Reste[re].Re=A[i].Re;
		Reste[re].Im=A[i].Im;
		re++;
	}
}
for(i=0;i<r;i++)
printf("%f",AR[i]);
}
