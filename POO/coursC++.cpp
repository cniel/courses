26/09
/*
avantage du C++ : c'est compatible avec le C, on peut donc encapsuler des fonctions de programmes pré-existant en C, et "améliorer ces programmes" avec les pptés du C++


définition de variables plus souple.
Deux fonctions peuvent porter le meme nom, si elles ont des paramètres différents (surcharge).

new, delete : créer et supprimer des objets.

Ce n'est plus obligatoire de regrouper le variables en début de bloc.
La philosophie est d'encapsuler les structures comme les comportements.
*/

int main(){
	cout << "Ce début de programme principal est invalide en C mais est correct en C++.";
	int n=5;
	for(int i=0, i<5;i++) cout << "i= " << i <<"\n";
}

/*
Nouvelles possibilités d'entrées sorties //t au C .
notion de flot utilisée : cout cin
<< : écrire dans un flot.
>> : lire dans un flot.

l'utilisation des E/S spécifiques au C++ nécessite l'ajout de la biblio iostream.h

Le main n'est rien d'autre qu'une méthode de la classe 'programme principal'

Il y a des bizarreries : il faut encore parfois manipuler les pointeurs alors qu'on est censé être dans un langage de haut niveau...

Les méthodes d'une classe sont appelées fonctions membres.
Les attributs d'une classe sont appelées données membres.
Mais personne n'utilise vraiment cette terminologie... Il faut le savoir qd meme.
*/

//Déclaration d'une classe:
class nom_class
{
	private:
		//données membres et fonctions membres privées.
		// Seules les instances de cette classe ont la possibilité d'utiliser ces données.
	public:
		//données membres et fonctions membres publiques.		
};

/*
private et public sont des 'spécificateurs d'accès'.
Les spécificateurs d'accès peuvent apparaitre plsrs fois, ds n'importe quel ordre. C'est à éviter !

c++ permet de mettre public aux attributs -> c'est violer le principe d'encapsulation.
*/

//définition d'une fonction membre:
type_retour nom_classe::nom_fonction(arguments)
{
	//corps de la fonction.
}

//Attention, ça c'est la définition, ça ne se met pas dans le fichier où l'on définit les attributs de la class etc. À cet endroit, on ne met que les prototypes des fonctions membres.

//Quelque chose comme ça est possible:
void Point::initialise(abs, ord){
	x = abs;
	y = ord;
}
// Le compilateur comprend que x et y correspondent au attributs de la classe 'Point'.

/*Instancier une classe : 
NomClasse nomInstance;
Exemple : */
Point p1;

Point tab[10]; //tableau de 10 objets de classe Point.
Point* ptr; //Pointeur sur un objet de type Point.
/*On parle d'objet, des choses que l'être humain voit, et la on nous sert du pointeur...
On essaiera au maximum de ne pas s'encombrer avec cette gestion.*/
//Accès aux champs : comme les structures en C.
nom_objet.nom_donnée;
nom_objet.nom_fonction(args);
nom_pointeur->nom_donnée;
nom_pointeur->nom_fonction(args);

/*
On met la classe dans un fichier.
Dans un autre fichier, il y a le main. Il n'est là que pour assembler les morceaux de codes qui ont déjà été pensés auparavant.
*/

Point a,b; // on déclare deux point.
a.initialise(5,2);
/*
On s'adresse au point 'a' : on lui dit de s'initialiser.
Le programme va chercher la méthode dans la classe 'Point' (l'objet 'a', lui, n'a pas de méthode à proprement parler).
*/

//Affectation d'objets :
class Point
{
	int x; //qd rien n'est indiqué pour la portée des variables, elles sont privées par défaut.
	
	public :
	int y;
	...
};

Point a,b;
b = a;
//revient à écrire :
b.x = a.x;
b.y = a.y;

/*
Cependant, ça pose un pbm car x est privé donc on ne peut pas y accéder à l'extérieur de la classe point.
2 solutions suivant le contexte :
	- mettre cette affectation dans la classe Point.
	- rendre publique la variable x.
*/

/*
Notion de constructeur:
	C'est une méthode qui sert à initialiser un objet.
	Appelée automatiquement à chaque création de l'objet.

	Écrire son propre constructeur pour une prog propre.

	instancier la classe Point : 
	réserver l'espace mémoire pour cet objet (pr ts les attributs...)
	Des valeurs par défaut sont également attribuées. C'est le role du constructeur.
	
	Il porte le mm nom que la classe

Destructeur:
	Garbage collector. Rendre l'espace propre une fois qu'on ne se sert plus de l'objet.
	Le mm nom que la classe, précédé de ~.

Grâce à la surcharge, une classe peut avoir autant de constructeurs qu'on le souhaite.
*/

