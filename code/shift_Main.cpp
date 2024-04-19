#include "shift_Main.h"
#include "shift_Data.h"

enum GameState {MENU, GAME, RESET};
GameState applicationState;

// NOTE : GLOBALS
global_variable Texture2D playerTexture;

int main() 
{
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Shift");
  SetTargetFPS(144);

  initGameData();

// TODO : make the game start at menu and do the stuff there
  applicationState = GAME;
  while(!WindowShouldClose()) 
  {
    BeginDrawing();
    ClearBackground(BLUE);

// TODO : make the other states
    switch(applicationState) 
    {
      case GAME: 
        {
          updateGame();
        }break;
    }    
    EndDrawing();
  }
  CloseWindow();
}

internal void initGameData() 
{
  playerTexture = createTextureFromImage("../data/res/textures/PlayerCharacter.png");
  createAnimations();
}

internal void updateGame() 
{
  handlePlayerData(playerTexture);
}
