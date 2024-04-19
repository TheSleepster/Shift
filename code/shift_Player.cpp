#include "shift_Main.h"
#include "shift_Data.h"

global_variable Entity *player = nullptr;

void handlePlayerData(Texture2D playerTexture) 
{
  if(player == nullptr) 
  {
    player = initPlayer(playerTexture);
  } 
  updatePlayer();
}

internal Entity *initPlayer(Texture2D playerTexture) 
{
  player = (Entity*)malloc(sizeof(struct Entity));

  player->entityFlags.isActive = true;
  player->entityFlags.isPlayer = true;
  player->entityFlags.isAnimated = true;
  player->entityFlags.isInMotion = false;
  player->entityFlags.isAI = {};
  player->entityFlags.isEnvironment = {};

  player->sprite = playerTexture; 
  player->srcRect = {0, 0, 16, 32};
  player->sheetLength = 9;
  player->rotation = 0;
  player->scale = 3;

  player->pos = {200, 300};
  player->vel = {0, 0};
  player->movementSpeed = 2.0f;

  player->maxHealth = 5;
  player->currentHealth = 5;

  return(player);
}

internal void updatePlayer() 
{
  vec2 oldPlayerPos = player->pos;
  player->pos = handlePlayerMovement();

// TODO : Animation system (State Machine??)

  player->dstRect = 
  {
    player->pos.x, 
    player->pos.y, 
    player->srcRect.width * player->scale,
    player->srcRect.height * player->scale
  };

  if(player->entityFlags.isInMotion) 
  {
    playAnimation(player, pWalking);
    printf("walking\n");
  }
  else if(!player->entityFlags.isInMotion) 
  {
    playAnimation(player, pIdle);
    printf("idle\n");
  }

  DrawTexturePro
  (player->sprite, player->srcRect, player->dstRect, {0, 0}, player->rotation, WHITE);
}

internal vec2 handlePlayerMovement() 
{

// VERTICAL
  if(IsKeyDown(KEY_W)) 
  {
    player->vel.y = -player->movementSpeed;
  } 
  else if(IsKeyDown(KEY_S)) 
  {
    player->vel.y = player->movementSpeed;
  }
  else 
  {
    player->vel.y = 0;
  }

// HORIZONTAL
  if(IsKeyDown(KEY_A)) 
  {
    player->vel.x = -player->movementSpeed;
  }
  else if(IsKeyDown(KEY_D)) 
  {
    player->vel.x = player->movementSpeed;
  }
  else 
  {
    player->vel.x = 0;
  }

  if(IsKeyUp(KEY_W) && IsKeyUp(KEY_D) && IsKeyUp(KEY_S) && IsKeyUp(KEY_D)) 
  {
    player->entityFlags.isInMotion = false;
  }
  else if(IsKeyDown(KEY_W) || IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D)) 
  {
    player->entityFlags.isInMotion = true;
  }

  Vector2Normalize(player->vel);
  player->pos.y += player->vel.y;
  player->pos.x += player->vel.x;
  return(player->pos);
}