/*
Variable de classe : 
	commune à l'ensemble des intances de cette classe.
	Elles sont déclarées de la façon suivante :
*/
class nomClasse{
	static int n;  //variable de classe
	float x; //variable d'instance
	...
};

/* Initialisation de var. de classe :
	- ne se fait aps dans un constructeur.
	- se fait en dehors de toute méthode.
	- La modif de sa valeur s'applique à toutes les instances de cette classe.
*/

//Exemple avec la classe pile (~25min)

/*Rapport avec l'entreprise : séparation en 2 fichiers : 
	- la Classe, les prototypes de ses méthodes et les attributs: c'est le fichier Spec. 
	  Très utile dans le rapport avec l'entreprise (en termes de délai et de coût).
	
	- le corps des méthodes. C'est le 'Code'.
*/


// LES PROPRIÉTÉS DES FONCTIONS MEMBRES

/*Surdéfinition
	Différentes méthodes, avec un meme nom mais des arguments différents (i.e. surcharge)
	exemple en diapos 96-97 : c'est pas de l'appel récursif, c'est juste un appel à une autre fonction portant le mm nom (mais ayant des param différents).

	- Rédéfinition d'une même méthode: on garde le mm nom, les mm arguments, mais on change le corps.
	- Surdéfinition : on garde le mm nom, mais on change les arguments et le corps.
*/

/*Fonctions membres en ligne:
	- svt utilisé pour les accesseurs, modifiers, constructeurs, destructeurs : c'est qqchose qui fait qd meme partie de la spec quand on y pense.
	- utiliser le mot clé inline si on la met dans le mm fichier Spec, mais après la classe. Sinon on peut aussi la mettre dans la classe. (voir exemples diapos 101 et 102).
*/


/*Exercice: 
	Définir une classe Fenêtre (au sens informatique), pr qu'on puisse manipuler celle-ci.
*/

//###########  Fenetre.h #############
class Fenetre
{
	private:
		int x;
		int y;
		int largeur;
		int hauteur;		
		
		static int nbInstances;
		
	public:
		//Constructors
		Fenetre();
		Fenetre(int px, int py);
		
		//Getters		
		float getLargeur();
		float getHauteur();
		float getnbPouces();
		
		//Setters
		void setLargeur(float pLargeur);
		void setHauteur(float pHauteur);
		void setnbPouces(float pnbPouces);
};

//Constructors
inline Fenetre::Fenetre() { x = 10; y = 10; largeur = 600; hauteur = 300; }
inline Fenetre::Fenetre(int px, int py) { x = px; y = py; largeur = 600; hauteur = 300; }

//Getters
inline Fenetre::getLargeur() { cout }

//Setters

03/09
//PARAMETRAGE

/* 3 modes de transmission d'objets en arguments à une fonction:
- par valeur.
- par adresse.
- par référence.
*/

class Point{
	int x, y;
	public:
	//...
	int coincide(Point);
};

int Point::coincide(Point pt){
	if((pt.x == x) && (pt.y == y)) return 1;
	else return 0;
}

/*
	si l'abscisse du point donné en paramètre est égale à l'abscisse de l'objet courant,
	alors les deux points sont identiques.
*/

main(){
	int egaux
	Point a(3,5), b(4,9);
	egaux = a.coincide(b); // ici, on regarde donc si b.x == a.x, puis b.y == a.y
}	
	
/*
	Ce mode de passage est peu recommandé.
	En effet, une copie locale du paramètre est réalisée lors de l'appel.
	Il peut y avoir des pbms si certaines données de l'objet sont des pointeurs.
*/

class Point{
	int x, y;
	public:
	//...
	int coincide(Point*);
};

int Point::coincide(Point* ptr){
	if((ptr->x == x) && (ptr->y == y)) return 1;
	else return 0;
}

main(){
	int egaux
	Point a(3,5), b(4,9);
	egaux = a.coincide(&b); // ici, on regarde donc si b.x == a.x, puis b.y == a.y
}

/*
	Le passage par adresse.
	C'est plus difficile à utiliser.
	Ça colle pas avec la philosophie objet.

	Il reste la transmission par référence:
	C'est une transmission par adresse, prise en charge par le compilateur.
*/

class Point{
	int x, y;
	public:
	//...
	int coincide(Point&);
};

