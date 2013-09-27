#include <iostream>

using namespace std; //référentiel lexical : contient ttes les méthodes de la classe std.

void affichage(int nb, int base);

int main(){
	
	int nombre;
	int base;
	
	cout<<"Veuillez entre un nombre" <<endl;
	cin>>nombre;
	
	cout << "Quelle base d'affichage pour ce nombre ?\n(1) décimal\n(2) hexadécimal\n(3) octal\n";
	cin>>base;
	
	affichage(nombre, base);
}

void affichage(int nb, int base){
	switch(base){
		case 1:
			nb=(float)nb;
			cout << "En base décimale, le nombre vaut " <<nb <<endl;
			break;
		case 2:
			cout << "En base hexa, le nombre vaut " <<hex <<nb <<endl;
			break;
		case 3:
			cout << "En base octale, le nombre vaut " <<oct <<nb <<endl;
			break;
		default:
			cout << "La base est incorrecte" <<endl;
	}
}
