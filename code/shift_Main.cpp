#include "Shift_Main.h"
#include "Shift_Player.h"
#include "Shift_Tilesets.h"

internal void 
Init() 
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Shift");
    HandleWorldData();
}

internal void 
Update() 
{
    BeginDrawing();

    ClearBackground(BLUE);
    HandlePlayer();

    EndDrawing();
}

int main() 
{
    Init();

    while(!WindowShouldClose()) 
    {
      Update();
    } 
    
    return(0);
}
