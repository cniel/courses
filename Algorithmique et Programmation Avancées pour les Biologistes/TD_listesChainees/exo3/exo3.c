#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "fonctions.h"

int main(){
	TMatr matrix;
	initMat(&matrix, 12, 4, 1.2);
	
	printf("\nDans le main:\nmatrice initialisée :\n%d, %d, %f, %p.\n",matrix.nbMaxRows, matrix.nbMaxCols, matrix.valDef, matrix.headRows);
	
	TPRow p1; TPRow p1prev; TPCol p2; TPCol p2prev;
	recherche(matrix, 3, 5, &p1, &p1prev, &p2, &p2prev);
	printf("\np1:%p\np1prev:%p\np2:%p\np2prev:%p\n", p1,p1prev,p2,p2prev);
	return 0;
}
