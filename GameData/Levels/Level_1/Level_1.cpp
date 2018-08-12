#include "Level_1.h"

Level_1::Level_1() : Level("Level_1", "Levels/Level_1_back.png"), player("Player.png", sf::Vector2f(600, 300))
{

}

void Level_1::initialize()
{
    ai.push_back(Agent("Enemy_Wizard.png", sf::Vector2f(800, 100)));
}

void Level_1::update()
{
    player.update();
}

void Level_1::render(sf::RenderWindow* window)
{
    Level::render(window);
    player.render(window);

    //render ai
    for(int i = 0; i < ai.size(); i++)
        ai.at(i).render(window);
}

void Level_1::handleInput(sf::Keyboard::Key key)
{
    player.handleInput(key);
}