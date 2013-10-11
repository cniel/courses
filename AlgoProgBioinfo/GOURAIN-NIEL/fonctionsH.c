#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define taille 52

//Structures nécessaires________________________________________________________________________
typedef enum evenement{
	naissance=0,
	mort=1,
	transformation=2,
	division=3,
	rien=4
}EVENEMENT;

typedef struct HistoriqueCase{
	int numIt;
	EVENEMENT ev;
	struct HistoriqueCase *suivant;
}HCASE;

typedef struct matriceH{
	HCASE ***tab;
	int l;
	int c;
}H;

//Fonctions HCase_______________________________________________________________________________

//Allocation de l'espace mémoire d'HCASE
/*
Lors de l'allocation de mémoire d'HCASE, l'itération est 0 et l'évènement est 4, c'est à dire 'rien'.
Puisque chaque allocation est suivi de la définition du HCASE (numéro d'itération et type d'évènement associé), les listes chaînées d'HCASE ne contiendront jamais un HCASE ayant un numéro d'itération nul et un évènement égal à 'rien'.
*/
HCASE* AlloueHCase(){
	/* Déclaration et allocation de mémoire d'un poiteur de type HCASE */
	HCASE *h=(HCASE*)malloc(sizeof(HCASE));
	
	/* Message d'erreur d'allocation ou initialisation */
	if(h==NULL){
		printf("PB de mémoire.");
	}else{
		h->numIt=0;
		h->ev=4;
		h->suivant=NULL;
	 }
return h;
}

//Définition d'un nouveau hcase selon l'évènement
HCASE* DefHCase(HCASE *nouveau, EVENEMENT evIt, int iteration){
	
	nouveau->numIt=iteration;
	nouveau->ev=evIt;
	nouveau->suivant=NULL;
	
return nouveau;
}

//Fonctions de la matrice H____________________________________________________________________________________________________________

//Allocation de la mémoire de H
H* Allouematrice(){
	int i=0, j=0;
	
	/* Définition et allocation d'un poiteur de type H */
	H *matH=(H*)malloc(sizeof(H));
	if(matH==NULL){
	printf("PB Mémoire");
	}else{
		/* Déclaration du pointeur du type H (tab) et allocation de son espace mémoire de la taille d'un pointeur de type HCASE */
		matH->tab = (HCASE***) malloc(sizeof(HCASE)*(taille*taille));
		/* Déclaration et initialisation des autres éléments de la stucture de type H */
		matH->l=taille;
		matH->c=taille;
		
		/* Allocation de l'espace mémoire de chaque ligne de tab */
		for(i=0; i<taille; i++) {
			matH->tab[i] = malloc(sizeof(HCASE)*taille);
		    	/* Allocation de l'espace mémoire de chaque élément de chaque ligne de tab */
		    	for(j=0; j<taille; j++) { 
				matH->tab[i][j] = malloc(sizeof(HCASE)*taille);
			}
		}
		for(i=0; i<taille; i++){
			for(j=0; j<taille; j++){
			matH->tab[i][j]->numIt=0;
			matH->tab[i][j]->ev=4;
			matH->tab[i][j]->suivant=NULL;
			}
		
		}
	 }
return matH;
}

//Ajout d'un évènement
/*
A appeler à chaque évènement en précisant la position dans la matrice P et donc la position du nouveau hcase (i et j).
*/
void InsererHCase(H *matH, EVENEMENT evIt, int iteration, int i, int j){
	/* Allocation de l'espace mémoire du nouvel hcase */
	HCASE *nouveauindef=AlloueHCase();
	
	/* Définition du numéro d'itération et du type d'évènement */
	HCASE *nouveaudef=DefHCase(nouveauindef, evIt, iteration);
	
	/* Insertion du nouvel hcase*/
	HCASE *actuel=matH->tab[i][j];
	while(actuel->suivant!=NULL){
		actuel=actuel->suivant;
	}
	actuel->suivant = nouveaudef;
}

//Fonction de sauvegarde_____________________________________________________________________________________________________
/*
ATTENTION : lors de l'appel de la fonction sauvegarde, entrer en paramètre matH->tab[0][0]
*/
void sauvegarde(H *matH){
	
	HCASE *actuel;
	FILE *f;
	char nom_fichier[]="historique";
	EVENEMENT evenement;
	int i=0, j=0, lcase=0, ccase=0, num=0;

	/* Ouverture du fichier historique.txt en mode écriture */
	f = fopen(nom_fichier, "w+");
	
	/* Parcours de la matrice */
	for(i=1; i<taille-1; i++){
		for(j=1; j<taille-1; j++){
			actuel=matH->tab[i][j];
			/* Insertion : du numéro de ligne puis de colonne ... */
			lcase=i;
			ccase=j;
			fprintf(f, "	%d-%d\n", lcase, ccase);
			do{
				evenement = actuel->ev;
				num = actuel->numIt;
				/* ...du numéro d'itération... */	
				fprintf(f, "|%d|", num);
				/* ...et de l'évènement*/
				switch(evenement){
					case 0 : fprintf(f, " naissance\n");break;
					case 1 : fprintf(f, " mort\n");break;
					case 2 : fprintf(f, " transformation\n");break;
					case 3 : fprintf(f, " division\n");break;
					case 4 : fprintf(f, "  \n");break;
					default : fprintf(f, " problème de reconnaissance d'évènement\n");
				}
				if(actuel->suivant!=NULL){actuel=actuel->suivant;}		
			}while(actuel->suivant!=NULL);
		}
	}
	fclose(f);
}

//Affichage d'une liste chainée d'hcase_________________________________________________________________________________________________

void affichelistHCase(H *matH){

	int la=0, ca=0;	
	
	/* Choix de la case de la matrice P dont l'utilisateur souhaite afficher l'historique */
	printf("De quelle cellule souhaitez-vous connaitre l'histoire?\nLigne : ");
	scanf("%d", &la);
	printf("Colonne : ");
	scanf("%d", &ca);

	HCASE *actuel=matH->tab[la][ca];
	EVENEMENT evenement;
	
	// ...affichage par double ligne du numéro d'itération et de l'évènement correspondant...
	do{
		printf("Itération n°%d.\n", actuel->numIt);
		evenement=actuel->ev;
		switch(evenement){
			case 0 : printf("Evènement : naissance.\n\n");break;
			case 1 : printf("Evènement : mort.\n\n");break;
			case 2 : printf("Evènement : transformation.\n\n");break;
			case 3 : printf("Evènement : division.\n\n");break;
			case 4 : printf("Evènement : rien.\n\n");break;
			default : printf("Problème de reconnaissance d'évènement.\n\n");
		}
		// ...jusqu'au dernier historique de la case 
		if(actuel->suivant!=NULL){actuel=actuel->suivant;}
	}while(actuel->suivant!=NULL);
}  

	


