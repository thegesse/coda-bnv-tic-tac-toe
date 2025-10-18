#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char grid[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

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

char win_condition() {
    // Check for 'o' wins (rows, columns, diagonals)
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
    
    // Check for 'X' wins (rows, columns, diagonals)
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
    
    // Check if all squares are full (draw) using a while loop
    // Assuming empty squares are represented by ' ' (space)
    int i = 0;
    while (i < 9) {
        if (grid[i] == ' ') {
            // If any square is empty, no draw yet
            return 0;  // Or whatever value indicates no win/draw yet
        }
        i++;
    }
    // If loop completes without finding an empty square, it's a draw
    return 3;
}

void machine() {
    if (win_condition() != 0) {
        // Game is over (win or draw), so don't make a move
        return;
    }
    int bot;
    do {
        srand(time(NULL));
        bot = rand() % 9;
    } while (grid[bot] != ' ');  // Keep looping until an empty spot is found
    grid[bot] = 'X';
    printf("Bot placed 'X' at spot: %d\n", bot);
}