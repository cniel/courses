#include <stdlib.h>
#include <stdio.h>

#include "structures.h"
#include "fonctions.h"


void initMat(TMatr* adr_mat, int pnbMaxRows, int pnbMaxCols, double pvalDef){
	//adr_mat = (TMatr*)malloc(sizeof(TMatr));  NE PAS FAIRE ÇA !!!!! : la mémoire est déjà allouée dans le main quand on fait la déclaration.
	
	adr_mat->nbMaxRows = pnbMaxRows;
	adr_mat->nbMaxCols = pnbMaxCols;
	adr_mat->valDef = pvalDef;
	adr_mat->headRows = NULL;
	
	printf("Dans la fonction:\nmatrice initialisée :\n%d, %d, %f, %p.\n",adr_mat->nbMaxRows, adr_mat->nbMaxCols, adr_mat->valDef, adr_mat->headRows);
}

void recherche(TMatr mat, int i, int j, TPRow* adr_pRow, TPRow* adr_pRowPrec, TPCol* adr_pCol, TPCol* adr_pColPrec){
	*adr_pRow = mat.headRows;
	*adr_pRowPrec = NULL;
	*adr_pCol = NULL;
	*adr_pColPrec = NULL;
		
	while(*adr_pRow != NULL && (*adr_pRow)->numRow < i){
		*adr_pRowPrec = *adr_pRow;
		*adr_pRow = (*adr_pRow)->next;
	}

	if(*adr_pRowPrec != NULL){
		*adr_pCol = (*adr_pRow)->next;
		while(*adr_pCol != NULL && (*adr_pCol)->numCol < j){
			*adr_pColPrec = *adr_pCol;
			*adr_pRowPrec = *adr_pRow;
		}
	}
}
