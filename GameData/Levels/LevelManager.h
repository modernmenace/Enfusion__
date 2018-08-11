#ifndef ENFUSION_LEVELMANAGER_H
#define ENFUSION_LEVELMANAGER_H

#include "../Core/Engine.h"
#include "Level.h"
#include "Level_1/Level_1.h"

static class LevelManager {

public:
    LevelManager(std::string initialLevel);

    Level& getCurrentLevel();

private:
    Level currentLevel;

};

#endif //ENFUSION_LEVELMANAGER_H
