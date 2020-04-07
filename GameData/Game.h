#ifndef ENFUSION_GAME_H
#define ENFUSION_GAME_H

#include <SFML/Graphics.hpp>
#include "Engine/Core/Engine.h"
#include "Engine/Lvl/LevelManager.h"
#include "Data/Items.h"

#define LEVEL LevelManager::Instance()->getCurrentLevel()

class Game {

public:
    Game();
    void run();

private:
    void initialize();
    void processEvents();
    void update(sf::Time tickRate);
    void render();

    sf::RenderWindow mWindow;

};

#endif