int Point::coincide(Point& pt){
	if((pt.x == x) && (pt.y == y)) return 1;
	else return 0;
}

main(){
	int egaux
	Point a(3,5), b(4,9);
	egaux = a.coincide(b); // ici, on regarde donc si b.x == a.x, puis b.y == a.y
}

//C'est bcp plus proche de la philosophie objet.

/* le mot clé "this" :
   c'est juste pour être sûr qu'on travaille bien sur l'objet courant.
*/

void Point::affiche(){
	cout << "Adresse : " << this;  //donne l'adresse de l'objet courant.
}

/*
méthode affiche écrite au niveau de la classe point:
	on met juste les coordonnées x et y.
	on prend un point a.
	a.afficher().
	la méthode affiche les coordonnées du point a.
	
Dans le cas d'une méthode de classe:
	les instructions porteront sur les variables statiques de classe.	
*/

//Exemple:
class Exemple{
	static int ctr;
	
	public:
	Exemple();
	~Exemple();
	static void compte(); // déclaration d'une méthode de classe avec le mt clé static.
};

int Exemple::ctr = 0;  // initialisation du membre statique.

Exemple::Exemple(){
	cout << "Construction. Il y a maintenant " << ctr++ <<" objets.\n";
}

Exemple::~Exemple(){
	cout << "Destruction. Il y a maintenant " << --ctr << " objets.\n";
}

void Exemple::compte(){
	cout << "Compte affiche qu'il y a " << ctr <<" objets.\n";
}

/*
	A chaque fois qu'on appelle le constructeur, le compteur (variable de classe) est incrémenté.
	Quand on appelle le destructeur : ce compteur est décrémenté.	
*/

void fct(){
	Exemple x,y;
}

main(){
	Exemple::compte(); //pour une fois, on appelle une méthode sans objet apparenté -> on doit préciser la classe correspondante.
	Exemple a;
	Exemple b;
	fct();
	/*
		anvant de sortir de fct(), il y a 4 objets.
		après être sorti de fct(), il reste 2 objets. (en sortie de bloc, le destructeur est automatiquement appelé).
	*/ 
}

// on peut faire une déclaration d'un objet qui sera constant par la suite:
const Point a;
// Ses valeurs ne pourront pas changer par la suite.


//Objets automatiques et statiques
/* 
   Objet automatique:
	Est créé lors de la rencontre de sa déclaration, dans une fonctions ou dans un bloc (l'objet est détruit lors de la sortie du bloc).

   Objet statique:
   	Est créé en dehors de toute fonction,
	Ou dans une fonction, mais précédé du mot clé static.
*/

//Objets dynamiques:
/*
	Mots clés new et delete
*/

de façon équivalente, on peut écrire:
	Point *adr;
	(*adr).initialise(1,3);
	(*adr).affiche();
	
	delete adr //suppression
	
	En mode dynamique trop IN:
	Point* adr = new Point(1,3); //on déclare le pointeur, et on déclenche le constructeur qui a deux arguements.
	adr->affiche();
	Point* adr2 = new Point; // on déclare le pointeur, et on déclenche le constructeur qui n'a pas d'arguments.
	adr2->affiche();
	
Notions de copie superficielle et de copie profonde (une copie physique).
Pour effectuer une copie profonde:
il faut un constructeur de recopie. Si on en met pas, le complilateur en met un automatiquement, et il sera superficiel.

// copie effective (en profondeur):
Chaine::Chaine(const Chaine& C){
	D = new char[C.Taille] : Taille = C.Taille;
	for (int i=0; i<Taille; i++) D[i]=C.D[i];
}

Pour un objet englobant un autre objet (dans ses attributs), il faut spécifier les arguments qui vont être spécifiés lors de la construction de ce 'sous-objet'.


class Point{
	identifie()
};

class Pointcol :: Point{
	identifie()
};

-> appel croisé :
dans identifie() de pointcol, on appelle identifie() de la classe point.

main(){
	Point *a = new Point;
	Point *b = new Pointcol;
}

la virtualité : utiliser dès qu'il y a polymorhisme.

un constructeur ne peut pas être virtuel !
une méthode virtuelle peut être redéfinie, surchargée (sans que ça soit en virtuel aussi).

template <class T> class Point
{
	T x;
	T y;
	
	public:
	Point(T abs=0, T ord=0);
	void affiche();
}

Utilisation:
Point<int> pt1; -> définit deux entiers x et y
Point<Point> pt2; -> définit deux points x et y

C'est une 'méta-classe'

template <class T, int n> class Tableau
{
	T tab[n];
	
	
}
