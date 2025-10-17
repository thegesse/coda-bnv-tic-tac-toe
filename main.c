#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char grid[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
void draw_grid();

void draw_grid(){
    printf("        |           |         \n");
    printf("        |           |         \n");
    printf("     %c  |      %c    |   %c    \n", grid[0], grid[1], grid[2]);
    printf("________|___________|_________\n");
    printf("        |           |         \n");
    printf("        |           |         \n");
    printf("     %c  |      %c    |   %c    \n", grid[3], grid[4], grid[5]);
    printf("________|___________|_________\n");
    printf("        |           |         \n");
    printf("        |           |         \n");
    printf("     %c  |      %c    |   %c    \n", grid[6], grid[7], grid[8]);

}
void machine(){
    
}

char win_condition(){
        if(grid[0] == 'o' && grid[1] == 'o' && grid[2] == 'o' || grid[3] == 'o' && grid[4] == 'o' && grid[5] == 'o' || grid[6] == 'o' && grid[7] == 'o' && grid[8] == 'o'){
            return(1);
        }
        
        else if(grid[0] == 'o' && grid[3] == 'o' && grid[6] == 'o' || grid[1] == 'o' && grid[4] == 'o' && grid[7] == 'o' || grid[2] == 'o' && grid[5] == 'o' && grid[8] == 'o'){
            return(1);
        }
        else if(grid[0] == 'o' && grid[4] == 'o' && grid[8] == 'o' || grid[2] == 'o' && grid[4] == 'o' && grid[6] == 'o'){
            return(1);
        }
}
int main(){
    int game_state = 0;
    draw_grid();
    printf("player 1 is 'o', player 2 is computer and is 'x' \n");
    while(game_state == 0){
        int  choice;
        printf("\nplayer 1 turn: ");
        int placement = scanf("%d", &choice);
        grid[choice] = 'o';
        draw_grid();
        win_condition();
        if(win_condition() == 1){
            printf("player 1 wins\n");
            game_state ++;
        }



    }

}