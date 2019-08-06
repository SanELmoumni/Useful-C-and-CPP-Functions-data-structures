#include<iostream>
const float PI=3.1416;
using namespace std;
class Figure{
	protected:
		double absc,ordc;
	public:
		Figure(double a,double o):absc(a),ordc(o){	}
		double get_abs(){return (absc);	}
		double get_ord(){return (ordc);	}
		void set_abs(double a){absc=a;	}
		void set_ord(double o){ordc=o;	}
		virtual void afficher(){
		cout<<"----------------------------------------"<<endl;
		cout<<"L'abscisse centrale est: "<<absc<< " L'ordonnee centrale est : "
		<<ordc<<endl;}
		virtual double surface()=0;
		};
		
class Rectangle: public Figure{
	double longu,larg;
	public:
		Rectangle(double a,double o,double lon,double lar):
		Figure(a,o),longu(lon),larg(lar){}
		double get_longu(){return (longu);	}
		double get_larg(){return (larg);	}		
		void set_long(double a){longu=a;}
		void set_larg(double o){larg=o;	}				
		void afficher(){
			Figure::afficher();
			cout<<"La longueur du Rectangle est : "<<longu<<
			" La largeur est : "<<larg<<endl;
		}
		double surface(){
			return(longu*larg);
		}		
					};
					
class Disque: public Figure{
	protected:
		double rayon;
	public:
		Disque(double a, double o, double r):
		Figure(a,o),rayon(r){ }
		double get_ray(){return (rayon);	}
		void set_ray(double a){rayon=a;		}	
	
		void afficher(){
		Figure::afficher();
		cout<<"Le rayon est égale a : "<<rayon<<endl;
		}
		virtual double surface(){
			return(PI*rayon*rayon);
								}
};
		
class Cylindre:public Disque{
	double hauteur;
	public:
		Cylindre(double a,double o,double r,double h):
		Disque(a,o,r),hauteur(h){}
		double get_haut(){return (hauteur);		}
		void set_haut(double a){hauteur=a;		}				
		void afficher(){
			Figure::afficher();
			cout<<"Le rayon de la base est : "<<
			rayon<<endl;
			cout<<"La hauteur de ce cylindre est : "
			<<hauteur<<endl;
		}		
		double surface(){
			return((2*PI*rayon*hauteur)+(2*PI*rayon*rayon));
		}		
		double volume(){
			return(PI*rayon*rayon*hauteur);
		}	
};

void presenter(Figure &f){
	f.afficher();
	cout<<"La surface S est : "<<f.surface()<<" metre carre !"<<endl;
}
int main(){
	Rectangle r(1,2,3,5);
	presenter(r);
	Disque d(1,0,5);
	presenter(d);
	Cylindre c(1,0,5,4);
	presenter(c);
	cout<<c.volume();
	return 0;
}		
