#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

#define taille 52

//Structures nécessaires_______________________________________________________________________________
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

//Fonctions____________________________________________________________________________________________
//Déclare une cellule.
CELLULE* alloueCell() 
{
	CELLULE *p=(CELLULE*)malloc(sizeof(CELLULE));
	if(p==NULL) printf("PB de mémoire");
	else
	{
		p->type=0;
		p->age=0;
		p->nbVoisines=0;
	}
	return p;
}

//Initialise toutes les cases de le matrice P comme des pointeurs pointant sur NULL
void initMat(CELLULE* (*P)[taille]) 
{
	int l=0, c=0;
	
	for(l=0; l<taille; l++)
	{
		for(c=0; c<taille; c++)
		{
			P[l][c]=NULL;
		}
	}
}

//définit les bordures de la matrice comme étant des cellules initialisés à 0 (type, age, nbVoisines)
void bordure(CELLULE* (*P)[taille]) 
{
	int l=0, c=0;
	for(c=0; c<taille; c++)
	{
		P[0][c]=alloueCell();
		P[taille-1][c]=alloueCell();
	}
	for(l=0; l<=taille; l++)
	{
		P[l][0]=alloueCell();
		P[l][taille-1]=alloueCell();
	}
}

//initialise aléatoirement la position de chaque cellule
void initPosition(int nbCell, CELLULE* (*P)[taille], H *matH, int iteration) 
{
	int i=0, l=0, c=0;
	srand(time(NULL));
	for(i=0; i<nbCell; i++)
	{
		l=rand()%(taille-2)+1;
		c=rand()%(taille-2)+1;
		P[l][c]=alloueCell();
		InsererHCase(matH, 0, iteration, l, c);
	}
}

//compte chaque les deux types de cellules à chaque itération : "état des lieux"
void compttype(CELLULE* (*P)[taille]) 
{
	int l=0, c=0;
	int comptC=0, comptN=0;
	for(l=1; l<taille-1; l++)
	{
		for(c=1; c<taille-1; c++)
		{
			if(P[l][c]!=NULL){
				if(P[l][c]->type==0){
					comptN++;
				}else{
					comptC++;
				 }
			}
		}
	}
	printf("Il y a %d cellule(s) cancéreuse(s).\n", comptC);
	printf("Il y a %d cellule(s) normale(s).\n", comptN);
}

//gère l'affichage de la matrice de cellules
void afficheMat(CELLULE* (*P)[taille], int iteration) 
{
	int l=0, c=0;
	printf("Itération n°%d.\n", iteration);
	for(l=0; l<taille; l++)		//
	{				//Parcourir le tableau
		for(c=0; c<taille; c++) //
		{
			if(l==taille-1 || c==taille-1) printf(" "); //
			else if(l==0)				    //
			{					    //
				if(c<10) printf("%d ", c); 	    //
				else printf("%d",c);		    //
			}					    //bordures
			else if(c==0 && l!=0)			    //
			{					    //
				if(l<10) printf("%d ",l);	    //
				else printf("%d", l); 		    //
			}
			else if (P[l][c]==NULL) printf("  ");   //cases vides
			else if(P[l][c]->type==1) printf("* "); //cellules cancéreuses
			else printf("o "); // les autres : cellules normales.
		}
		printf("\n");
	}
	compttype(P);
	printf("\n");
}

//Compte le nombre de voisines de chaque cellule, et l'assigne dans la structure.
void comptVoisines(CELLULE* (*P)[taille])
{
	int compt=0, i=0, j=0, l=0, c=0;
	
	for(l=1; l<taille-1; l++)			//
	{						//on parcourt toutes les cases de P
		for(c=1; c<taille-1; c++)		//
		{
			if(P[l][c]!=NULL) //On ne prend en compte que les cases contenant des cellules
			{
				compt=0; //initialisation du compteur pour chaque cellule.
				for(i=-1; i<=1; i++)	     //
				{			     //on regarde l'entourage de la cellule actuelle
					for(j=-1; j<=1; j++) //
					{
						if(P[l+i][c+j]!=NULL)
						{
							if(i==0 && j==0) ;  
							else compt++; //On compte les voisines et pas la cellule elle-même.
						}
					}				
				}	
				P[l][c]->nbVoisines=compt; //on rentre le nombre de voisines dans la structure de la cellule.		
			}
		}
	}
}

//Incrémente l'âge de chaque cellule, et tue les celles qui sont trop vieilles. 
void incrementeAge(int ageMax, CELLULE* (*P)[taille], H *matH, int iteration)
{
	int l=0, c=0;
	for(l=1;l<taille-1;l++)
	{
		for(c=1;c<taille-1;c++)			
		{
			if(P[l][c]!=NULL) 
			{
				P[l][c]->age++; //la cellule vieillit à chaque cycle.
				if(P[l][c]->age>ageMax) 
				{
					P[l][c]=NULL; //si la cellule est trop agée, elle est réinitialisée.
					InsererHCase(matH, 1, iteration, l, c);
				}
			}	
		}
	}
}

