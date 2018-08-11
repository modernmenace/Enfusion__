#include "LevelManager.h"
#include "assert.h"

LevelManager* LevelManager::sInstance = nullptr;

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

Level& LevelManager::getCurrentLevel()
{
    return *this->currentLevel;
}