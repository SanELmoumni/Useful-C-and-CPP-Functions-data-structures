#include<iostream>
using namespace std;
class Ensemble{
	int* tab;
	int taille,nbelt;
	
	public:
		Ensemble():tab(NULL),taille(0),nbelt(0){ }
		
		Ensemble(int n){
			tab=new int[taille=n];
			nbelt=0;
		}
		
		Ensemble(const Ensemble& e){
			int i=0;
			tab=new int[taille=e.taille];
			nbelt=e.nbelt;
			while(i<nbelt){
				tab[i]=e.tab[i];
				i++;
			}
		}
		
		~Ensemble(){
			delete(tab);
		}
		//PROTO
		
		friend ostream& operator<<(ostream&,const Ensemble&);
		friend istream& operator>>(istream&,Ensemble&);
		
		
		//ENSEMBLE > a
		// Si element existe : return 1
		bool operator>(int a){
			int i=0;
			while(i<nbelt && tab[i]!=a) i++;
			return(i<nbelt);
		}
		
		
		bool operator>(const Ensemble& e){
			int i=0;
			while((*this)>e.tab[i] && i<nbelt) i++;
			return(i==e.nbelt);
		}
		
		Ensemble operator+(int x){
			int i=0;
			if(!(*(this)>x)){
				if(nbelt!=taille){
					nbelt++;
					tab[nbelt]=x;
					return(*this);
				}
				else{
					Ensemble e;
					e.tab=new int[e.taille=taille+1];
					for(i=0;i<taille;i++)
					e.tab[i]=tab[i];
					e.tab[i+1]=x;
					e.nbelt=e.taille;
					delete(tab);
					return(e);
					}
							
							}
			else
			cout<<"Cet element Existe deja ! "<<endl;	
			
		}
		
		
		Ensemble operator+(const Ensemble& e){
			int i=0;
			Ensemble x;
			x.taille=taille+e.taille;
			x.nbelt=nbelt+e.nbelt;
			x.tab=new int[x.taille];
			for(i;i<nbelt;i++)
			x.tab[i]=tab[i];
			for(i;i<x.nbelt;i++){
				while(int j=0<nbelt){
					if(!(x>tab[j]))
			x.tab[i]=e.tab[i];
			}
									}
			return (x);
			}
		
		Ensemble operator=(const Ensemble& e){
			Ensemble x(e); // C'EST FAUX, IL FAUT REECRIRE LES PROCEDURES SUR L'OBJET COURANT
							// PCK ON VEUT RETOURNER LOBJET COURANT PAS UN AUTRE OBJET
			delete(tab);
			return(x);			
		}
		
		bool est_vide(){
			return(nbelt==0);
		}
		int cardinal(){
			return(nbelt);
		}
		
};
ostream& operator<<(ostream& co,const Ensemble& e){
	for(int i=0;i<e.nbelt;i++)
	co<<e.tab[i]<<"\t";
	co<<endl;
	return(co);
}
		 		
				
istream& operator>>(istream& ci,Ensemble& e){
	cout<<"Quel est le nombre d'elem de votre Ensemble \n";
	ci>>e.nbelt;
	for(int i=0;i<e.nbelt;i++){
		cout<<"Saisir l'element "<<i<<": ";
		ci>>e.tab[i];
	}
	return(ci);
}



int main(){
	Ensemble e(5),e1(3);
	cin>>e;
	cout<<e;
	if(e>1){
		cout<<"Existe"<<endl;}
	else {
		cout<<"N'existe pas"<<endl;
		
	}
	cin>>e1;
	e=e+e1;
	cout<<e;	
				
	return 0;	
}
