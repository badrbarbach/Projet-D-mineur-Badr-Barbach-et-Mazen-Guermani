Organisation du projet:
demineur.h : contient toutes les déclaration des fonctions du fichier principal.
demineur.c : c'est le fichier contenant la fonction main, et qui fait appel à la fonction lancer_le_jeu
afficher_matrice.c : pour afficher une matrice dans le terminal
interface.c : pour demander à l'utilisateur d'entrer ses choix.
mise_a_jour.c : pour mettre à jour la matrice affichée sur le terminal
lancer_le_jeu : pour lancer le jeu.

Compilation du projet:
Pour compiler le projet, taper la commande suivante :
    make
et le compilateur va chercher automatiquement, le makefile, donc pas besoin de le specifier.
Le makefile, compile tous les fichier .c 


Description du projet :
Le jeu demande à l'utilisteur de choisir s'il va jouer ou quitter, si l'utilisateur choisit de 
jouer, le jeu lui demande d'entrer son nom. Ce nom sera stocké dans un fichier texte si le 
joueur gagne, le nom sera stocké avec le temps pris par l'utilisateur pour gagner.

Ensuite, le programme affiche la matrice, et demande à l'utilisateur d'entrer les coordonnées.
De plus, pour gagner des points bonus, j'ai écrit quelques commentaires en anglais.
