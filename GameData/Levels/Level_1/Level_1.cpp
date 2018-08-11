#include "Level_1.h"

Level_1::Level_1() : Level("Level_1", "Levels/Level_1_back.png"), player("TestChar.png", sf::Vector2f(600, 300))
{

}

void Level_1::initialize()
{

}

void Level_1::update()
{
    player.update();
}

void Level_1::render(sf::RenderWindow* window)
{
    Level::render(window);
    player.render(window);
}

void Level_1::handleInput(sf::Keyboard::Key key)
{
    player.handleInput(key);
}