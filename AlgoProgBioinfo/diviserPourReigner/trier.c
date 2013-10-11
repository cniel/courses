PROCEDURE trier((es)V:vecteur d'entiers, (e)g:entier, (e)d:entier)
variables locales:
index_pivot : entier

debut
	si(g<d) alors
		séparer(V,g,d,index_pivot)
		trier(V, g, index_pivot-1)
		trier(V, index_pivot+1, d)
	fin
fin
