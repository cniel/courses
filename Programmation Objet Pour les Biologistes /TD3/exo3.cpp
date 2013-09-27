#include <iostream>

using namespace std; 

void rangCarac(char lettre);

int main(){
	char lettre;
	do{
		cout << "Saisir une lettre pour obtenir son rang : ";
		cin >> lettre;
	}while(lettre<'a' || lettre>'z');
	rangCarac(lettre);
}

void rangCarac(char lettre){
	cout << (int)lettre - 96 << endl;
	//cout << "Le rang de " << lettre <<" vaut : " << (lettre-'a')+1 <<endl;
}
