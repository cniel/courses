#include <stdlib.h>

#define taille 52

//Structures nécessaires___________________________________________________________________________

typedef enum norm_canc{
	normale=0,
	cancereuse=1
}TYPE;

typedef struct cel{
	TYPE type;
	int age;
	int nbVoisines;
}CELLULE;

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

//Prototypes des fonctions de gestion de la matrice principale______________________________________________

//Déclaration, initialisation et affichage de la matrice P
void initMat(CELLULE* (*P)[taille]);
void bordure(CELLULE* (*P)[taille]);
void afficheMat(CELLULE* (*P)[taille], int iteration);
void initPosition(int nbCell, CELLULE* (*P)[taille], H *matH, int iteration);
CELLULE *alloueCell();

//Comptage, vieillissement et division des cellules
void comptVoisines(CELLULE* (*P)[taille]);
void compttype(CELLULE* (*P)[taille]);
void incrementeAge(int ageMax, CELLULE* (*P)[taille], H *matH, int iteration);
void divisions(int ageMature,CELLULE* (*P)[taille], H *matH, int iteration);

//Mort des cellules selon le nombre de voisines et leurs type et changement de type d'une cellule
void tuer_f_nbVoisines(CELLULE* (*P)[taille], H *matH, int iteration);
void chgmtType(float beta, int ageMax, CELLULE* (*P)[taille], H *matH, int iteration);
void tuer_f_Cancer(float delta, CELLULE* (*P)[taille], H *matH, int iteration);

int nbHasard();

//Prototypes des fonctions de gestion de l'historique_______________________________________________________

//hcase (objet de la liste chaînée traçant l'historique d'une case de la matrice P)
HCASE* AlloueHCase();
HCASE* DefHCase(HCASE *nouveau, EVENEMENT evIt, int iteration);

//matrice H (contenant les listes chaînées d'hcase) et insertion d'un hcase
H* Allouematrice();
void InsererHCase(H *matH, EVENEMENT evIt, int iteration, int i, int j);

//affichage de l'historique d'une case
void affichelistHCase(H *matH);

//sauvegarde
void sauvegarde(H *matH);




