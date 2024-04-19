#pragma once 

#include "util/Standards.h"
#include "shift_Data.h"

internal void initGameData();
internal void updateGame();

inline Texture2D 
createTextureFromImage(const char *filepath) 
{
  Image image = LoadImage(filepath);
  Texture2D texture = LoadTextureFromImage(image);

  UnloadImage(image);

  return(texture);
}
