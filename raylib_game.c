
#include "raylib.h"
#include "screens.h"    

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

struct {
    float x, y;
    float speedX, speedY;

}Ball;

int main() {

    float ballX, ballY, LrectangleY, RrectangleY, ballspeedX, ballspeedY;

    Ball.x = 400;
    Ball.y = 300;
    LrectangleY = 300;
    RrectangleY = 300;
    Ball.speedX = 100;
    Ball.speedY = 250;


    InitWindow(800, 600, "Pong");
    SetWindowState(FLAG_VSYNC_HINT);

    while (!WindowShouldClose()) {

        if (Ball.y < 0) {
            Ball.y = 0;
            Ball.speedY *= -1;
        }
        
        if (Ball.y > GetScreenHeight()) {
            Ball.y = GetScreenHeight();
            Ball.speedY *= -1;
        }

        

        Ball.x += Ball.speedX * GetFrameTime();
        Ball.y += Ball.speedY * GetFrameTime();

        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircle(Ball.x, Ball.y, 6, WHITE);
        DrawRectangle(20, LrectangleY - 50, 10, 100, WHITE);
        DrawRectangle(780 - 10, RrectangleY - 50, 10, 100, WHITE);

        DrawFPS(10, 10);
        EndDrawing();

    }

    CloseWindow();



    return 0;
}