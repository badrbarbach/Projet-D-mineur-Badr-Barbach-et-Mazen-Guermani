#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include "demineur.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int interface()
{
    printf(ANSI_COLOR_BLUE"------------------------------------------------------\n"ANSI_COLOR_BLUE);
    printf(ANSI_COLOR_BLUE"-------------Bienvenue au jeu demineur----------------\n"ANSI_COLOR_BLUE);
    printf(ANSI_COLOR_BLUE"------------------------------------------------------\n"ANSI_COLOR_BLUE);
    printf(ANSI_COLOR_BLUE"---------------- Chosir 1 pour Jouer -----------------\n"ANSI_COLOR_BLUE);
    printf(ANSI_COLOR_BLUE"-------------- Choisir 0 pout Quitter ----------------\n"ANSI_COLOR_BLUE);
    printf(ANSI_COLOR_BLUE"------------------------------------------------------\n"ANSI_COLOR_BLUE);
    printf(ANSI_COLOR_YELLOW" Votre choix : "ANSI_COLOR_RESET );
    int choix_utilisateur = 0;
    scanf("%d", &choix_utilisateur);
    return choix_utilisateur;
}