#include<iostream>
using namespace std;

class Etudiant{
	protected:
		string nom,prenom;
		int nbnotes;
		float* tabnotes;
		
	public:
		Etudiant(string,string,int); // string=''; int=0
		Etudiant(const Etudiant&);
		friend istream& operator>>(istream&, Etudiant&);
		friend ostream& operator<<(ostream&, Etudiant&);
		Etudiant& operator=(const Etudiant&);
		bool operator==(const Etudiant&);
		bool operator<(const Etudiant&);
		bool operator>(Etudiant&);
		
		// Methodes
		float moyenne() const;
		int eliminatoire();
		bool admis();
		
};

class Etudiant_en_Maitrise:public Etudiant{
	float note_memoire;
	public :
		Etudiant_en_Maitrise(string,string,int,float);
		Etudiant_en_Maitrise(const Etudiant_en_Maitrise&);
		Etudiant_en_Maitrise& operator=(const Etudiant_en_Maitrise&);
		friend istream& operator>>(istream&,Etudiant_en_Maitrise&);
		friend ostream& operator<<(ostream&,Etudiant_en_Maitrise&);
		
		bool admis();
		bool exaeo_quo(const Etudiant_en_Maitrise&);
};


Etudiant::Etudiant(string a="",string b="",int x=0){
	nom=a; prenom=b; nbnotes=x; tabnotes=new float[nbnotes];
}
Etudiant::Etudiant(const Etudiant& e){
	nom=e.nom;
	prenom=e.prenom;
	nbnotes=e.nbnotes;
	tabnotes=new float[nbnotes];
	for(int i=0;i<nbnotes;i++,tabnotes[i]=e.tabnotes[i]);
		
}

istream& operator>>(istream& ci, Etudiant& e){
	cout<<"saisir nom : "<<endl;
	ci>>e.nom;
	cout<<"saisir prenom : "<<endl;
	ci>>e.prenom;
	cout<<"saisir nombre de notes : "<<endl;
	ci>>e.nbnotes;
	delete(e.tabnotes);
	e.tabnotes=new float[e.nbnotes];
	for(int i=0;i<e.nbnotes;i++){
	cout<<"saisir la note : ";
	ci>>e.tabnotes[i];}
	return (ci);
}


ostream& operator<<(ostream& co, Etudiant& e){
	co<<"Le nom complet de l'etudiant est : ";
	co<<e.nom<<" "<<e.prenom<<endl;
	co<<"il dispose de "<<e.nbnotes<<" notes dans son dossier."<<endl;
	for(int i=0;i<e.nbnotes;i++)
		co<<e.tabnotes[i]<<"\t";
		cout<<endl<<endl<<"*********"<<endl;
	return(co);
}

Etudiant& Etudiant::operator=(const Etudiant& e){
	if(this!=&e){
		nom=e.nom;
		prenom=e.prenom;
		nbnotes=e.nbnotes;
		delete(tabnotes);
		tabnotes=new float[nbnotes];
		for(int i=0;i<nbnotes;i++)
			tabnotes[i]=e.tabnotes[i];
	}
	return(*(this));
}

float  Etudiant::moyenne() const{
	float s=0;
	int i=0;
	while(i<nbnotes){
		s+=tabnotes[i];
		i++;
	}
	return (s/nbnotes);
}

int Etudiant::eliminatoire(){
	int s=0;
	for(int i=0;i<nbnotes;i++){
		if(tabnotes[i]<5) s++;
	}
	return s;
}

bool Etudiant::admis(){
	return(moyenne()>=10 && eliminatoire()==0);
}

//Là
bool Etudiant::operator==(const Etudiant& e){
	return(moyenne()==e.moyenne());
}
//Là 
bool Etudiant::operator<(const Etudiant& e){
	return(moyenne()<e.moyenne());
}
//Et là aussi !
bool Etudiant::operator>(Etudiant& e){
	return(e<(*this));
}


Etudiant_en_Maitrise::Etudiant_en_Maitrise(string a="",string b="",int i=0,float f=0){	
	Etudiant(a,b,i);
	note_memoire=f;
}

Etudiant_en_Maitrise::Etudiant_en_Maitrise(const Etudiant_en_Maitrise& e):Etudiant(e),note_memoire(e.note_memoire){}

Etudiant_en_Maitrise& Etudiant_en_Maitrise::operator=(const Etudiant_en_Maitrise& e){
	if(this!=&e){
		Etudiant::operator=(e);			
		note_memoire=e.note_memoire;
		
		// OU BIEN  en utilisant les pointeurs :  
		/* 
			Etudiant* p1,p2;
			p1=this; 
			p2=&e;
			*p1=*p2;
			note_mem=e.notemem;
		*/
	}
	return(*this);
}

istream& operator>>(istream& ci,Etudiant_en_Maitrise& em){
	Etudiant* p;
	p=&em;	
	ci>>*p;
	cout<<"Saisir la note memoire : ";
	ci>>em.note_memoire;
	return (ci);
}

ostream& operator<<(ostream& co,Etudiant_en_Maitrise& em){
	Etudiant* p;	
	p=&em;
	co<<*p;
	co<<"Note memoire est : "<<em.note_memoire<<endl;
}

bool Etudiant_en_Maitrise::admis(){
	return(Etudiant::admis() && note_memoire>=12);
}
bool Etudiant_en_Maitrise::exaeo_quo(const Etudiant_en_Maitrise& e){
	return(Etudiant::operator==(e) && note_memoire==e.note_memoire);
}


int main(){
	Etudiant e4;
	Etudiant e5(e4);
	Etudiant_en_Maitrise em;
	cin>>em;
	Etudiant_en_Maitrise e=em;
	cout<<e;
	cout<<em;
	/*
	cin>>em;
	cout<<e;
	cout<<em;
	cout<<"la moyenne de e est : "<<e.moyenne()<<endl;
	cout<<"il a "<<e.eliminatoire()<<"notes eliminatoires"<<endl;
	cout<<"e est meilleur que e1";
	else
	cout<<"e1 est meilleur que e2";
	if(e.admis())
	cout<<"etudiant admis"<<endl;
	else
	cout<<"l'etudiant n'est pas admis";*/
	return 0;
}
