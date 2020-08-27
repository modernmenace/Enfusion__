#include "Level_1.h"
#include "../../../Lvl/MapGenerator.h"

//TODO: Break level into chunks

Level_1::Level_1() : Level("Level_1", "Levels/Level_1_back.png"),
                     player(sf::Vector2f(600, 300)),
                     i_menu(&player),
                     p_menu(),
                     hotbar(&player, sf::Vector2f(-300, 350), &i_menu),
                     minimap(&player, this),
                     q_display()
{
    addEntity(&player);
    addUIEntity(&minimap);
    addUIEntity(&q_display);
    addUIEntity(&i_menu);
    addUIEntity(&hotbar);
    addUIEntity(&p_menu);
    l_player = &player;

    auto level = MapGenerator::Instance()->generateMap(250, 250, 16);

    map = new Tilemap("Levels/terrain.png", level, MapGenerator::Instance()->size(), 16);
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
    Level::update(tickRate);

    //check for collisions
    //todo: this is inefficient, implement quadtrees for nearby
    //todo: may also help when split into chunks
    if (player.isMoving())
    {
        for(StaticMapObject* o : *MapGenerator::Instance()->staticMapObjects())
        {
            if (o->blocksMovement())
            {
                if (o->bounds().intersects(*player.collider()))
                {
                    player.stopMovement();
                }
            }
        }
    }

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
    MapGenerator::Instance()->render(window);
    Level::render(window);
}