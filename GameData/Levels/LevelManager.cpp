#include "LevelManager.h"

LevelManager::LevelManager(std::string initialLevel)
{
    //need to find somewhere to store a map or vector or something of levels
    //here or Engine.h ??
}

Level& LevelManager::getCurrentLevel()
{
    return this->currentLevel;
}