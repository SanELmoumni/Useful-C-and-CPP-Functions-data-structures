#include<stdio.h>
#include<stdlib.h>


int leen(char* c){
	int tol=0,i=0;
	while(c[i]!='\0'){
	tol++;
	i++;
		}
		return tol;

}

int main(void)
{
	char src[]="Coucou !";
	printf(" %d ",leen(src));
	
}
