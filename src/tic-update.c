#include "../includes/tictactoe.h"

// Vector2, 2 components
// typedef struct Vector2 {
//     float x;                // Vector x component
//     float y;                // Vector y component
// } Vector2;

bool    update_square(uint8_t x, uint8_t y, uint8_t player)
{
    const uint8_t   square_size = 60;
    const uint8_t   offset_x = (WIDTH + square_size * 3) * 10;
    const uint8_t   offset_y = (HEIGHT + square_size * 3) * 10;

    uint8_t pos_x = offset_x + x * square_size;
    uint8_t pos_y = offset_y + y * square_size;

    Vector2 mouse_position = GetMousePosition();

    DrawRectangleLines(pos_x, pos_y, square_size, square_size, GREEN);

    if (player == 1)
        DrawText("x", pos_x + 20, pos_y + 10, square_size - 20, LIGHTGRAY);
    else if (player == 2)
        DrawText("o", pos_x + 20, pos_y + 10, square_size - 20, LIGHTGRAY);
    else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if (mouse_position.x > pos_x
            && mouse_position.x < pos_x + square_size
            && mouse_position.y > pos_y
            && mouse_position.y < pos_y + square_size)
            return (true);
    }
    return (false);
}

void    board_update(board *board, uint8_t *player)
{
    for (uint8_t i = 0; i < 3; i++)
    {
        for (uint8_t j = 0; j < 3; j++)
        {
            if(update_square(i, j, board->position[i][j]))
            {
                board->position[i][j] = *player;
                *player = next_player(*player);
            }
        }
    }
}