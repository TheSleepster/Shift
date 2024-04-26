#include "Shift_Main.h"
#include "Shift_Entity.h"
#include "Shift_Player.h"
#include "Shift_Tilesets.h"

void HandleWorldData() 
{
    const int TilemapWidth = 17;
    const int TilemapHeight = 17;

    enum TileType 
    {
        EmptyTile,
        FloorTile,
        WallTile,
        PlayerTile,
    };

    vec2 TileSizeInPixels = {10, 10}; 
    uint32 Tilemap[TilemapWidth][TilemapHeight] = 
    {
    }; 
}
