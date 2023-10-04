#include "../includes/tictactoe.h"

void    action()
{
    board   board = board_constructor();
    uint8_t player = next_player(0);
    char    *message = "";

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        board_update(&board, &player);

        if(win_check(board, 1))
        {
            board = board_constructor();
            message = "Player x Won!";
        }
        if (win_check(board, 2))
        {
            board = board_constructor();
            message = "Player o Won!";
        }
        if (board_full(board))
        {
            board = board_constructor();
            message = "GGWP :D";
        }

        DrawText(TextFormat("Current Player: %c", player == 1 ? 'x' : 'o'), 25, 10, 40, VIOLET);
        DrawText(message, 25, 60, 40, VIOLET);
        EndDrawing();
    }
}