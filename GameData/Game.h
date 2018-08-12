#ifndef ENFUSION_GAME_H
#define ENFUSION_GAME_H

#include <SFML/Graphics.hpp>
#include "Engine/Core/Engine.h"
#include "Engine/Lvl/LevelManager.h"

#define LEVEL levelManager.getCurrentLevel()

class Game {

public:
    Game();
    void run();

private:
    void initialize();
    void processEvents();
    void update();
    void render();

    AssetManager manager;
    LevelManager levelManager;

    sf::RenderWindow mWindow;

};

#endif
