#include<stdio.h>
#include<stdlib.h>
int main(void)
{
     int i,n ; float s=0,note;
     do {
         printf("Saisir le nombre de note:");
         scanf("%d",&n);
         }while (n<=0);
        
		 i=1;
         while (i<=n){
               do {
                   printf ("Entrer la note %d:" ,i);
                   scanf ("%f",&note);
                   }while (note<0);
                   s=s+note;
                   i=i+1;
                   }
                   printf("La moyenne est :%f ! \n" ,s/n);
                   system ("pause");
				   }
