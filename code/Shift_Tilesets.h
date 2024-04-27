#pragma once

#include "Shift_Main.h"
#include "Shift_Entity.h"
#include "Shift_Player.h"
#include "Shift_Tilesets.h"

void DrawTileMap(void);
void InitFloorTexture();

struct Tiles 
{
    Texture2D FloorTexture;
    vec2i TileSize;
    vec2i Tilepos;
    Rectangle TextureSrc;
    Rectangle TextureDst;
};
