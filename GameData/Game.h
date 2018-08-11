#ifndef ENFUSION_GAME_H
#define ENFUSION_GAME_H

#include <SFML/Graphics.hpp>
#include "Core/Engine.h"

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
    sf::RenderWindow mWindow;
    sf::Sprite testSprite;

};

#endif
