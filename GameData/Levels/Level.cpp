#include "Level.h"

Level::Level(std::string levelName, std::string background)
{
    this->levelName = levelName;
    this->background.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    this->background.setTexture(&AssetManager::getTexture(background));
}

//virtual functions (overridden)
void Level::initialize() {}
void Level::update() {}
void Level::render(sf::RenderWindow* window)
{
    window->draw(background);
}