#include "Shift_Main.h"
#include "Shift_Player.h"
#include "Shift_Entity.h"

global_variable Texture2D PlayerSpriteSheet; 

internal Entity*
InitPlayerData() 
{
    Entity *dummy = (Entity*)malloc(sizeof(struct Entity));

    dummy->pos = {200, 300};
    dummy->vel = {0, 0};
    dummy->movementSpeed = 200.0f;
    dummy->accel = 0.5f;
    dummy->friction = 0.25f;
    dummy->Sprite = PlayerSpriteSheet;
    dummy->SheetLength = 9;
    dummy->rotation = 0;
    dummy->scale = 2.5f;
    dummy->isActive = true;
    dummy->isPlayer = true;

    return(dummy);
}

internal vec2 
PlayerInputManager() 
{
    if(IsKeyDown(KEY_W)) 
    {
        Player->vel.y = -Player->movementSpeed;
    }  
    else if(IsKeyDown(KEY_S)) 
    {
        Player->vel.y = Player->movementSpeed;
    }
    else 
    {
        Player->vel.y = 0;
    }

    if(IsKeyDown(KEY_A)) 
    {
        Player->vel.x = -Player->movementSpeed;
    }
    else if(IsKeyDown(KEY_D)) 
    {
        Player->vel.x = Player->movementSpeed;
    }
    else 
    {
        Player->vel.x = 0;
    }
    Vector2Normalize(Player->vel);
    return(Player->vel);
}

void HandlePlayer() 
{
    if(Player == nullptr) 
    {
        PlayerSpriteSheet = CreateTextureFromFilepath("../data/res/textures/PlayerCharacter.png");
        Player = InitPlayerData();
    }
    vec2 NewVel = PlayerInputManager();
    Player->pos.x += NewVel.x * GetFrameTime();
    Player->pos.y += NewVel.y * GetFrameTime();

    Player->SrcRect = 
    {0, 0, (real32)(Player->Sprite.width/Player->SheetLength), (real32)(Player->Sprite.height)};
    Player->DstRect = 
    {Player->pos.x, Player->pos.y, Player->SrcRect.width * Player->scale, Player->SrcRect.height * Player->scale};

    DrawTexturePro(Player->Sprite, Player->SrcRect, Player->DstRect, {0, 0}, Player->rotation, WHITE);
}
