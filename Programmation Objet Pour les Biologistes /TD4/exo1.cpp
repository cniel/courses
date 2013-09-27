#include <iostream>

using namespace std; 

//1 octet = 1 byte = 8 bit 

//1 char = 1 octet -> plage valeurs: -128 à 127 (-2puiss7 à 2puiss7 - 1) puiss7 car c'est 8 bits.

//1 int = 4octets  -> plage valeurs: -2puiss31 à 2puiss31 - 1)
//1 short int = 2 octets -> plage valeurs: -32 768 à 32 767
//long int = 8 octets

//1 float = 4 octets
//1 double = 8 octets

int main(){

	int i=0; //4 octets.
	char *s = "Bonjour à tous !"; //16 caractères + le \0 -> 17 octets
	double matrice[3][3]; // 3*3*8 octets -> 72 octets
	char temp[256]; //256 octets

	T *p = new T;
	//...
	delete p;

	//passage par valeurs et par adresses (comme en C), et par références en C++.
}
