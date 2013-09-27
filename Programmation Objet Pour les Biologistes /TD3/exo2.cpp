#include <iostream>

using namespace std; 

void saisieDonnees(int&, int&, int&, int&);
void conversion(int ,int, int, int);

int main(){
	int sensConversion;
	int borne1, borne2;
	int pas;
	
	saisieDonnees(sensConversion, borne1, borne2, pas);
	conversion(sensConversion, borne1, borne2, pas);
}

void saisieDonnees(int& sensConversion, int& borne1, int& borne2, int& pas){
	do{
		cout << "Sens de conversion : \n(1)°C -> °F\n(2)°F -> °C" <<endl;
		cin >> sensConversion;
	}while(sensConversion!=1 && sensConversion!=2);
	
	cout << "Borne inférieure : ";
	cin >> borne1;
	do{
		cout << "Borne supérieure : ";
		cin >> borne2;
		if(borne1>=borne2)
			cout<<"Borne supérieure invalide." <<endl;
	}while(borne1>=borne2);
	
	cout << "Quel est le pas ?";
	cin >> pas;
}

void conversion(int sensConversion, int borne1, int borne2, int pas){
	int degRetour;
	
	if(sensConversion==1){
		for(int deg=borne1; deg<=borne2; deg+=pas){  //déclaration à la volée possible
			degRetour = (int)deg*(9./5.)+32;
			cout << "T = " << deg <<"°C\t => T = " << degRetour << "°F" <<endl;
		}
	}else{
		for(int deg=borne1; deg<=borne2; deg+=pas){  //déclaration à la volée possible
			degRetour = (int)((5./9.)*(deg-32));
			cout << "T = " << deg <<"°F\t => T = " << degRetour << "°C" <<endl;
		}
	}	
}
