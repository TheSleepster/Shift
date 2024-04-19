#include "shift_Main.h"
#include "shift_Data.h"

// TODO : This entire file is pretty much unneeded, move the contents of the "createAnimations" function into Init() in main
// then move "playAnimation" into main.h as an inline

void createAnimations() 
{
// TODO : use this function to create animations and have the index of the array correltate with that of the 
// enum number that's used to describe it. For example, Idle = 0 and is located at Animations[0]. Therefore whenever
// playAnimation(Idle) is called, it will simple pass the data relating to that animation too the function and play it.
  
  Animations[pIdle] = {2, 0, 90, 0};
  Animations[pWalking] = {4, 5, 50, 0};
}

void playAnimation(Entity *entity, enum AnimationIndex animation) 
{
  // TODO : play the animation related to this passed enum. Do this by indexing the array for a value that will bring
  // the animations data back to this function.
  Animation playedAnimation = Animations[animation];

  playedAnimation.animationLength = Animations[animation].animationLength;
  playedAnimation.currentFrame = Animations[animation].currentFrame;
  playedAnimation.frameDelay = Animations[animation].frameDelay;
  playedAnimation.currentTime = Animations[animation].currentTime;

  entity->srcRect = {(real32)((entity->sprite.width / entity->sheetLength) * playedAnimation.currentFrame), 
                    0, (real32)(entity->sprite.width / entity->sheetLength), (real32)entity->sprite.height};
  playedAnimation.currentTime++;

// for loop instead?  
  if(playedAnimation.currentTime >= playedAnimation.frameDelay) 
  {
    playedAnimation.currentFrame++;
    playedAnimation.currentTime = 0;
  }

  if(playedAnimation.currentFrame >= playedAnimation.animationLength) 
  {
    playedAnimation.currentFrame = 0;
  }
}
