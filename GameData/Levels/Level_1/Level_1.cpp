#include "Level_1.h"

Level_1::Level_1() : Level("Level_1", "Levels/Level_1_back.png"),
                     player("Objects/mount1.png", sf::Vector2f(600, 300)),
                     map("Levels/testTiles.png")
{
    addEntity(&player);
}

void Level_1::initialize()
{
    Level::initialize();
    map.initialize();
}

void Level_1::render(sf::RenderWindow *window)
{
    map.render(window);
    Level::render(window);
}

void Level_1::handleInput(sf::Keyboard::Key key)
{
    player.handleInput(key);
}