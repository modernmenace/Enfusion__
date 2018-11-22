#include "Level_1.h"

Level_1::Level_1() : Level("Level_1", "Levels/Level_1_back.png"), player("Objects/mount1.png", sf::Vector2f(600, 300))
{
    //TODO: pointers are required for new entities, try switching to a template to make this easier
    addEntity(&player);
}

void Level_1::handleInput(sf::Keyboard::Key key)
{
    player.handleInput(key);
}