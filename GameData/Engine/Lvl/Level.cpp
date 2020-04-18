#include "Level.h"

bool LEVEL_PAUSED = false;

/*
 *  Level
 *
 *  DESC: Base class for all game levels, contains virtual functions
 *
 *  NOTE: UI Entities are separate in that they are rendered in a static view
 *
 *  USAGE: All levels inherit from this base class
 *          EX: Level 1() : public Level("Level_1", "background.png");
 */

Level::Level(string_t levelName, string_t background)
    : defaultView(sf::Vector2f(0, 0), sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT))
{
    this->levelName = levelName;
}

Level::~Level()
{
    for(std::vector<Entity*>::iterator i = entities.begin(),
            e = entities.end(); i != e; ++i)
        delete (*i);

    for(std::vector<Entity*>::iterator i = uiEntities.begin(),
                e = entities.end(); i != e; ++i)
        delete (*i);
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
    if (l_state == GameState::RUNNING)
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

    auto oldView = window->getView();

    window->setView(defaultView);

    MousePosition = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

    for(auto &e : uiEntities)
        e->render(window);

    window->setView(oldView);
}

void Level::handleInput(sf::Keyboard::Key key)
{
    if (l_state == GameState::RUNNING)
        for(auto &e : entities)
            e->handleInput(key);

    for(auto &e : uiEntities)
        e->handleInput(key);
}

void Level::handleInput(sf::Mouse::Button button)
{
    if (l_state == GameState::RUNNING)
        for(auto &e : entities)
            e->handleInput(button);

    for(auto &e : uiEntities)
        e->handleInput(button);
}