void initMat(TMatr* adr_mat, int nbMaxRows, int nbMaxCols, double valDef);

TPRow allouerMemoire();
TPCol allouerMeuuuhmoire();

void creation_case_affectation1(TMatr* adr_mat, TPRow* adr_p_prec, int i, int j, double val);
void creation_case_affectation2(TPRow* adr_ptr_lig_i, TPCol* adr_p_j_prec, int j, double val){

void recherche_col(TPCol headCols, TPCol* adr_Col, TPCol* adr_ColPrec);

void recherche(TMatr mat, int i, int j, TPRow* adr_Row, TPRow* adr_RowPrec, TPCol* adr_Col, TPCol* adr_ColPrec);
/*postCondition:
si *adr_pRow = NULL   :  la ligne i n'est pas présente dans la structure.
si ________ != NULL   :  _________ est présente.

si *adr_pCol = NULL   :  la colonne j n'est pas présente dans la liste des colonnes pointées par la ligne i.
si *adr_pCol != NULL  :  la colonne j est présente.

si *adr_pRowPrec != NULL : valeur particulière.
si *adr_pColPrec != NULL : valeur particulière.
*/

void set(TMatr* adr_mat, int i, int j, double val); //mat[i][j] = val;

/*
ANALYSE de la fonction set:

	SI on remplace une valeur par défaut par une valeur par défaut, ALORS il n'y a rien à faire. 		//1.1
	SI on remplace la valeur par défaut par une particulière, ALORS il faut faire de la création :		//1.2
	-peut-être créer une cellule ligne (la ligne i si elle n'existe pas).
	-créer une cellule colonne (la colonne j).
	
	SI on remplace une valeur particulière par la valeur par défaut, ALORS il faut faire de la destruction :	//2.1
	-supprimer la cellule
	-et peut-être aussi sauter sa ligne si c'était sa dernière cellule.
	
	SI on remplace une valeur particulière par une valeur particulière, ALORS il faut faire de la mise à jour. 	//2.2
	
	
C'est pas de la bonne prog d'avoir une fonction qui fasse un return ET qui ait des paramètres par adresse.
*/
