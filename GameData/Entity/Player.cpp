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

    LevelManager::Instance()->setPlayer(this);
}

void Player::initialize()
{
    Entity::initialize();
    sf::Vector2f pos = getComponent<Position>().getPosition();
    uint32_t aPos = resolvePositionToTile(pos.x, pos.y);
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