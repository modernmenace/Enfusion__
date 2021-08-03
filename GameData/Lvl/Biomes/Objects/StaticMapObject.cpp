#include "StaticMapObject.h"
#include "../../LvlStructs.h"
#include "../../../Engine/Lvl/LevelManager.h"
#include "../../../Engine/Component/Misc/Camera.h"
#include "../../../Engine/Component/Anim/AnimatedSprite.h"
#include "../../../Engine/Component/Base/Z.h"

/************************************************************************
 * FUNCTION :       StaticMapObject::StaticMapObject
 *
 * DESCRIPTION :
 *       Constructor
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.07.25 	    JCB     Documentation Start
 *
 ************************************************************************/

StaticMapObject::StaticMapObject(const StaticMapObject &obj) : StaticMapObject(obj.o_tileset, obj.o_bounds) { }
StaticMapObject::StaticMapObject(string_t tileset, sf::IntRect texBounds) : o_sprite()
{
    o_sprite.setTexture(AssetManager::Instance()->getTexture(tileset));
    o_bounds = texBounds;
    o_tileset = tileset;
    o_sprite.setScale(GLOBAL_SCALE_GAMEOBJECT);
    o_sprite.setTextureRect(o_bounds);
    o_tileWidth  = (unsigned int)(o_sprite.getGlobalBounds().width / 32)  + 1;
    o_tileHeight = (unsigned int)(o_sprite.getGlobalBounds().height / 32) + 1;

    addComponent<Z>(Z_BOTTOM);
}

/************************************************************************
 * FUNCTION :       StaticMapObject::setPosition
 *
 * DESCRIPTION :
 *       Sets the object's position to a tile location
 *
 *  INPUTS:  Tile& tile : The tile to be placed at
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.07.25 	    JCB     Documentation Start
 *
 ************************************************************************/

void StaticMapObject::setPosition(Tile& tile)
{
    o_tile = &tile;
    o_sprite.setPosition(o_tile->position);
    sf::Rect<uint32_t> occTiles = resolvePositionRectToTileRect(o_sprite.getGlobalBounds());

    //below code for blocking whole sprite
    /*
    for(int i = 0; i < occTiles.width; i++)
    {
        for(int j = 0; j < occTiles.height; j++)
        {
            uint32_t arrayPos = occTiles.top + i + (j * 250);
            if (arrayPos > MapGenerator::Instance()->map()->m_tiles.size())
                continue;
            MapGenerator::Instance()->map()->m_tiles[arrayPos].blocked = true;
        }
    }
     */
    o_tiles = occTiles;
}

/************************************************************************
 * FUNCTION :       StaticMapObject::center
 *
 * DESCRIPTION :
 *       Returns the center of the object in global coordinates
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: sf::Vector2u : The tile's center point
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.07.25 	    JCB     Documentation Start
 *
 ************************************************************************/

sf::Vector2u StaticMapObject::center()
{
    sf::Vector2u center;

    sf::FloatRect gBounds = o_sprite.getGlobalBounds();

    center.x = gBounds.left + (gBounds.width / 2);
    center.y = gBounds.top  - (gBounds.height / 2);

    return center;
}

/************************************************************************
 * FUNCTION :       StaticMapObject::render
 *
 * DESCRIPTION :
 *       Renders the object
 *
 *  INPUTS:  sf::RenderWindow *window : pointer to the render window
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.07.25 	    JCB     Documentation Start
 *
 ************************************************************************/


void StaticMapObject::render(sf::RenderWindow *window)
{
    if (o_inView)
        window->draw(o_sprite);
}

/************************************************************************
 * FUNCTION :       StaticMapObject::update
 *
 * DESCRIPTION :
 *       Update, check for events
 *
 *  INPUTS:  sf::Time tickRate : The current tick rate
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.08.01	    JCB     Documentation Start
 *
 ************************************************************************/

void StaticMapObject::update(sf::Time tickRate)
{
    Player* player = LevelManager::Instance()->getCurrentLevel().player();

    // TODO: Minimize calls to these?
    sf::FloatRect pView   = player->getComponent<Camera>().getCameraView();
    sf::Vector2u  pCenter = player->getComponent<AnimatedSprite>().center();

    // Only update if in view
    if (pView.intersects(bounds()))
    {
        o_inView = true;

        //TODO: this isnt working, and is slow?
        //TODO: probably not working because sort is never called on Level
        //TODO: on level have flag and sue levelmanager to change it from Z comp
        if (pCenter.y > zOrderBoundary())
            getComponent<Z>().setZ(player->z() - 1);
        else
            getComponent<Z>().setZ(player->z() + 1);

        //TODO: check for player collision and direct to function below

    }
    else
    {
        o_inView = false;
    }
}

/************************************************************************
 * FUNCTION :       StaticMapObject::collideWithPlayer
 *
 * DESCRIPTION :
 *       Update, check for events
 *
 *  INPUTS:  Player& player : Pointer to the player object
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.08.01	    JCB     Documentation Start
 *
 ************************************************************************/

void StaticMapObject::collideWithPlayer(Player& player)
{
    // Handle player collisions
}

/************************************************************************
 * FUNCTION :       StaticMapObject::zOrderBoundary
 *
 * DESCRIPTION :
 *       Return's the y boundary determining the z-order
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: uint16_t boundary : the y-boundary
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.07.25 	    JCB     Documentation Start
 *
 ************************************************************************/

uint16_t StaticMapObject::zOrderBoundary()
{
    return center().y;
}