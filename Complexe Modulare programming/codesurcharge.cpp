#include<iostream>
#include"codesurcharge.hpp"
#include<cmath>

	Complexe::Complexe():Re(0),Im(0){ }
	
	Complexe::Complexe(double i=0):Re(i),Im(0){ }
	
	Complexe::Complexe(double r,double i):Re(r),Im(i){ }
	
	Complexe::Complexe(const Complexe& c):Re(c.Re),Im(c.Im){ }
	
	double Complexe::get_Im(){return Im;}
	
	double Complexe::get_Re(){return Re;}
	
	void Complexe::set_Im(double i){Im=i;}
	
	void Complexe::set_Re(double r){Re=r;}
	
	ostream& operator<<(ostream& co,const Complexe& c){
		if(c.Re!=0){
			if(c.Im>0){
				co<<c.Re<<"+"<<c.Im<<"i";
			}else if(c.Im<0){
				co<<c.Re<<"-"<<-(c.Im)<<"i";
			}
			else
				co<<c.Re;
		}
		else{
			if(c.Im>0){
				co<<c.Im<<"i";
			}else if(c.Im<0){
				co<<"-"<<-(c.Im)<<"i";
			}
			else
				co<<0;
			
		} 
		return (co);
		}
		
	
	double Complexe::Module(){
		return (sqrt((Re*Re)+(Im*Im)));
	}
	
	Complexe Complexe::Conjugue(){
		Complexe c(0); //equivalent à
		c.Re=Re;    //equivalent à
		c.Im=-Im;   //equivalent à
		return c;   //equivale,t à return Complexe(Re,-Im);  (CONSTRUCTEUR)!!
		
	}	
	
	bool Complexe::operator==(const Complexe& c){
		return (c.Re==Re && c.Im==Im);
	}
	
	bool Complexe::operator!=(const Complexe& c){
		return(!(*(this)==c));
	}
	Complexe Complexe::operator+(const Complexe& c){
		return(Complexe(Re+c.Re,Im+c.Im));
	}
	Complexe Complexe::operator*(const Complexe& c){
		return(Complexe(Re*c.Re-Im*c.Im,Im*c.Re+Re*c.Im));
	}	
	
	
	istream& operator>>(istream& is,Complexe &c){
		cout<<"Saisir la partie reelle ";
		is>>c.Re;
		cout<<"Saisir la partie imaginaire";
		is>>c.Im;
		return(is);	
	}
