#pragma once

#include "Shift_Main.h"

struct Entity 
{
// TRANSFORM DATA
    vec2 pos;
    vec2 vel;
    real32 accel;
    real32 friction;
    real32 movementSpeed;

  // RENDER DATA
    Texture2D Sprite;
    int SheetLength;
    Rectangle SrcRect;
    Rectangle DstRect;
    real32 rotation;
    real32 scale;
  // FLAGS
    bool isActive;
    bool isPlayer;
};
