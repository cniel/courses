#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

typedef int TInfo;

typedef struct{
	TInfo info;
	struct TCell *next;
}TCell;

typedef TCell* TPointeur;

void parcoursListe(TPointeur tete);
TPointeur creer_cell(TInfo val);
void accesPos(TPointeur liste, int k, TPointeur ptrCell, bool* trouve);
void ajoutTete(TPointeur* tete, TInfo val);
void ajoutTri(TPointeur* adr_tete, TInfo val);
void InsertTri(TPointeur* adr_tete, TInfo val);
//void ajoutQueue(TPointeur* adr_tete, TInfo val);

int main(){
	
	TPointeur liste = NULL;
	
	ajoutTri(&liste, 15);
	ajoutTri(&liste, 2);
	ajoutTri(&liste, 30);
	ajoutTri(&liste, 58);
	ajoutTri(&liste, 6);
	
	parcoursListe(liste);
	
	return 0;	
}

TPointeur creer_cell(TInfo val){
	TPointeur ptr;
	ptr = (TCell*)malloc(sizeof(TCell)); //il faut pas oublier le struct en C
	if(ptr == NULL){
		printf("Plus d'espace mémoire.\n");
		exit(1);
	}
	ptr->info = val;
	ptr->next = NULL;
	
	return ptr;
}

void ajoutTete(TPointeur* adr_tete, TInfo val){ //Un pointeur de TPointeur en paramètre car sa valeur va changer -> on le passe par adresse.
	TPointeur new = NULL;
	new = creer_cell(val); //pas besoin de free car c'est une variable locale -> supprimée à la fin de la procédure
	new->next = *adr_tete;
	adr_tete = new;
}

/*
void ajoutQueue(TPointeur* adr_tete, TInfo val){
	TPointeur new = creer_cell(val);
	TPointeur temp = *adr_tete;
	if(temp == NULL) adr_tete=new;
	else{
		while(temp != NULL){
			temp = temp->next;
		}
		temp = new;
	}
}
*/

void ajoutTri(TPointeur* adr_tete, TInfo val){
	TPointeur temp = NULL;
	TPointeur memoire = NULL;
	TPointeur new = creer_cell(val);
	temp = *adr_tete;
	
	if(*adr_tete == NULL)  //liste vide
		ajoutTete(adr_tete, new->info);
	
	else{ 
		while((temp != NULL) && (temp->info >= new->info)){
		//Si on a un "||" dans un while, c'est très louche!!!  D'autre part, inverser les deux parties du while dans ce cas peut faire crier le compilateur.
			memoire = temp;
			temp = temp->next;
		}
		
		if(memoire == NULL)
			ajoutTete(adr_tete, val);
		else
			ajoutTete(&memoire->next, val);
	}
}

//CORRECTION DEVELOPPEZ
void InsertTri(TPointeur* adr_tete, TInfo val){
	TPointeur memoire = NULL;
	TPointeur temp = *adr_tete;
	TPointeur new = creer_cell(val);
        
	while((temp != NULL) && (temp->info < val)){
		memoire = temp;
		temp = temp->next;
	}
	new->next = temp;
	if(memoire != NULL) 
		memoire->next = new;
	else 
		*adr_tete=new;
}


void parcoursListe(TPointeur tete){
	TPointeur ptr = tete;
	while(ptr != NULL){
		printf("%d\n", ptr->info);
		ptr = ptr->next;
	}
}	//n'affiche rien si la liste est vide.

void accesPos(TPointeur liste, int k, TPointeur ptrCell, bool* trouve){
	int i = 0;
	ptrCell = liste;
	
	for(i=0;i<k;i++){
		ptrCell = ptrCell->next;
		if(ptrCell == NULL) break;
	}
	if(ptrCell != NULL) *trouve = TRUE;
	else *trouve = FALSE;
}
