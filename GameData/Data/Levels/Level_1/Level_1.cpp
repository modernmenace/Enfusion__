#include "Level_1.h"
#include "../../../Lvl/MapGenerator.h"

#if DEBUG_ENABLE_DEBUG_MENU == 1
#include "../../../Engine/Component/Misc/Camera.h"
#endif

/************************************************************************
 * FUNCTION :       Level_1::Level_1
 *
 * DESCRIPTION :
 *       Level constructor, set up objects
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.25 	    JCB     Documentation Start
 *
 ************************************************************************/

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

/************************************************************************
 * FUNCTION :       Level_1::initialize
 *
 * DESCRIPTION :
 *       Initialize the level and generate the map
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.25 	    JCB     Documentation Start
 *
 ************************************************************************/

void Level_1::initialize()
{
    Level::initialize();
    map->initialize();
    hotbar.updateSlots();

    auto p_posX = (rand()%(MapGenerator::Instance()->size().x * map[0].getTileSize())-1) + 1;
    auto p_posY = (rand()%(MapGenerator::Instance()->size().y * map[0].getTileSize())-1) + 1;
    player.getComponent<Position>().setPosition(sf::Vector2f(p_posX, p_posY));

    #if DEBUG_ENABLE_DEBUG_MENU == 1
    dbg_playerPosText  = new TextDisplay("Test", sf::Vector2f(-950, -530), 12);
    dbg_viewBoundsText = new TextDisplay("Test2", sf::Vector2f(-950, -510), 12);
    dbg_playerPosText->initialize();
    dbg_viewBoundsText->initialize();
    dbg_playerPosText->setVisible(false);
    dbg_viewBoundsText->setVisible(false);
    dbg_menuVisible = false;
    addUIEntity(dbg_playerPosText);
    addUIEntity(dbg_viewBoundsText);
    #endif
}

/************************************************************************
 * FUNCTION :       Level_1::update
 *
 * DESCRIPTION :
 *       Called every tick, update debug menu and check for collisions (temp)
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.25 	    JCB     Documentation Start
 *
 ************************************************************************/

void Level_1::update(sf::Time tickRate)
{
    Level::update(tickRate);

    #if DEBUG_ENABLE_DEBUG_MENU == 1
    if (dbg_menuVisible)
    {
        auto p_pos = player.getComponent<Position>().getPosition();
        dbg_playerPosText->setText("Player Position: (" + std::to_string(p_pos.x) + ", " + std::to_string(p_pos.y) + ")");
        auto c_view = player.getComponent<Camera>().getCameraView();
        dbg_viewBoundsText->setText("Camera View: (" + std::to_string(c_view.top) + "t, "
            + std::to_string(c_view.left) + "l, " + std::to_string(c_view.width) + "w, " + std::to_string(c_view.height) + "h)");
    }
    #endif

    //check for collisions
    //todo: this is inefficient, implement quadtrees for nearby
    //todo: may also help when split into chunks
    if (player.isMoving())
    {
        for(StaticMapObject* o : map->map()->m_mapObjects)
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

/************************************************************************
 * FUNCTION :       Level_1::handleInput
 *
 * DESCRIPTION :
 *       Process control input
 *
 *  INPUTS:  Key key : key that was pressed
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.25 	    JCB     Documentation Start
 *
 ************************************************************************/

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

    #if DEBUG_ENABLE_DEBUG_MENU == 1
    //keycode 85 = F1
    if (key == 85)
    {
        dbg_playerPosText->setVisible(!dbg_playerPosText->visible());
        dbg_viewBoundsText->setVisible(!dbg_viewBoundsText->visible());
        dbg_menuVisible = !dbg_menuVisible;
    }
    #endif

    Level::handleInput(key);
}

/************************************************************************
 * FUNCTION :       Level_1::render
 *
 * DESCRIPTION :
 *       Render level objects
 *
 *  INPUTS:  RenderWindow* window : window to render to
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.25 	    JCB     Documentation Start
 *
 ************************************************************************/

void Level_1::render(sf::RenderWindow *window)
{
    map->render(window);
    Level::render(window);
}