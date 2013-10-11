PROCÉDURE separer((es)V:vecteur d'entiers, (e)g:entier, (e)d:entier, (s)index_pivot:entier)
// g  et d sont des bornes gauches et droites -> délimitent la partie de vecteur qui m'intéresse.

//précondition : g < d
//postcondition : sépare le vecteur pris entre les bornes g et d en trois zones: V[g ... index_point-1], V[index_pivot], V[index_pivot+1 ... d]
//pourTout g <= j <= index_pivot-1 : V[j] <= V[index_pivot]
//pourTout index_pivot+1 : V[index_pivot] < V[j]

variables locales:
comp, pivot : entiers
bas, haut : entiers

debut
	bas <- g; haut <- d;
	pivot <- V[bas]
	comp <- V[haut]
	tantQue bas < haut
		si comp > pivot alors
			V[haut] <- comp
			decr(haut)
			comp <- V[haut]
		sinon
			V[bas] <- comp
			incr(bas)
			comp <- V[bas]
		finsi
	fin tantQue
	
	V[bas] <- pivot
	index_pivot <- bas
fin
