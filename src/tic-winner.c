#include "../includes/tictactoe.h"

bool    horizontal(board board, uint8_t player)
{
    for (uint8_t i = 0; i < 3; i++)
    {
        if (board.position[i][0] == player
            && board.position[i][1] == player
            && board.position[i][2] == player)
            return (true);
    }
    return (false);
}

bool    vertical(board board, uint8_t player)
{
    for (uint8_t i = 0; i < 3; i++)
    {
        if (board.position[0][i] == player
            && board.position[1][i] == player
            && board.position[2][i] == player)
            return (true);
    }
    return (false);
}

bool    diagonal(board board, uint8_t player)
{
    for (uint8_t i = 0; i < 3; i++)
    {
        if (board.position[0][0] == player
            && board.position[1][1] == player
            && board.position[2][2] == player)
            return (true);

        if (board.position[2][0] == player
            && board.position[1][1] == player
            && board.position[0][2] == player) 
            return (true);
    }
    return (false);
}

bool    win_check(board board, uint8_t player)
{
    if (horizontal(board, player) ||
        vertical(board, player) ||
        diagonal(board, player))
        return (true);
    return (false);
}