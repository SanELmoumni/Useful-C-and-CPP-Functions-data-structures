using namespace std;
//  Conjugué = L'opposé de la partie imaginaire 

class Complexe{
	double Re,Im;
	public : 
	Complexe();
	Complexe(double i);
	Complexe(double r,double i);
	Complexe(const Complexe&);
	double get_Re();
	double get_Im();
	void set_Re(double);
	void set_Im(double);
	friend ostream& operator<<(ostream&,const Complexe&);
	/* ON DOIT OBLIGATOIREMENT LA DEFINIR COMME FCT EXTERNE !!!
		PCK L'OPERANDE A GAUCHE EST DE CLASS OSTREAM
		ET L'OPERANDE A DROITE EST DE CLASS COMPLEXE
		DONC AVEC COUT<<C1<<C2 ON AURA ERREUR 
		CAR C1 DOIT ETRE DE TIPE OSTREAM !!!
	 */
	double Module();
	Complexe Conjugue();
	bool operator==(const Complexe&);
	bool operator!=(const Complexe&);
	Complexe operator+(const Complexe&);
	Complexe operator*(const Complexe&);
	friend istream& operator>>(istream& ,Complexe&);
		//COPIE PROFONDE
};
	
