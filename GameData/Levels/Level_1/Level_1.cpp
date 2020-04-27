#include "Level_1.h"
#include "../../../GameData/Engine/Lvl/MapGenerator.h"

//TODO: Break level into chunks

Level_1::Level_1() : Level("Level_1", "Levels/Level_1_back.png"),
                     player("Objects/mount1.png", sf::Vector2f(600, 300)),
                     i_menu(&player),
                     p_menu(),
                     hotbar(&player, sf::Vector2f(-300, 350), &i_menu),
                     minimap()
{
    addEntity(&player);
    addUIEntity(&minimap);
    addUIEntity(&i_menu);
    addUIEntity(&hotbar);
    addUIEntity(&p_menu);

    //Debug Display
    #ifdef DEBUG_BUILD
    TextDisplay* debugText = new TextDisplay("Debug Build", sf::Vector2f(-950, -545), 30);
    playerPosDebugText     = new TextDisplay("(100, 100)", sf::Vector2f(-950, -510), 30);
    addUIEntity(debugText);
    addUIEntity(playerPosDebugText);
    #endif

    auto level = MapGenerator::Instance()->generateMap(500, 500);

    map = new Tilemap("Levels/mapgen.png", level, MapGenerator::Instance()->size(), 48);
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