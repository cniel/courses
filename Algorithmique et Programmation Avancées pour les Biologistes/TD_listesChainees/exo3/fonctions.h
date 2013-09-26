

void initMat(TMatr* adr_mat, int pnbMaxRows, int pnbMaxCols, double pvalDef);

void set(TMatr* adr_mat, int i, int j, double val); //mat[i][j] = val;
/*
ANALYSE de la fonction set:

	SI on remplace une valeur par défaut par une valeur par défaut, ALORS il n'y a rien à faire.
	
	SI on remplace une valeur particulière par la valeur par défaut, ALORS il faut faire de la destruction :
	-supprimer la cellule
	-et peut-être aussi sauter sa ligne si c'était sa dernière cellule.
	
	SI on remplace la valeur par défaut par une particulière, ALORS il faut faire de la création :
	-peut-être créer une cellule ligne.
	-créer une cellule colonne.

pointeur courant et pointeur précédent : 2 pour les lignes, 2 pour les colonnes.

c'est pas de la bonne prog d'avoir une fonction qui fasse un return ET qui ait des paramètres par adresse.
*/

void recherche(TMatr adr_mat, int i, int j, TPRow* adr_pRow, TPRow* adr_pRowprec, TPCol* adr_pCol, TPCol* adr_pColPrec);
/*postCondition:
si *adr_pRow = NULL   :  la ligne i n'est pas présente dans la structure.
si ________ != NULL   :  _________ est présente.

si *adr_pCol = NULL   :  la colonne j n'est pas présente dans la liste des colonnes pointées par la ligne i.
si *adr_pCol != NULL  :  la colonne j est présente.

si *adr_pRowPrec != NULL : valeur particulière.
si *adr_pColPrec != NULL : valeur particulière.
*/
