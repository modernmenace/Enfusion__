#include "Level_1.h"

Level_1::Level_1() : Level("Level_1", "Levels/Level_1_back.png"),
                     player("Objects/mount1.png", sf::Vector2f(600, 300)),
                     i_menu(&player),
                     p_menu(),
                     hotbar(&player, sf::Vector2f(-300, 350), &i_menu)
{
    addEntity(&player);
    addUIEntity(&i_menu);
    addUIEntity(&hotbar);
    addUIEntity(&p_menu);

    //Debug Display
    #ifdef DEBUG_BUILD
    TextDisplay* debugText = new TextDisplay("Debug Build", sf::Vector2f(730, -545), 30);
    playerPosDebugText     = new TextDisplay("(100, 100)", sf::Vector2f(730, -520), 30);
    addUIEntity(debugText);
    addUIEntity(playerPosDebugText);
    #endif

    const int level[] =
            {
                    69, 69, 70, 69, 69, 69, 69, 69, 69, 69, 69, 69,
                    69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 70, 69,
                    69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
                    69, 69, 69, 70, 69, 69, 69, 69, 69, 69, 69, 69,
                    69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
                    69, 69, 69, 69, 69, 69, 70, 69, 69, 69, 69, 69,
                    69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
                    69, 69, 69, 69, 70, 69, 69, 69, 69, 69, 69, 69,
                    70, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69
            };

    map = new Tilemap("Levels/GrasslandColor2@128x128.png", level, 12, 9);
}

void Level_1::initialize()
{
    Level::initialize();
    map->initialize();

    hotbar.updateSlots();
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

void Level_1::handleInput(sf::Keyboard::Key key)
{
    if (key == 60 && !p_menu.active()) i_menu.toggleMenu();
    if (key == 36 && !i_menu.active())
    {
        p_menu.toggleMenu();
        if (l_state == GameState::RUNNING)
            l_state = GameState::PAUSE;
        else
            l_state = GameState::RUNNING;
    }
    Level::handleInput(key);
}

void Level_1::render(sf::RenderWindow *window)
{
    map->render(window);
    Level::render(window);
}