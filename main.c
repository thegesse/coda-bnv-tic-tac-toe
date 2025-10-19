#include <stdio.h>
#include <stdlib.h>
#include "tic-tac-toe.h"


int main(){
    int game_state = 0;

    draw_grid();

    printf("Le joueur est 'o', le bot est 'X', la grille est "
        "numeroté de 0 a 8, si la grille ne se place pas instantanement "
        "cela veut dire que le bot reflechi a son prochain "
        "placement veuillez lui laissez un peu de temps \n ");

    while(game_state == 0){
        int  choice;

        printf("\nChoisisez ou jouer: ");
        scanf("%d", &choice);

        if(grid[choice] != 'X' && grid[choice] != 'o'){

            grid[choice] = 'o';
            machine();
            draw_grid();
            win_condition();
        }

        else{
            printf("emplacement invalide ressayez: ");
        }
        
        if(win_condition() == 1){
            printf("C'est gagné\n");
            game_state ++;
        }

        else if(win_condition() == 2){
            printf("c'est perdu\n");
            game_state ++;
        }

        else if(win_condition() == 3){
            printf("match nul\n");
            game_state ++;
        }



    }
    exit(0);
}