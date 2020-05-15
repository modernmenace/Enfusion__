#include "Level_1.h"
#include "../../../Lvl/MapGenerator.h"

//TODO: Break level into chunks

Level_1::Level_1() : Level("Level_1", "Levels/Level_1_back.png"),
                     player("Objects/mount1.png", sf::Vector2f(600, 300)),
                     i_menu(&player),
                     p_menu(),
                     hotbar(&player, sf::Vector2f(-300, 350), &i_menu),
                     minimap(&player, this)
{
    addEntity(&player);
    addUIEntity(&minimap);
    addUIEntity(&i_menu);
    addUIEntity(&hotbar);
    addUIEntity(&p_menu);
    l_player = &player;

    //Debug Display
    #ifdef DEBUG_BUILD
    TextDisplay* debugText = new TextDisplay("Debug Build", sf::Vector2f(-950, -545), 30);
    playerPosDebugText     = new TextDisplay("(100, 100)", sf::Vector2f(-950, -510), 30);
    addUIEntity(debugText);
    addUIEntity(playerPosDebugText);
    #endif

    auto level = MapGenerator::Instance()->generateMap(250, 250);

    map = new Tilemap("Levels/mapgen.png", level, MapGenerator::Instance()->size(), 48);
    minimap.setTilemap(map);
}

void Level_1::initialize()
{
    Level::initialize();
    map->initialize();
    hotbar.updateSlots();

    auto p_posX = (rand()%(MapGenerator::Instance()->size().x * map[0].getTileSize())-1) + 1;
    auto p_posY = (rand()%(MapGenerator::Instance()->size().y * map[0].getTileSize())-1) + 1;
    player.getComponent<Position>().setPosition(sf::Vector2f(p_posX, p_posY));
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
    if (key == CONTROL("INVENTORY")
        && !p_menu.active())
            i_menu.toggleMenu();

    if (key == CONTROL("PAUSE")
        && !i_menu.active())
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