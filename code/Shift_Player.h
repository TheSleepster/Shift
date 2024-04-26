#pragma once

#include "Shift_Main.h"
#include "Shift_Entity.h"

global_variable Entity* Player = nullptr;
enum PlayerAnimationState {Idle, Walking}; 

void HandlePlayer();
internal Entity *InitPlayerData();
