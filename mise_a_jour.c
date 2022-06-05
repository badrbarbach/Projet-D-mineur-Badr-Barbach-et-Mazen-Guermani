#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stdio.h>
#include "demineur.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


void mise_a_jour(char** matrice_affichee, char** matrice_bombes, int i, int j, int grid_size)
{
    int nColonnes = grid_size;
    int nlignes = grid_size;
    int count = 0;
    if (i - 1 >= 0 && j - 1 >= 0 && matrice_bombes[i - 1][j - 1] == '1')
    { 
        count++;
    }
    if (i - 1 >= 0 && matrice_bombes[i - 1][j] == '1')
    {
        count++;
    }
    if (i - 1 >= 0 && j + 1 < nColonnes && matrice_bombes[i - 1][j + 1] == '1')
    {
        count++;
    }
    if (j - 1 >= 0 && matrice_bombes[i][j - 1] == '1')
    {
        count++;
    }
    if (j + 1 < nColonnes && matrice_bombes[i][j + 1] == '1')
    {
        count++;
    }
    if (i + 1 < nlignes && j - 1 >= 0 && matrice_bombes[i + 1][j - 1] == '1')
    {
        count++;
    }
    if (i + 1 < nlignes && matrice_bombes[i + 1][j] == '1')
    {
        count++;
    }
    if (i + 1 < nlignes && j + 1 < nColonnes && matrice_bombes[i + 1][j + 1] == '1')
    {
        count++;
    }
    //count la valeur des mines qui entour la position actuelle
    matrice_affichee[i][j] = count + '0';
}