void divisions(int ageMature,CELLULE* (*P)[taille], H *matH, int iteration)
{
	int l=0, c=0, i=0, j=0;
	
	for(l=1;l<taille-1;l++)
	{
		for(c=1;c<taille-1;c++)
		{
			if(P[l][c]!=NULL && P[l][c]->nbVoisines<4 && P[l][c]->age>ageMature) //critères de l'énoncé
			{
				do
				{
					i=nbHasard(); 
					j=nbHasard(); 			
				}while(P[l+i][c+j]!=NULL); //donne une case vide voisine de P[l][c] (la case d'intérêt actuelle)
				P[l+i][c+j]=alloueCell();  //déclaration de la cellule fille.
				P[l+i][c+j]->type=P[l][c]->type; //Le type de la fille est le même que celui de la cellule mère
				if(P[l][c]->age<10) P[l+i][c+j]->age=0; 
				else P[l+i][c+j]->age=P[l][c]->age-10; //La cellule fille est plus jeune que la mère.
				P[l+i][c+j]->nbVoisines=8;  //sert à ce que la cellule fille ne se divise pas dans le même cycle que celui où elle naît (dans le même appel de fonction), si elle est placée plus loin dans l'ordre de lecture de la matrice.
				P[l][c]->age+=5; //Le processus de division fait vieillir la cellule mère.
				InsererHCase(matH, 3, iteration, l, c); //entre l'évenement "division" dans l'historique.
				InsererHCase(matH, 0, iteration, l+i, c+j); //entre l'évenement "naissance" dans l'historique.
			}
		}
	}
}

//renvoie au hasard un entier entre -1 et 1
int nbHasard() 
{
	int x=0;
	
	x=rand()%100;
	if(x<=33) return -1;
	else if(x<=66) return 0;
	else return 1;	
}

//gère la mort des cellules normales en fonction de leur nombre de voisines
void tuer_f_nbVoisines(CELLULE* (*P)[taille], H *matH, int iteration) 
{
	int l=0, c=0;
	for(l=1; l<taille-1; l++)
	{
		for(c=1; c<taille-1; c++)
		{
			if(P[l][c]!=NULL && P[l][c]->type==0 && P[l][c]->nbVoisines>4) //La survie des cellules cancéreuses ne dépend pas du nombre de voisines (car proche de la réalité).
			{
				P[l][c]=NULL; //la cellule meurt
				InsererHCase(matH, 1, iteration, l, c); //insertion de l'évenement "mort" dans l'historique
			}
		}
	}
}

//gère le changement de type des cellules
void chgmtType(float beta, int ageMax, CELLULE* (*P)[taille], H *matH, int iteration)  
{
	int l=0, c=0;
	float probaCancer=0, chance=0;
	for(l=1; l<taille-1; l++)
	{
		for(c=1; c<taille-1; c++)
		{
			if(P[l][c]!=NULL && P[l][c]->type==0)
			{
				probaCancer=(P[l][c]->age)-ageMax;
				probaCancer=beta*exp(probaCancer); 
				probaCancer*=100; //proba de devenir cancéreuse en %
				chance=rand()%101;//nombre aléatoire entre 0 et 100
				if(chance<=probaCancer)
				{
					P[l][c]->type=1;
					InsererHCase(matH, 2, iteration, l, c); //insère l'évenement "transformation" dans l'historique
				}
			}
		}
	}
}

//gère la mort des cellules normales en fonction de la présence de voisines cancéreuses
void tuer_f_Cancer(float delta, CELLULE* (*P)[taille], H *matH, int iteration)
{
	int l=0, c=0, i=0, j=0, voisinesCancer=0, probaMourir=0, chance=0;
	
	for(l=1; l<taille-1; l++)
	{
		for(c=1; c<taille-1; c++)
		{
			voisinesCancer=0;
			if (P[l][c]!=NULL && P[l][c]->type==0)
			{
				for(i=-1; i<=1; i++)	     //
				{			     //on regarde l'entourage de la cellule actuelle
					for(j=-1; j<=1; j++) //
					{
						if(P[l+i][c+i]!=NULL && P[l+i][c+i]->type==1 && i!=0 && j!=0) voisinesCancer=1; //On regarde si'il y a des types 1 et on ne compte pas la cellule elle-même...
					}
				}
				if(voisinesCancer==1) //tuer la cellule au risque delta.
				{
					probaMourir=100*delta;
					chance=rand()%101;
					if(chance<=probaMourir)
					{
						P[l][c]=NULL;
						InsererHCase(matH, 1, iteration, l, c);
					}
				}
			}
		}
	}
}

