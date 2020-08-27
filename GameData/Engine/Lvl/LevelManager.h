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

    inline sf::Vector2i boundaries() { return m_levelBoundaries; }
    inline void setBoundaries(sf::Vector2i b) { m_levelBoundaries = b; };

private:
    LevelManager() {};

    Level*               m_currentLevel;
    static LevelManager* m_Instance;
    Player*              m_player = nullptr;
    sf::Vector2i         m_levelBoundaries;

};

#endif //ENFUSION_LEVELMANAGER_H
