ALLOCATION DYNAMIQUE

char s1[21]; //allocation statique
strcpy(s, "blabliblu"); //de type pointeur sur type caractère

s1 est équivalent à &s1[0] : c'est de type char*.

char* s1;
s1 = (char*)malloc(sizeof(char)*21)  //le 1er char* est une conversion de type.
strcpy(s1, "blabliblu");
free(s1); //Les  21 cases sont libérées directement. Pas besoin de faire tourner une boucle pour chaque case.



double r=12.2;
int i;
i = (int)r;  //C'est la conversion de type, ou le cast



char* s1;
strcpy(s1, "titi"); //Est-ce que ça pose un problème au compilateur
/*
	Pas forcément mais on rentre ces valeurs dans des zones mémoires qu'on ne contrôle pas.
	Si jamais l'espace mémoire pris au hasard est déjà de la mémoire réservée à un entier, la valeur de l'entier va donc changer.
*/


int i;
char** t;
t = (char**)malloc(sizeof(char*)*10);
/*
	C'est un tableau de pointeurs vers des chaines de caractères.
	Il faut alors faire l'allocation dynamique pour faire par exemple une matrice 10x200
*/
for(i=0;i<10;i++){
	t[i] = (char*)malloc(sizeof(char)*200);  //la left value peut aussi être *(t+i)
	strcpy(t[i],"titi");
}
//On voit ici qu'il y a un gros gaspillage de mémoire

RÉSERVATION DE MÉMOIRE AU PLUS EXACT :
char *s;
s = (char*)malloc(sizeof(char)*(strlen(s1)+1));  //s1 est connu par ailleurs  le "+1" c'est pour le \0
strcpy(s,s1);

//Si on a un s3 de taille 1000, et qu'on veut le copier dans s1 : il faut d'abord faire un free sur s1, puis refaire un malloc.

//Libérer la mémoire de la matrice créée précédemment :
// Comme il y avait deux niveaux de malloc, il faut free chaque niveau.
for(i=0; i<10; i++){
	free(t[i]);
}
free(t);


// _________________________________________________________________________

TypePersonne ta_mere;
TypePersonne ton_pere;
TypePersonne personne;

strcpy(ta_mere.nom, "momy");
ta_mere.mere = NULL;
ta_mere.pere = NULL;

strcpy(ton_pere.nom, "sista");
ton_pere.mere = NULL;
ton_pere.pere = NULL;

strcpy(personne.nom, "Stalone");
personne.mere = &ta_mere;
personne.pere = &ton_pere;

// _________________________________________________________________________

TypePersonne* adr_pers;
adr_pers = &ta_mere;
printf("...%s\n", ta_mere.nom);
printf("...%s\n", adr_pers->nom); //est un équivalent

STRUCTURE ET POINTEUR : LE TYPE ARBRE BINAIRE
la racine en haut et les feuilles en bas.
Chaque noeud possède au plus deux enfants (0, 1 ou 2).
Ceux qui en ont 0 s'appellent les feuilles.

// C'est un peu un cas général des listes chainées (il y a 2 successeurs ici).
typedef struct TypeNoeud{
	int valeur;
	struct TypeNoeud* fg; //fils_gauche
	struct TypeNoeud* fd; //fils_droit
}

//Fonction allouerNoeud.
/*
	Il vaut mieux déporter les malloc dans des fonctions,
	car si on transcrit le programme dans un langage qui utilise 
	pas malloc, c'est plus simple de le changer.
*/

TypeNoeud* allouerNoeud(){
	return (TypeNoeud*)malloc(sizeof(TypeNoeud)); //C'est une fonction qui alloue une case mémoire. Selon les compilateurs, il peut y a voir besoin de struct devant TypeNoeud.
}

TypeNoeud* p_noeud;
p_noeud = allouerNoeud();



LES FONCTIONS
//Emplacement :
Emplacement avant le main, déclaration avant l'appel.

//Définition :
Définition_fonction ::= type identificateur([paramètres]) liste_instructions
paramètres ::= paramètre[, paramètre]*      l'étoile indique 0, 1 ou plusieurs répétitions.

//Déclaration :
Déclaration_fonction ::= type identificateur([paramètres]);
/*
	Si f1 fait appel à f2, il faut impérativement avoir la déclaration de f2 avant.
	C'est la récursivité croisée.
*/



AVEC OU SANS RETOUR
-> pseudo-code
-> fonction, procédure

void message(){
	printf("bliblablu\n");
}

int tirage_au_hasard(){
	int i = 456;
	return i;
}

MODALITÉS DE PASSAGES DE PARAMÈTRES
//pseudo-code : par entrée/sortie
es i:entier

//Équivalent au passage par adresse en C.
PROCÉDURE lire_clavier(s i:entier)
début
	i <- primitive_lire_clavier()  //la fonction scanf
fin

PROCÉDURE doubler_valeur(es i:entier)
début
	i <- i*2
fin

//Equivalent au passage par valeur en C
PROCÉDURE affichage(e i:entier)
début
	primitive_afficher_écran(i)    //la fonction printf
fin

//EN C, ça donne :

int i=3;
affichage(i); //Passage par valeur en pseudo-code et en C :
/*
	Une copie de la valeur de i est effectuée, et est placée dans le cadre d'appel de la procédure affichage.
	Donc même si on fait un calcul sur la valeur passée dans la procédure, i ne sera pas modifié dans le reste du programme.
*/

doubler(i)   //passage par adresse en pseudo-code 
doubler(&i); //passage par adresse en C :
/*
	Ici, le cadre d'appel de la fonction contient les adresses des paramètres passés.
	Dit autrement, il contient des pointeurs vers les paramètres.
*/

//Plus de détails sur la syntaxe C avec le passage par adresse:
//définition
void doubler(int* adr_i){  //attention à bien mettre un pointeur.
	*adr_i *= 2;
}

//appel
int i = 13;
doubler(&i);  //attention à bien passer l'adresse de i.



/*
Parfois, on peut avoir à passer par adresse, même si on ne veut pas modifier la variable:
	- un tableau : pas besoin du & car un tableau est déjà une adresse.
	- avec un const : si on passe un énorme structure composée de multiples sous-structures, ça évite que la mémoire soit saturée car il n'y a pas de copie à faire.
*/

//Autre exemple:
void fonction(int** p){   //ici, p est un paramètre formel.
	//*p : de type int*
}

int i=13;
int* k=&i;
fonction(&k);         //ici k est le paramètre effectif.







