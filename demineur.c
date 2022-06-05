#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stdio.h>
#include "demineur.h"
#include<unistd.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
 

 
// La fonction inerface retourne le choix de l'utilisateur, 
// 2 choix possibles : 1 Jouer, 0 Quitter 
/*
Après que l'utilisateur choisit de jouer, on demande son nom pour l'enregisterer dans un text file au cas où le joueur a gagné. Ce prénom sera aussi stocké avec le temps mis par le joueur pour gagner sa partie.
    On rappelle que Le nom ainsi que le temps ne sont stockés que si l'utilisateur a gagné.
*/
int main(int argc, char *argv[])
{
    int choice = 0;
    /*
    La boucle suivante se répète infiniment, jusq'à ce que le joueur choisit 0, ou 1. dans les autres cas, le compilateur demande à chaque foisau joueur de reentrer son choix 
    */
    int condition = 1; //Si condition est égale à 0, on entre pas dans la boucle
    while (condition)
    {
        choice = interface();    // On récupère le choix de l'utilisateur sous format int
        if (choice == 1)    // Si l'utilisateur a choisit 1 donc on lance le jeu! 
        {
            // Entrer le nom de l'utilisateur
            char* name[20]; 
            // Le nom de l'utilisateur est stocké dans un tableau de caractère, on declare ce tableau d'une manière statique.
            printf(" Entrez votre nom : \n");
            scanf("%s", name);
            
            // Choisir la difficulté 
            printf("Veuillez choisir le niveau : \n");
            printf(" 1. Debutant (9x9) \n");
            printf(" 2. Avance (16x16) \n");
            int inp = 0;
            scanf("%d", &inp);
            
            int grid_size;
            // D'après le choix de l'utilisateur, on fixe la taille de la grid
            if(inp == 1) // Niveau débutant
            {
                grid_size = 9;
            }
            else if(inp == 2) // niveau avancé
            {
                grid_size = 16;
            }
            
            // On lance le jeu 
            lancer_le_jeu(grid_size);
        }
        else if (choice == 0)
        {
            // On quitte le programme si l'utilisateur décide de quitter
            printf("Au revoir !\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("Le choix que vous avez entre n'existe pas, rentrez svp! \n");
        }
    }
    return 0;
} 