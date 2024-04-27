#include "Shift_Main.h"
#include "Shift_Entity.h"
#include "Shift_Player.h"
#include "Shift_Tilesets.h"

global_variable Texture2D FloorTileTexture;
global_variable Texture2D Dummy;

void InitFloorTexture() 
{
    FloorTileTexture = CreateTextureFromFilepath("../data/res/textures/walls.png");
}

void DrawTileMap(void) 
{
    Tiles FloorTile;
    Tiles Wall1Tile;
        
    enum TileType 
    {
        Empty,
        Floor1,
        Wall1,
        Player,
    };

    const int TilemapSizeX = 9;
    const int TilemapSizeY = 17;
    
    int32 Tilemap[TilemapSizeX][TilemapSizeY] = 
    {
        {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1},
        {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 1},
        {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 1},
        {1,0,0,0, 1,1,1,0, 0,0,1,0, 0,0,0,0, 1},
        {1,0,0,0, 1,0,0,0, 0,0,1,0, 0,0,0,0, 1},
        {1,0,0,0, 1,0,0,0, 0,0,1,0, 0,0,0,0, 1},
        {1,0,0,0, 1,0,0,0, 0,0,1,0, 0,0,0,0, 1},
        {1,0,0,0, 1,0,0,0, 0,0,1,0, 0,0,0,0, 1},
        {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1} 
    };
    
    for(int Row = 0; Row < TilemapSizeX; ++Row) 
    {
        for(int Column = 0; Column < TilemapSizeY; ++Column) 
        {
            switch(Tilemap[Row][Column]) 
            {
                case 0: 
                {
                    DrawTexturePro(); 
                }break;
                case 1:
                {

                }break;
            }
        }
    }
}
