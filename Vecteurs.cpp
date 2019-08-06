#include<iostream>
#include<cmath>
using namespace std;
class Vecteur{
	int taille;
	float* T;
	public:
	Vecteur();
	Vecteur(int);
	Vecteur(const Vecteur&);
	~Vecteur();
	bool test_egal(const Vecteur&);
	float norme();

	
	float operator[](int);
	Vecteur operator+(const Vecteur&);
	Vecteur operator*(float);
	float operator*(const Vecteur&);
	friend Vecteur operator*(float,const Vecteur&);
	bool operator==(const Vecteur&);
	bool operator!=(const Vecteur&);
	Vecteur& operator=(const Vecteur&);
	friend ostream& operator<<(ostream&,const Vecteur&);
	friend istream& operator>>(istream&,Vecteur&);
	
	
};
Vecteur::Vecteur(){
	T=new float[1];
	T[0]=0;
}
Vecteur::Vecteur(int n){
	int i;
	taille=n;
	T=new float[n];
}

Vecteur::Vecteur(const Vecteur& v){
	taille=v.taille;
	T=new float[taille];
	for(int i=0;i<taille;T[i]=v.T[i],i++);
}


Vecteur::~Vecteur(){
	delete T;
}




bool Vecteur::test_egal(const Vecteur& v){
	bool test=false;
	if(taille==v.taille){
	for(int i=0;i<taille;i++){
	if(T[i]==v.T[i]) test=true;
	else{
		test=false;
		break;
	}
	 }
}return (test);
}



	float Vecteur::norme(){
	float s=0;
	int i=0;
	for(i=0;i<taille;i++,s+=T[i]*T[i]);
	s=sqrt(s);
	return s;
	}


		
			//PARTIE SURCHARGE !!
			
			
Vecteur Vecteur::operator+(const Vecteur& v){
	Vecteur v1(v);
	if(taille!=v.taille)cout<<"Somme impossible car tailles différentes";
	else {
	for(int i=0;i<taille;i++)
		v1.T[i]=T[i]+(v.T[i]);
}
	return v1;
}



	ostream& operator<<(ostream& ct,const Vecteur& v){
		int i;
		for(i=0;i<v.taille;i++)
		ct<<v.T[i]<<"\t";
		return(ct);
	}
	
	istream& operator>>(istream& in,Vecteur& v){
		cout<<"saisir la taille du vecteur :";
		in>>v.taille;
		for(int i=0;i<v.taille;i++){
			cout<<"saisir T["<<i<<"] : "<<endl;
			in>>v.T[i];
		}
		return(in);
	}
	
	
	Vecteur Vecteur::operator*(float k){
		Vecteur v(*(this));
		for(int i=0;i<taille;i++)
		v.T[i]=T[i]*k;
		return v;	
	}


	float Vecteur::operator*(const Vecteur& v){
		float produit=0;
		for(int i=0;i<taille;i++){
			produit+=T[i]*v.T[i];
		}
	return produit;
	}
	
	
	
	Vecteur operator*(float x,const Vecteur& v){
		Vecteur vp(v);
		for(int i=0;i<v.taille;i++)vp.T[i]=v.T[i]*x;
			return(vp);
}

	bool Vecteur::operator==(const Vecteur& v){
		bool test=false;
		if(taille==v.taille){
		for(int i=0;i<taille;i++){
		if(T[i]==v.T[i]) test=true;
		else{
			test=false;
			break;
		}
	 }
}return (test);
									}
	
	
	bool Vecteur::operator!=(const Vecteur& v){
		return (!(*(this)==v));
	}
	
	Vecteur& Vecteur::operator=(const Vecteur& v){
		taille=v.taille;
		T=new float[taille];
		for(int i=0;i<taille;i++,T[i]=v.T[i]);
		return(*(this));
	}
	
	
	
float Vecteur::operator[](int i){
	return(T[i]);
}



int main(){
	Vecteur v;
	cin>>v;
	Vecteur vs(0);
	cout<<"v="<<v<<endl;
	Vecteur v2=v;
	cout<<"La norme est : ";
	cout<<v.norme()<<endl;
	cout<<"v*v2="<<v2*v<<endl;
	cout<<"3*v="<<3*v<<endl;
	cout<<"v*3="<<v*3<<endl;	
	return 0;
}
