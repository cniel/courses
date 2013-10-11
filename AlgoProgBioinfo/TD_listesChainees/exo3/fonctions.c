#include <stdlib.h>
#include <stdio.h>

#include "structures.h"
#include "fonctions.h"

//##########################################################################################################################

void initMat(TMatr* adr_mat, int nbMaxRows, int nbMaxCols, double valDef){
	//adr_mat = (TMatr*)malloc(sizeof(TMatr));  NE PAS FAIRE ÇA !!!!! : la mémoire est déjà allouée dans le main quand on fait la déclaration.
	
	adr_mat->nbMaxRows = nbMaxRows;
	adr_mat->nbMaxCols = nbMaxCols;
	adr_mat->valDef = valDef;
	adr_mat->headRows = NULL;
	
	printf("Dans la fonction:\nmatrice initialisée :\n%d, %d, %f, %p.\n",adr_mat->nbMaxRows, adr_mat->nbMaxCols, adr_mat->valDef, adr_mat->headRows);
}

TPRow allouerMemoire(){
//
}

TPCol allouerMeuuuhmoire(){
//
}



void recherche_col(TPCol headCols, TPCol* adr_Col, TPCol* adr_ColPrec){
	TPCol pc;
	TPCol pcp;
	
	pcp=NULL; pc=headCols;
	while(pc != NULL && pc->numCol < j){
		pcp = pc; 
		pc = pc->next;
	}
	if(pc != NULL && pc->numCol > j)
		pc = NULL;
	*adr_Col=pc;
	*adr_ColPrec=pcp;
}

//##########################################################################################################################

void recherche(TMatr mat, int i, int j, TPRow* adr_Row, TPRow* adr_RowPrec, TPCol* adr_Col, TPCol* adr_ColPrec){
	*adr_Row = NULL;
	*adr_RowPrec = NULL;
	*adr_Col = NULL;
	*adr_ColPrec = NULL;

	TPRow pl = mat.headRows;
	TPRow plp = NULL;
	TPCol pc = NULL;
	TPCol pcp = NULL;


	while(pl != NULL && pl->numRow < i){
		plp = pl;
		pl = pl->next;
	}

	if(pl != NULL){
		if(pl->numRow == i) 
			recherche_col(pl->headCols, adr_Col, adr_ColPrec);
		else
			pl=NULL;
	}
	
	*adr_Row = pl;
	*adr_RowPrec = plp;
}

//##########################################################################################################################

void creation_case_affectation1(TMatr* adr_mat, TPRow adr_prec, int i, int j, double val){
/* préconditions:
	*adr_p_prec est significatif (NULL ou non)
	La ligne n'existe pas
*/

	TPRow p = allouerMemoire();
	TPCol q = allouerMeuuuhmoire();
	
	p->numRow = i;
	if(adr_prec == NULL){
		p->next = adr_mat->headRows;
		adr_mat->headRows = p;
	}else{
		p->next = adr_prec->next;
		adr_prec->next = p;
	}
	
	//création de la colonne j
	q->val = val;
	q->numCol = j;
	q->next = NULL;
	p->headCols = q;
}

//##########################################################################################################################

void creation_case_affectation2(TPRow adr_lig_i, TPCol adr_j_prec, int j, double val){
/* préconditions:
	*adr_ptr_lig_i != NULL (et est significatif)
	*adr_p_j_prec est significatif (NULL ou non)

   Postcondition:
   	la colonne j a été créé.
*/

	TPCol q = allouerMemoire();
	q->val=val;
	q->numCol=j;
	
	if(adr_j_prec == NULL){
		q->next = adr_lig_i->headCols;
		adr_lig_i->headCols = q;
	}else{
		q->next = adr_j_prec->next;
		adr_j_prec->next = q;
	}
}

//##########################################################################################################################

void detruire_case(TMatr* adr_mat, TPRow ptr_i_prec, TPRow* adr_ptr_i, TPCol ptr_j_prec, TPCol* adr_ptr_j){
	//case en fin de liste
	//case en milieu de liste
	//case en tete de liste
	
	//est-ce que c'est la dernière case de la ligne ? ou reste-t-il d'autres cases?
	
	if(ptr_j_prec == NULL)
		(*adr_ptr_i)->headCols = (*adr_ptr_j)->next; //2
		
		if((*adr_ptr_i)->headCols == NULL)
			detruire_ligne_i_en_tete(adr_mat, adr_ptr_i);

	else{
		ptr_j_prec->next = (*adr_ptr_j)->next; // les deux cas 1	
	}
	free(*adr_ptr_j);
}	
	
void detruire_ligne_i_en_tete(TMatr* adr_mat, TPRow* adr_ptr_i){
	//précondition : *adr_ptr_i pointe sur la première case de la liste adr_mat->headRows
	//postcondition : La ligne i a été suprimée de ette liste.
}

void modifier_valeur(TPCol ptr_j, double val){
	ptr_j->val = val;
}

//##########################################################################################################################

void set(TMatr* adr_mat, int i, int j, double val){
	TPRow ptr_lig_i;
	TPRow ptr_lig_i_prec;
	TPCol ptr_col_j;
	TPCol ptr_col_j_prec;
	
	recherche(*adr_mat, i, j, &ptr_lig_i, &ptr_lig_i_prec, &ptr_col_j, &ptr_col_j_prec);
	
	if(ptr_lig_i == NULL){
		if(val != adr_mat->valDef) //1.2
			creation_case_affectation1(adr_mat, ptr_lig_i_prec, i, j, val);
		return; //on sort de la procédure.
	}

	if(ptr_col_j == NULL){
		if(val != adr_mat->valDef) //1.2
			creation_case_affectation2(ptr_lig_i, ptr_col_j_prec, j, val);
	}else{
		if(val == adr_mat->valDef) //2.1
			detruire_case(adr_mat, ptr_lig_i_prec, &ptr_lig_i, ptr_col_j_prec, &ptr_col_j);
		else //2.2
			modifier_valeur(ptr_col_j, val);
	}
}
//##########################################################################################################################

