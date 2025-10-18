#include <stdio.h>
#include <stdlib.h>
#include "tic-tac-toe.h"


int main(){
    int game_state = 0;
    draw_grid();
    printf("player 1 is 'o', player 2 is a computer and is 'X' \n");
    while(game_state == 0){
        int  choice;
        printf("\nplayer 1 turn: ");
        scanf("%d", &choice);
        if(grid[choice] != 'X' && grid[choice] != 'o'){
            grid[choice] = 'o';
            machine();
            draw_grid();
            win_condition();
        }
        else{
            printf("emplacement invalide ressaie: ");
        }
        
        if(win_condition() == 1){
            printf("player 1 wins\n");
            game_state ++;
        }
        else if(win_condition() == 2){
            printf("bot wins\n");
            game_state ++;
        }
        else if(win_condition() == 3){
            printf("draw\n");
            game_state ++;
        }



    }
    exit(0);
}