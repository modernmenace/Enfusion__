#include "Player.h"
#include "../Engine/Component/Anim/AnimatedSprite.h"
#include "../Engine/Component/Base/Position.h"
#include "../Engine/Component/Motion/AnimatedMovement.h"
#include "../Engine/Component/Misc/Camera.h"
#include "../Component/Inventory.h"
#include "../Engine/Lvl/LevelManager.h"

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