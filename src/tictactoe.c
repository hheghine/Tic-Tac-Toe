#include "../includes/tictactoe.h"

void    win_init()
{
    InitWindow(WIDTH, HEIGHT, "Tic-Tac-Toe");
    SetTargetFPS(60);
}

void    win_run()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        EndDrawing();
    }
}

int main()
{
    win_init();
    action();
    CloseWindow();
}

// int main(void)
// {
//     InitWindow(800, 450, "Tic-Tac-Toe");

//     while (!WindowShouldClose())
//     {
//         BeginDrawing();
//             ClearBackground(RAYWHITE);
//             DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
//         EndDrawing();
//     }

//     CloseWindow();

//     return 0;
// }