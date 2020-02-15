#ifndef ENFUSION_GAME_H
#define ENFUSION_GAME_H

#include <SFML/Graphics.hpp>
#include "Engine/Core/Engine.h"
#include "Engine/Lvl/LevelManager.h"
#include "Engine/Misc/ItemRegistry.h"
#include "Data/Items.h"

#define LEVEL levelManager.getCurrentLevel()

class Game {

public:
    Game();
    void run();

private:
    void initialize();
    void processEvents();
    void update(sf::Time tickRate);
    void render();

    AssetManager manager;
    LevelManager levelManager;
    ItemRegistry itemRegistry;

    sf::RenderWindow mWindow;

};

#endif
