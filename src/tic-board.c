#include "../includes/tictactoe.h"

bool    board_full(board board)
{
    for (uint8_t i = 0; i < 3; i++)
    {
        for (uint8_t j = 0; j < 3; j++)
        {
            if (board.position[i][j] == EMPTY)
                return (false);
        }
    }
    return (true);
}

uint8_t next_player(uint8_t player)
{
    return (player == 2 ? 1 : 2);
}

board   board_constructor()
{
    board   board;

    for (uint8_t i = 0; i < 3; i++)
    {
        for (uint8_t j = 0; j < 3; j++)
            board.position[i][j] = EMPTY;
    }
    return (board);
}
