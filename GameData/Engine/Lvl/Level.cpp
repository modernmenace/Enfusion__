#include "Level.h"

/*
 *  Level
 *
 *  DESC: Base class for all game levels, contains virtual functions
 *
 *  NOTE: This class will definitely be expanded in the future
 *
 *  USAGE: All levels inherit from this base class
 *          EX: Level 1() : public Level("Level_1", "background.png");
 */

Level::Level(std::string levelName, std::string background)
    : defaultView(sf::Vector2f(0, 0), sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT))
{
    this->levelName = levelName;
    //TODO: Figure out if we want to keep this background or remove it entirely
    //this->background.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    //this->background.setTexture(&AssetManager::getTexture(background));
}

void Level::initialize()
{
    for(auto &e : entities)
        e->initialize();

    for (auto &e : uiEntities)
        e->initialize();
}

void Level::update(sf::Time tickRate)
{
    for(auto &e : entities)
        e->update(tickRate);

    for (auto &e : uiEntities)
        e->update(tickRate);
}

void Level::render(sf::RenderWindow* window)
{
    window->draw(background);

    for(auto &e : entities)
        e->render(window);

    //window->setView(defaultView);

    //for(auto &e : uiEntities)
    //    e->render(window);
}

void Level::handleInput(sf::Keyboard::Key key) {}