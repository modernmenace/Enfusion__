#include "Level_1.h"

Level_1::Level_1() : Level("Level_1", "Levels/Level_1_back.png"),
                     player("Objects/mount1.png", sf::Vector2f(600, 300))
{
    addEntity(&player);

    //Debug Display
    #ifdef DEBUG_BUILD
    TextDisplay* debugText = new TextDisplay("Debug Build", sf::Vector2f(700, -525));
    playerPosDebugText     = new TextDisplay("(100, 100)", sf::Vector2f(700, -485));
    addUIEntity(debugText);
    addUIEntity(playerPosDebugText);
    #endif

    const int level[] =
            {
                    69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
                    69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
                    69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
                    69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
                    69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
                    69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
                    69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
                    69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
                    69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69
            };

    map = new Tilemap("Levels/GrasslandColor2@128x128.png", level, 12, 9);
}

void Level_1::initialize()
{
    Level::initialize();
    map->initialize();
}

void Level_1::update(sf::Time tickRate)
{
    #ifdef DEBUG_BUILD
    auto playerPos = player.getComponent<Position>().getPosition();
    playerPosDebugText->setText(std::string("(") + std::to_string((int)playerPos.x)
            + std::string(", ") + std::to_string((int)playerPos.y) + std::string(")"));
    #endif
    Level::update(tickRate);
}

void Level_1::render(sf::RenderWindow *window)
{
    map->render(window);
    Level::render(window);
}

void Level_1::handleInput(sf::Keyboard::Key key)
{
    player.handleInput(key);
}