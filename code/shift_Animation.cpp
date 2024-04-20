#include "shift_Main.h"
#include "shift_Data.h"

// TODO : This entire file is pretty much unneeded, move the contents of the "createAnimations" function into Init() in main
// then move "playAnimation" into main.h as an inline

void createAnimations() 
{
// TODO : use this function to create animations and have the index of the array correltate with that of the 
// enum number that's used to describe it. For example, Idle = 0 and is located at Animations[0]. Therefore whenever
// playAnimation(Idle) is called, it will simple pass the data relating to that animation too the function and play it.
  
  Animations[pIdle] = {2, 0, 100, 0};
  Animations[pWalking] = {4, 4, 50, 0};
}

void playAnimation(Entity *entity, enum AnimationIndex animation) 
{
  global_variable Animation pAnimation = Animations[animation];
  // TODO : play the animation related to this passed enum. Do this by indexing the array for a value that will bring
  // the animations data back to this function.
  
  pAnimation.currentTime++;
  if(pAnimation.currentTime >= pAnimation.frameTime) 
  {
    pAnimation.currentFrame++;
    pAnimation.currentTime = 0;
    if(pAnimation.currentFrame >= pAnimation.animationLength) 
    {
      pAnimation.currentFrame = Animations[animation].currentFrame;
    }
  }
  real32 animOffset = (real32)(entity->sprite.width / entity->sheetLength) * pAnimation.currentFrame;
  entity->srcRect.x = {animOffset};

  DrawTexturePro(entity->sprite, entity->srcRect, entity->dstRect, {0, 0}, entity->rotation, WHITE);
}

// TODO : Investigate the possibility of an Animation State Machine as an alternative for this awfulness
