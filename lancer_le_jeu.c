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
 
void lancer_le_jeu(int grid_size)
{
    // On défini le pointeur du fichier pour stocker le temps et le nom du joueur s'il gagne
    FILE * fPtr;
    fPtr = fopen("score.txt", "w");
    if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
    }
    
    
    
    
    int nlignes = grid_size;
    int nColonnes = grid_size;
    
    //Créer les tableaux bi dimentionnels (Allocation dynamique car la taille change à chaque fois)
    char** matrice_affichee = (char**)malloc(grid_size * sizeof(char*));
    for (int i = 0; i < grid_size; i++)
        matrice_affichee[i] = (char*)malloc(grid_size * sizeof(char));

    char** matrice_bombes = (char**)malloc(grid_size * sizeof(char*));
    for (int i = 0; i < grid_size; i++)
        matrice_bombes[i] = (char*)malloc(grid_size * sizeof(char));


    // matrice_affichee  est initialisé avec  des  X
    for (int i = 0; i < nlignes; i++)
    {
        for (int j = 0; j < nColonnes; j++)
        {
            matrice_affichee[i][j] = 'X';
        }
    }

    // Initialisation de la matrice des bombes
    for (int i = 0; i < nlignes; i++)
    {
        for (int j = 0; j < nColonnes; j++)
        {
            matrice_bombes[i][j] = '0';
        }
    }
    
    // Generer 10 si le niveau est facil, 40 sinon
    int mine_count = 0;
    if(grid_size == 9)
    {
        mine_count = 10;
    }
    else if(grid_size == 16)
    {
        mine_count = 40;
    }
    
    while (mine_count > 0)
    {
        // On génère les bombes randomly
        int i = rand() % nlignes;
        int j = rand() % nColonnes;
        if (matrice_bombes[i][j] == '1')
        {
            continue;
        }
        matrice_bombes[i][j] = '1';
        --mine_count;
    }

    int blank_count = 0;
    while (1)
    {
        // Si le joueur gagne, on print le temps
        clock_t t;
        t = clock();

        printf("\n");
        
        int flag = 0;
        //affichege de la matrice  
        //afficher_matrice(matrice_bombes, grid_size, flag);
        afficher_matrice(matrice_affichee, grid_size, flag);
        
        //reccuperation des coordonnées de l'utilisateur
        printf("\n \n");
        
        printf(" Voulez vous : \n");
        printf(" 1. Decouvrir une ligne \n");
        printf(" 2. Placer/enlever un marquer de bombes\n");

        int coord_bombe = 0;
        scanf("%d", &coord_bombe);

        int i = 0;
        int j = 0;

        int i_bombe = 0;
        int j_bombe = 0;

        if(coord_bombe == 1){
            
            for(int i1=0; i1<grid_size;i1++)
            {
                for(int j1=0; j1<grid_size;j1++)
                {
                    if(i1==0 && j1==0)
                    {
                        if(matrice_bombes[i1][j1] == '0' && matrice_bombes[i1+1][j1+1]== '0' && matrice_bombes[i1][j1+1]== '0' && matrice_bombes[i1+1][j1]== '0')
                        {
                            matrice_affichee[i1][j1] = '0';
                        }            
                    }
                    if(i1 == grid_size-1 && j1 == grid_size-1)
                    {
                        if(matrice_bombes[i1][j1] == '0' && matrice_bombes[i1-1][j1-1]== '0' && matrice_bombes[i1][j1-1]== '0' && matrice_bombes[i1-1][j1]== '0')
                        {
                            matrice_affichee[i1][j1] = '0';
                        }            
                    }

                    if(i1 == grid_size-1 && j1 == 0)
                    {
                        if(matrice_bombes[i1][j1] == '0' && matrice_bombes[i1-1][j1]== '0' &&  matrice_bombes[i1-1][j1+1]== '0' &&  matrice_bombes[i1][j1+1]== '0')
                        {
                            matrice_affichee[i1][j1] = '0';
                        }            
                    }
                    if(j1 == grid_size-1 && i1 == 0)
                    {
                        if(matrice_bombes[i1][j1] == '0' && matrice_bombes[i1][j1-1]== '0' &&  matrice_bombes[i1+1][j1-1]== '0' &&  matrice_bombes[i1+1][j1]== '0')
                        {
                            matrice_affichee[i1][j1] = '0';
                        }            
                    }

                    if(i1>0 && j1>0 && i1<grid_size-1 && j1<grid_size-1)
                    {
                        if(matrice_bombes[i1][j1] == '0' && matrice_bombes[i1-1][j1-1] == '0' && matrice_bombes[i1-1][j1]== '0' && matrice_bombes[i1][j1-1]== '0' && matrice_bombes[i1+1][j1+1]== '0' && matrice_bombes[i1][j1+1]== '0' && matrice_bombes[i1+1][j1]== '0')
                        {
                            matrice_affichee[i1][j1] = '0';
                        }            
                    }
                    else if(i1 == 0 && j1 != 0 && i1<grid_size-1 && j1<grid_size-1)
                    {
                        if(matrice_bombes[i1][j1] == '0' && matrice_bombes[i1][j1-1] == '0' && matrice_bombes[i1+1][j1-1] == '0' && matrice_bombes[i1+1][j1+1]== '0' && matrice_bombes[i1][j1+1]== '0' && matrice_bombes[i1+1][j1]== '0')
                        {
                            matrice_affichee[i1][j1] = '0';
                        }
                    }
                   
                    else if(j1 == 0 && i1 != 0 && i1<grid_size-1 && j1<grid_size-1)
                    {
                        if(matrice_bombes[i1][j1] == '0' && matrice_bombes[i1-1][j1] == '0' && matrice_bombes[i1-1][j1+1] == '0' &&  matrice_bombes[i1+1][j1+1]== '0' && matrice_bombes[i1+1][j1]== '0'&& matrice_bombes[i1][j1+1]== '0')
                        {
                            matrice_affichee[i1][j1] = '0';
                        }
                    }
                    else if(j1 == grid_size-1 && i1 != grid_size-1 && i1!=0)
                    {
                        if(matrice_bombes[i1][j1] == '0' && matrice_bombes[i1-1][j1] == '0' && matrice_bombes[i1-1][j1-1] == '0' && matrice_bombes[i1+1][j1]== '0' && matrice_bombes[i1][j1-1]== '0'&& matrice_bombes[i1+1][j1-1]== '0' )
                        {
                            matrice_affichee[i1][j1] = '0';
                        }
                    }
                    else if(i1 == grid_size-1 && j1 != grid_size-1 && j1!=0)
                    {
                        if(matrice_bombes[i1][j1] == '0' && matrice_bombes[i1][j1-1] == '0' && matrice_bombes[i1-1][j1-1] == '0' && matrice_bombes[i1][j1+1]== '0' && matrice_bombes[i1-1][j1]== '0' && matrice_bombes[i1-1][j1+1]== '0' )
                        {
                            matrice_affichee[i1][j1] = '0';
                        }
                    }

                    


                }
            }




            printf(" Entrer les coordonees : \n");
            printf("\n");
            printf(" ligne = ");
            scanf("%d", &i);
            printf(" colonne = ");
            scanf("%d", &j);


            

            printf("\n \n");
            if (matrice_affichee[i][j] != 'X')
            {
                printf(" La position d'entree a ete retournee, veuillez la saisir a nouveau.! \n");
                continue;
            }


            // Decider de marcher sur une bombe 
            if (matrice_bombes[i][j] == '1')
            {
                // Step on thunder, prompt game is over 
                afficher_matrice(matrice_bombes, grid_size, flag);
                printf(" Fin de la partie !\n");
                break;
            }

            
            blank_count++;
            
            // Si le jeu est gagnant
            if (blank_count == nlignes * nColonnes - grid_size+1)
            {
                printf(" Felicitations, vous avez gagne!\n");
                
                t = clock() - t;
                double time_taken = ((double)t)/CLOCKS_PER_SEC; 
                printf("Temps %f : \n", time_taken);
                
                char output[50];
                snprintf(output, 50, "%f", time_taken);
                
                fputs(output, fPtr);
                /* Close file to save file data */
                fclose(fPtr);
                break;
            }
            // Si l'utilisateur entre des coordonnées négatifs ou supérieur au grid_size
            if (i < 0 || i >= nlignes || j < 0 || j >= nColonnes)
            {
                printf("Ereur de l'entree, reentrer svp! \n");
                continue;
            }
            //7. Update the map to change the current location to 1 A digital 
            mise_a_jour(matrice_affichee, matrice_bombes, i, j, grid_size);
        }

        else if(coord_bombe == 2){
            printf(" Entrer la case : \n");
            printf("\n");
            printf(" ligne = ");
            scanf("%d", &i_bombe);
            printf(" colonne = ");
            scanf("%d", &j_bombe);
            if(matrice_affichee[i_bombe][j_bombe] != 'M'){
                matrice_affichee[i_bombe][j_bombe] = 'M';
            }
            else{
                matrice_affichee[i_bombe][j_bombe] = 'X';
            }
        }
        
 }
}