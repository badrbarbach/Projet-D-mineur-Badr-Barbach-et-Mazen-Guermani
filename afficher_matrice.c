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
 
/*
La fonction suivante permet d'afficher les matrices sur le terminal
*/
void afficher_matrice(char **map, int grid_size, int flag)
{
    int nColonnes = grid_size;
    int nlignes = grid_size;
    //Afficher la toute première ligne
    printf(ANSI_COLOR_YELLOW"    "ANSI_COLOR_YELLOW);
    for (int  i= 0; i < nColonnes; i++)
    {
        if(i<10){
            printf(ANSI_COLOR_YELLOW" %d |"ANSI_COLOR_YELLOW, i);
        }
        else{
            printf(ANSI_COLOR_YELLOW" %d|"ANSI_COLOR_YELLOW, i);
        }
    }
    printf("\n");
    //On affiche les séparateurs
    for (int j = 0; j < nColonnes; j++)
    {
        printf(ANSI_COLOR_YELLOW"----"ANSI_COLOR_YELLOW);
    }
    printf("\n");
    
    //On affiche les lignes
    for (int i = 0; i < nlignes; i++)
    {
        if(i<10){
            printf(ANSI_COLOR_YELLOW" %d |"ANSI_COLOR_YELLOW, i);
        }
        else{
            printf(ANSI_COLOR_YELLOW" %d|"ANSI_COLOR_YELLOW, i);
        }
        
        
        for (int j = 0; j < nColonnes; j++)
        {
            if(map[i][j] == 'X')
            {
                printf(ANSI_COLOR_YELLOW" %c |"ANSI_COLOR_RESET, map[i][j]);
            }
            else if(map[i][j] == 'M'){
                printf(ANSI_COLOR_BLUE" %c"ANSI_COLOR_RESET, map[i][j] );
                printf(ANSI_COLOR_YELLOW" |"ANSI_COLOR_RESET);
            }
            else{
                printf(ANSI_COLOR_CYAN" %c"ANSI_COLOR_RESET, map[i][j] );
                printf(ANSI_COLOR_YELLOW" |"ANSI_COLOR_RESET);
            }
                
            
        }
        printf("\n");
        }
}