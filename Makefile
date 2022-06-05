prog : demineur.o mise_a_jour.o afficher_matrice.o lancer_le_jeu.o interface.o 
	gcc -o prog demineur.o mise_a_jour.o afficher_matrice.o lancer_le_jeu.o interface.o 

demineur.o : demineur.c
	gcc -o demineur.o -c demineur.c

interface.o : interface.c
	gcc -o interface.o -c interface.c

mise_a_jour.o : mise_a_jour.c
	gcc -o mise_a_jour.o -c mise_a_jour.c

afficher_matrice.o : afficher_matrice.c
	gcc -o afficher_matrice.o -c afficher_matrice.c

lancer_le_jeu.o : lancer_le_jeu.c
	gcc -o lancer_le_jeu.o -c lancer_le_jeu.c