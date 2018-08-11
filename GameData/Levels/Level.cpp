#include "Level.h"

Level::Level(std::string levelName, std::string background)
{
    this->levelName = levelName;
    this->background = AssetManager::getTexture(background);
}

//virtual functions (overridden)
void Level::initialize() {}
void Level::update() {}
void Level::render() {}