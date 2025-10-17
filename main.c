#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char grid[9] = {};


void draw_grid(){
    printf("        |           |         \n"
       "        |           |         \n"
       "     %c  |       %c    |   %c    \n"
       "________|___________|_________\n"
       "        |           |         \n"
       "        |           |         \n"
       "     %c  |       %c    |   %c    \n"
       "________|___________|_________\n"
       "        |           |         \n"
       "        |           |         \n"
       "     %c  |       %c    |   %c    \n",
       grid[0], grid[1], grid[2], grid[3], grid[4], grid[5], grid[6], grid[7], grid[8]);

}
void machine(int player){
    int bot;
    do {
        bot = rand() % 9;
        printf("Bot trying spot: %d\n", bot);
    } while (grid[bot] != '\0' && grid[bot] != player);
    grid[bot] = 'X';
    printf("Bot placed 'X' at spot: %d\n", bot);

}

int full(char *array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == '\0') {
            return 0;
        }
    }
    return 1;
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
        else if(grid[0] == 'X' && grid[1] == 'X' && grid[2] == 'X' || grid[3] == 'X' && grid[4] == 'X' && grid[5] == 'X' || grid[6] == 'X' && grid[7] == 'X' && grid[8] == 'X'){
            return(2);
        }
        
        else if(grid[0] == 'X' && grid[3] == 'X' && grid[6] == 'X' || grid[1] == 'X' && grid[4] == 'X' && grid[7] == 'X' || grid[2] == 'X' && grid[5] == 'X' && grid[8] == 'X'){
            return(2);
        }
        else if(grid[0] == 'X' && grid[4] == 'X' && grid[8] == 'X' || grid[2] == 'X' && grid[4] == 'X' && grid[6] == 'X'){
            return(2);
        }
        if(full(grid, 9)){
            return(3);
        }
}



int main(){
    int game_state = 0;
    draw_grid();
    printf("player 1 is 'o', player 2 is a computer and is 'X' \n");
    while(game_state == 0){
        int  choice;
        printf("\nplayer 1 turn: ");
        scanf("%d", &choice);
        grid[choice] = 'o';
        machine(choice);
        draw_grid();
        win_condition();
        if(win_condition() == 1){
            printf("player 1 wins\n");
            game_state ++;
        }
        else if(win_condition() == 2){
            printf("bot wins");
            game_state ++;
        }
        else if(win_condition() == 3){
            printf("draw");
            game_state ++;
        }



    }
    exit(0);
}