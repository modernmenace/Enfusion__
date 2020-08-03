#ifndef ENFUSION_LEVELMANAGER_H
#define ENFUSION_LEVELMANAGER_H

#include "../Core/Engine.h"
#include "Level.h"
#include "../../Data/Levels/Level_1/Level_1.h"

class LevelManager {

public:
    static LevelManager* Instance();
    void setLevel(std::string level);
    void setPlayer(Player*);
    Level& getCurrentLevel();

private:
    LevelManager() {};

    Level*               m_currentLevel;
    static LevelManager* m_Instance;
    Player*              m_player = nullptr;

};

#endif //ENFUSION_LEVELMANAGER_H
