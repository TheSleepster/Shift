#pragma once

#include "shift_Main.h"

// ANIMATION DATA
struct Animation 
{
  int8 animationLength;
  int8 currentFrame;
  int8 frameDelay;
  int8 currentTime;
};

enum AnimationIndex 
{
  pIdle = 0,
  pWalking = 1,
};

const int AnimationCounter = 2;
global_variable Animation Animations[AnimationCounter];

// FLAGS
struct EntityFlags 
{
  bool isActive;
  bool isAnimated;
  bool isPlayer;
  bool isAI;
  bool isEnvironment;
  bool isInMotion;
  bool isInterrupted;
};

// GENERIC ENTITY (others derive from this)
struct Entity 
{
// FLAG DATA
EntityFlags entityFlags;

//ANIMATION DATA
  Animation *Animations;
  Texture2D sprite;
  uint8 sheetLength;
  uint8 animationCounter;

//RENDER DATA  
  Rectangle srcRect;
  Rectangle dstRect;
  real32 rotation;
  real32 scale;

//POSITION DATA  
  vec2 pos;
  vec2 vel;
  real32 movementSpeed;

//HEALTH DATA
  int maxHealth;
  int currentHealth;
};

internal Entity *initPlayer(Texture2D playerTexture);
void handlePlayerData(Texture2D playerTexture);
internal vec2 handlePlayerMovement();
internal void updatePlayer();

void createAnimations(); 
void playAnimation(Entity *entity, enum AnimationIndex animation); 
