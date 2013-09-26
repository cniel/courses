typedef struct{
	int numCol;
	double val;  //contient la valeur intéressante
	struct TCellCol* next;
}TCellCol;

typedef TCellCol* TPCol; //T_Pointeur_Col

typedef struct{
	int numRow;
	TPCol headCols;
	struct TCellRow* next;
}TCellRow;

typedef TCellRow* TPRow;

typedef struct{
	int nbMaxRows;
	int nbMaxCols;
	double valDef;
	TPRow headRows; //pointeur vers la 1ere structure "TCellRow" : NE DOIT PAS CHANGER ! 
}TMatr;
