#include<iostream>
#include"codesurcharge.hpp"
int main(int argc, char** argv) {
	Complexe c(5,-2),d;
	cout<<c<<endl;
	cout<<"Le module est : "<<c.Module()<<endl;
	cout<<"Le conjugue est : ";
	cout<<c.Conjugue()<<endl;
	cout<<"veuillez saisir le d"<<endl;
	cin>>d;
	if(c!=d)
	cout<<"Ces deux nombres complexes  sont different !"<<endl;
	else cout<<"c'est deux nombres sont differents !"<<endl;
	cout<<"Leur somme est : ";
	cout<<c+d<<endl;
	cout<<"Leur produit est : ";
	cout<<c*d<<endl;
	cout<<c<<" et "<<d<<endl;
	return 0;
}
