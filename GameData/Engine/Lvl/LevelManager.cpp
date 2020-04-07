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

LevelManager* LevelManager::m_Instance = nullptr;

LevelManager* LevelManager::Instance()
{
    if (m_Instance == nullptr)
        m_Instance = new LevelManager();

    return m_Instance;
}

void LevelManager::setLevel(std::string level)
{
    //maybe eventually move to some kind of map here
    //hardcoded for now, need good method of checking level names dynamically
    assert(m_Instance != nullptr);

    if (level == "Level_1")
    {
        dbg_log("LevelManager: Level_1 loaded.");
        this->currentLevel = new Level_1();
    }
    else
    {
        dbg_err("INVALID LEVEL '" + level + "'");
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
    assert(m_Instance != nullptr);
    return *this->currentLevel;
}