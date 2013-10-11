/*
PROCÉDURE tri_bulles((es) V : vecteur d'entrées, (e) n : entrée)
variables locales:
i : entier

début
	i <- n
	tant que i >= 2
		echanger_jusqu'à_position_i(V,i)
		decr(i)
	finTantQue
fin
*/

/*
PROCÉDURE echanger_jusqu'à_position_i((es)V:vecteur d'entiers, (e)i:entier)
variables locales:
j : entier

début
	j <- 1
	tant que j < i 
		si V[j] > V[j+1]
			alors échanger(V, j, j+1)
		finsi
		incr(j)
	fintantque
fin
*/

/*
PROCÉDURE tri_bulles_2((es)V:vecteur d'entiers, (e)n:entier)
variables locales:
dn:entier //dernier modifié
echange : booléen

debut
	dn <-n
	echange <- vrai
	tantque (dn <= 2 et echange)
		echanger_jusqua_position_dn(V, dn, echange)
	fin TantQue
fin
*/

/*
PROCEDURE echange_jusqua_position_dn((es)V:vecteur d'entrées, (es):dn;entier, (es): echange)
//précondition:
//echange : vrai

variable locale:
j, index_dn : entiers

debut
	echange <- faux
	j <- 1
	tant que j < dn:
		si (V[j] > V[j+1])
			alors echanger(V, j, //j+1)
			echange <- vrai
		finSi
		inser(j)
	finTantque
	dn <- index_dn
fin
*/
