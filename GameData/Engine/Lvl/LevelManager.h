#ifndef ENFUSION_LEVELMANAGER_H
#define ENFUSION_LEVELMANAGER_H

#include "../Core/Engine.h"
#include "Level.h"
#include "../../Levels/Level_1/Level_1.h"

class LevelManager {

public:
    LevelManager(std::string initialLevel);

    Level& getCurrentLevel();

private:
    Level* currentLevel;

    static LevelManager* sInstance;

};

#endif //ENFUSION_LEVELMANAGER_H
