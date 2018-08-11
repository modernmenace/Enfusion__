#include "Level_1.h"

Level_1::Level_1() : Level("Level_1", "Levels/Level_1_back.png")
{

}

void Level_1::initialize()
{

}

void Level_1::update()
{

}

void Level_1::render(sf::RenderWindow* window)
{
    Level::render(window);
    auto testSprite = sf::Sprite(AssetManager::getTexture("TestChar.png"));
    window->draw(testSprite);
}