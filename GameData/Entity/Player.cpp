#include "Player.h"
#include "../Engine/Component/Anim/AnimatedSprite.h"
#include "../Engine/Component/Base/Position.h"
#include "../Engine/Component/Motion/AnimatedMovement.h"
#include "../Engine/Component/Misc/Camera.h"
#include "../Component/Inventory.h"
#include "../Engine/Lvl/LevelManager.h"
#include "../Lvl/MapGenerator.h"
#include <cmath>

/************************************************************************
 * FUNCTION :       Player::Player
 *
 * DESCRIPTION :
 *       Constructor, set up components
 *
 *  INPUTS:  sf::Vector2f position | Starting position
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.27 	    JCB     Documentation Start
 *
 ************************************************************************/

Player::Player(sf::Vector2f position)
{
    addComponent<Position>(position);
    addComponent<AnimatedSprite>("Objects/chara2.png", 4, 3, sf::IntRect(0, 0, 78, 146), sf::Vector2i(1, 0));
    addComponent<Camera>(CameraType::FOLLOW);
    addComponent<AnimatedMovement>(true);
    addComponent<Inventory>();

    //todo: set initial tile (p_tile)
    //todo: map pointer stored in mapgenerator
    /*
     * pos.x = 0; pos.y = 0;
    for(uint32_t i = 0; i < (sizeX * sizeY); i++)
    {
        if (pos.x++ == sizeX)
        {
            pos.y++;
            pos.x = 0;
        }
        if (m_lvl[i].biome == LEVEL_BIOME_ID_NONE)
        {
            sf::Vector2f tempPos;
            tempPos.x = pos.x * 32;
            tempPos.y = pos.y * 32;
            BiomeManager::Instance()->biome(m_lvl[i-1].biome)->createTransitionTile(&m_lvl[i], tempPos, m_lvl[i-1].biome);
        }
    }
     */

    LevelManager::Instance()->setPlayer(this);
}

void Player::initialize()
{
    Entity::initialize();
    sf::Vector2f pos = getComponent<Position>().getPosition();
    uint16_t px = ceil(pos.x);
    uint16_t py = ceil(pos.y);
    uint32_t aPos = ((py / 32) * 250)+(px / 32);
    p_tile = &MapGenerator::Instance()->map()->m_tiles[aPos];
}

/************************************************************************
 * FUNCTION :       Player::bounds
 *
 * DESCRIPTION :
 *       Returns sprite bounds
 *
 *  INPUTS:  sf::Vector2f position | Starting position
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.27 	    JCB     Documentation Start
 *
 ************************************************************************/

sf::FloatRect Player::bounds()
{
    return getComponent<AnimatedSprite>().getSprite().getGlobalBounds();
}

/************************************************************************
 * FUNCTION :       Player::currentPosition
 *
 * DESCRIPTION :
 *       Returns current absolute position
 *
 *  INPUTS:  sf::Vector2f position | Starting position
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.27 	    JCB     Documentation Start
 *
 ************************************************************************/

sf::Vector2f Player::currentPosition()
{
    return getComponent<AnimatedSprite>().getSprite().getPosition();
}

/************************************************************************
 * FUNCTION :       Player::isMoving
 *
 * DESCRIPTION :
 *       Returns movement status
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: bool : movement status
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.27 	    JCB     Documentation Start
 *
 ************************************************************************/

bool Player::isMoving()
{
    return getComponent<AnimatedMovement>().isMoving();
}