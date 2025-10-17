#include <stdio.h>

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

int main(){
    int game_state = 0;
    draw_grid();
    while(game_state == 0){
        printf
    }

}