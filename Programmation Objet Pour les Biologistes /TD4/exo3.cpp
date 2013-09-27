#include <iostream>

using namespace std; 

void lecture(int resultat[], int);
int compteCorrects(int*, int*);

int main(){
	int num;
	int* resultat = new int[6];
	bool pasOk;
	
	for(int i=0; i<6;i++){
		do{
			cout<<"Saisir numéro " <<i+1 <<" : " <<endl;
			cin >> num;
			pasOk = (num<1 || num>49);
			if(pasOk)
				cout << "Numéro invalide" << endl;
		}while(pasOk);
		resultat[i]=num;
	}	
	lecture(resultat, 6);
}

void lecture(int* resultat, int taille){
	for(int j=0; j<taille;j++){
		cout << resultat[j] <<endl;
	}
}

int compteCorrects(int *t1, int *t2){
	int compt=0;
	for(int i=0;i<6;i++){
		for(int j=0; j<6; j++){
			if(t1[i]==t2[j])
				compt++;
		}
	}
	return compt;
}

int* stockeCorrects(int n, int* t1, int* t2){
	int* tabC=new int[n];
	int index=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(t1[i]==t2[j]){
				tabC[index]=t1[i];
				index++;
			}
		}
	}
}
