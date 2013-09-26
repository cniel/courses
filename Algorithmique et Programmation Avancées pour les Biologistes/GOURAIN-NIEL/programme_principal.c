#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"prototypes.h"


#define taille 52

int main(){

	
	srand(time(NULL));
	
	int encore=0;
	int choixmodif=2;
	int choixaffich=0;
	int affichH=0;
	int action=0;
	
	int nbCell=0;
	int iteration=0, iMax=0;
	int ageMature=0, ageMax=0;
	float beta=0, delta=0;
	CELLULE* P[taille][taille];
	initMat(P);
	bordure(P);
	H* matH=Allouematrice();
	
	printf("Ce programme permet de modéliser l'évolution d'une culture cellulaire.\nIl prend en compte l'âge de maturité des cellules, c'est à dire l'âge à partir duquel les cellules peuvent se diviser.\nLe programme gère également l'espérance de vie des cellules et le nombre initial de cellules en culture.\nLe nombre d'itérations est à relier au temps nécessaire à une cellule pour se diviser.\nLors d'une itération, la cellule peut également se transformer en cellule cancéreuse, mourir.\n\n");
	
	do{
		printf("Souhaitez vous utiliser les paramètres par défaut:\nAge de maturité=3\nAge maximum=1001\nNombre de cellules initiales=100\nNombre maximal d'itérations=1000\nbeta=0.5\ndelta=0.8\n\n[1]Oui [2]Non\n");
		do{
			scanf("%d", &choixmodif);
			if(choixmodif==1){
				ageMature=3;
				ageMax= 1001;
				nbCell= 100;
				iMax= 1000;
				beta= 0.5;
				delta= 0.8;
			}else if(choixmodif==2){
				printf("Age de maturité (par défaut 3): "); scanf("%d", &ageMature);
				printf("Age maximum (par défaut 1001): "); scanf("%d", &ageMax);
				printf("Nombre de cellules initiales (par défaut 100): "); scanf("%d", &nbCell);
				printf("Nombre maximal d'itérations (par défaut 1000): "); scanf("%d", &iMax);
				printf("beta (par défaut 0.5): "); scanf("%f", &beta);
				printf("delta (par défaut 0.8): "); scanf("%f", &delta);
	 		 }else printf("Erreur de saisie...\nLes choix sont:\n[1]paramètres par défault\n[2]Modifier les paramètres\n");
	 	}while(choixmodif!=1 && choixmodif!=2);
		do{
			initPosition(nbCell, P, matH, iteration);
			chgmtType(beta, ageMax, P, matH, iteration);
			comptVoisines(P);
			printf("\nVoici la disposition des cellules à l'état initial (avant la première itération)\n");
			afficheMat(P, iteration);
			printf("\n");
			
			do{
				printf("Souhaitez-vous afficher l'état de la matrice à chaque itération? [1]Oui [2]Non\n");
				scanf("%d", &choixaffich);
				if(choixaffich!=1 && choixaffich!=2) printf("Erreur de saisie...\n");
			}while(choixaffich!=1 && choixaffich!=2);
		
			while(iteration<iMax)
			{
				iteration++;
				incrementeAge(ageMax, P, matH, iteration);
				
				tuer_f_nbVoisines(P, matH, iteration);
				tuer_f_Cancer(delta, P, matH, iteration);
				chgmtType(beta, ageMax, P, matH, iteration);
			
				divisions(ageMature, P, matH, iteration);

				comptVoisines(P);
				if(choixaffich==1){
					afficheMat(P, iteration);
					printf("\n");
				}
			 
			}			
			sauvegarde(matH);
			printf("Un fichier contenant l'historique de la matrice vient d'être créé.\nIl se trouve dans le répertertoire du programme principal.\n");
		
			printf("\nVoici l'état de la culture cellulaire à la fin de toutes les itérations.\n");
			afficheMat(P, iteration);
			printf("\n");
	
			do{
				printf("Souhaitez-vous afficher l'histoire d'une cellule? [1]Oui [2]Non\n");
				scanf("%d", &affichH);
				if(affichH!=1 && affichH!=2) printf("Erreur de saisie...\n");
			}while(affichH!=1 && affichH!=2);
			if(affichH==1) affichelistHCase(matH);
			
			do{
				printf("Souhaitez-vous relancer la modélisation en concervant ces paramètres? [1]Oui [2]Non\n");
				scanf("%d", &encore);
				if(encore!=1 && encore!=2) printf("Erreur de saisie...\n");
			}while(encore!=1 && encore!=2);
		}while(encore==1);
		
		do{
			printf("Souhaitez-vous [1]relancer une modélisation [2]quitter le programme ?\n");
			scanf("%d", &action);
			if(action!=1 && action!=2) printf("Erreur de saisie...\n");
		}while(action!=1 && action!=2);
	 }while(action==1);

printf("Au revoir.\n");
return 0;
}

