#ifndef DEMINEUR_H_INCLUDED
#define DEMINEUR_H_INCLUDED 1

int interface();
void lancer_le_jeu(int grid_size);
void afficher_matrice(char **map, int grid_size, int flag);
void mise_a_jour(char** matrice_affichee, char** matrice_bombes, int i, int j, int grid_size);


#endif