#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char grid[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void draw_grid(){
    printf("        |           |         \n"
       "        |           |         \n"
       "     %c  |       %c   |   %c    \n"
       "________|___________|_________\n"
       "        |           |         \n"
       "        |           |         \n"
       "     %c  |       %c   |   %c    \n"
       "________|___________|_________\n"
       "        |           |         \n"
       "        |           |         \n"
       "     %c  |       %c   |   %c    \n",
       grid[0], grid[1], grid[2], grid[3], grid[4], grid[5], grid[6], grid[7], grid[8]);

}

char win_condition() {
    // regarde si le joueur gagne
    if ((grid[0] == 'o' && grid[1] == 'o' && grid[2] == 'o') ||
        (grid[3] == 'o' && grid[4] == 'o' && grid[5] == 'o') ||
        (grid[6] == 'o' && grid[7] == 'o' && grid[8] == 'o') ||
        (grid[0] == 'o' && grid[3] == 'o' && grid[6] == 'o') ||
        (grid[1] == 'o' && grid[4] == 'o' && grid[7] == 'o') ||
        (grid[2] == 'o' && grid[5] == 'o' && grid[8] == 'o') ||
        (grid[0] == 'o' && grid[4] == 'o' && grid[8] == 'o') ||
        (grid[2] == 'o' && grid[4] == 'o' && grid[6] == 'o')) {
        return 1;
    }
    
    // regarde si le bot gagne
    else if ((grid[0] == 'X' && grid[1] == 'X' && grid[2] == 'X') ||
             (grid[3] == 'X' && grid[4] == 'X' && grid[5] == 'X') ||
             (grid[6] == 'X' && grid[7] == 'X' && grid[8] == 'X') ||
             (grid[0] == 'X' && grid[3] == 'X' && grid[6] == 'X') ||
             (grid[1] == 'X' && grid[4] == 'X' && grid[7] == 'X') ||
             (grid[2] == 'X' && grid[5] == 'X' && grid[8] == 'X') ||
             (grid[0] == 'X' && grid[4] == 'X' && grid[8] == 'X') ||
             (grid[2] == 'X' && grid[4] == 'X' && grid[6] == 'X')) {
        return 2;
    }
    //regarde si le match est nul
    int i = 0;
    while (i < 9) {
        if (grid[i] == ' ') {
            //regarde si il y a des cases vide
            return 0;
        }
        i++;
    }
    return 3;
}

void machine() {
    if (win_condition() != 0) {
        // regarde si la partie est terminer victoire, defaite ou nul
        return;
    }
    int bot;
    do {
        srand(time(NULL));
        bot = rand() % 9;
    } while (grid[bot] != ' ');  // continue tant qu'il y a une case vide
    grid[bot] = 'X';
    printf("Bot placed 'X' at spot: %d\n", bot);
}