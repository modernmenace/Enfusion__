#include "LevelManager.h"
#include "assert.h"

/*
 *  Level Manager
 *
 *  DESC: Handles level related logic, such as switching between levels
 *        and storing the current level
 *
 *  NOTE: There can only be one instance of Level Manager at one time
 *
 */

LevelManager* LevelManager::sInstance = nullptr;

/*
 *  Constructor
 *
 *  DESC: Takes the initial level's name as an argument and loads it
 *
 *  NOTE: This is currently harcoded with the level names, this NEEDS
 *        to be changed to make the engine more modular
 *
 */

LevelManager::LevelManager(std::string initialLevel)
{
    assert(sInstance == nullptr);
    sInstance = this;

    //maybe eventually move to some kind of map here
    //hardcoded for now, need good method of checking level names dynamically
    if (initialLevel == "Level_1")
    {
        dbg_log("LevelManager: Level_1 loaded.");
        this->currentLevel = new Level_1();
    }
    else
    {
        dbg_err("INVALID LEVEL '" + initialLevel + "'");
    }
}

/*
 *  Get Current Level
 *
 *  DESC: Returns the address of the current level
 *
 */

Level& LevelManager::getCurrentLevel()
{
    return *this->currentLevel;
}