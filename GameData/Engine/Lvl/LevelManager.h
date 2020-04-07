#ifndef ENFUSION_LEVELMANAGER_H
#define ENFUSION_LEVELMANAGER_H

#include "../Core/Engine.h"
#include "Level.h"
#include "../../Levels/Level_1/Level_1.h"

class LevelManager {

public:
    static LevelManager* Instance();
    void setLevel(std::string level);
    Level& getCurrentLevel();

private:
    LevelManager() {};

    Level* currentLevel;
    static LevelManager* m_Instance;

};

#endif //ENFUSION_LEVELMANAGER_H
