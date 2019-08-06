#include<iostream>
#include<conio.h>

using namespace std;

class Date{	public:
	int j,m,a;
		Date(int jour,int mois,int annee):j(jour),m(mois),a(annee){}
		Date();
		int get_jour(){return(j);}
		int get_mois(){return(m);}
		int get_annee(){return(a);}
		void set_annee(int ann){a=ann;}
		void set_mois(int moo){m=moo;}
		void set_jour(int jr){j=jr;}
		void affiche_dt(Date d){
			cout<<d.get_jour()<<"/"<<d.get_mois()<<"/"<<d.get_annee();
		}
		
};

class Employe{
	public : Date dt_naiss;
	private:
		
		int matricule;
		string nom;
		string prenom;
		
		char situation;

	public:
		
		void setNom(string nm,string prenm){   
			//Name setter
			
			nom=nm;
			prenom=prenm;
		}
		
		void setMatricule(int x){
			//Marticule setter
			matricule=x;
		}
		
		void setDate(Date a){
			// Birthdate setter
			dt_naiss=a;
		}
		
		void setState(char st){
			// State setter
			situation=st;
		}
		
		int getMatricule ()const{
			//Matrcule getter
			return matricule;
		}
		
		string getNom ()const{
			// First name getter
			return nom;
		}
		
		string getPrenom()const{
			//Last name getter
			return prenom;
		}
		
		Date getDate()const{
			//Birthdate getter
			return dt_naiss;
		}
		
		char getSituation()const{
			//Situation getter
			return situation;}
			
			
			
		void saisie(){
			string nm,prnm;
		int mat;
		int ji,mi,ni;
		char situ;

		cout<<"Saisir le nom et le prenom de l'employe"<<endl;
		cin>>nm>>prnm;
		setNom(nm,prnm);
	
		cout<<"Saisir le matricule de l'employe"<<endl;
		cin>>mat;
		setMatricule(mat);
		
		cout<<"Saisir la date de naissance de l'employe";
		cout<<"(jour/mois/annee)"<<endl;
		dt_naiss.set_jour(ji);
		dt_naiss.set_mois(mi);
		dt_naiss.set_annee(ni);
			
		do{
		cout<<"Saisir la situation familiale de l'employe.";
		cout<<"(M pour Marie,C pour Celibataire et D pour Divorce)";
		cout<<endl;
		cin>>situ;
		setState(situ);
		}while(situ!='C' && situ!='M' && situ!='D');	
			}


	

 						// AFFICHE !

void Affiche(){
	cout<<"L'employe s'appelle "<<getNom()<<" "<<getPrenom()<<endl;
	cout<<"Son matricule est : "<<getMatricule()<<endl;
	cout<<"Il/Elle est ne(e) le : "<<getDate().j<<"/"<<getDate().m<<"/"<<getDate().a<<endl;
	switch(getSituation()){
		case 'M' :
			cout<<"L'employe(e) est Marie(e)"<<endl;
			break;
		case 'C' :
			cout<<"L'employe(e) est Celibataire"<<endl;
			break;
		case 'D' :
			cout<<"L'employe(e) est Divorce(e)"<<endl;
			break;
	}
}

		//MODIFIE  !!
		
void Modifie(){
	char situ;
	cout<<"\t \t ------ Modification de la situation familiale de l'employe ------";
	cout<<endl;
	do{
	cout<<endl<<endl<<"Quel est la nouvelle situation familiale de l'employe ?"<<endl;
	cout<<"M pour Marie,C pour Celibataire et D pour Divorce)"<<endl;
	cin>>situ;
	setState(situ);
	}while(situ!='C' && situ!='M' && situ!='D');	
}
};

int main(){
	Employe m;
	m.saisie();
	m.Affiche();
	m.Modifie();
	m.Affiche();
	return 0;
}
