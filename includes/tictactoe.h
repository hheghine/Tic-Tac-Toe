#ifndef TICTACTOE_H
# define TICTACTOE_H

# include "raylib.h"

# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>

# define WIDTH 800
# define HEIGHT 600

#define EMPTY 0

typedef struct board
{
    uint8_t position[3][3];
}   board;

board   board_constructor(void);
bool    board_full(board board);
uint8_t next_player(uint8_t player);
bool    win_check(board board, uint8_t player);
void    board_update(board *board, uint8_t *player);
void    action();

#endif