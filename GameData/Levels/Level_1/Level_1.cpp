#include "Level_1.h"

Level_1::Level_1() : Level("Level_1", "Levels/Level_1_back.png"), player("Objects/mount1.png", sf::Vector2f(600, 300))
{
    //TODO: pointers are required for new entities, try switching to a template to make this easier
    Agent* a = new Agent("AI/Enemy_Wizard.png", sf::Vector2f(100, 100));
    entities.emplace_back(&player);
    entities.emplace_back(a);
}

void Level_1::initialize()
{
    for(auto &e : entities)
        e->initialize();
}

void Level_1::update(sf::Time tickRate)
{
    for(auto &e : entities)
        e->update(tickRate);
}

void Level_1::render(sf::RenderWindow* window)
{
    Level::render(window);

    for(auto &e : entities)
        e->render(window);
}

void Level_1::handleInput(sf::Keyboard::Key key)
{
    player.handleInput(key);
}