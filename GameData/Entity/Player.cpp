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
    addComponent<AnimatedSprite>("Protagonist/base_body.png", 3, sf::IntRect(0, 0, 87, 152));
    getComponent<AnimatedSprite>().addLayer("Protagonist/base_head.png", Layer_Type_HEAD);
    addComponent<Camera>(CameraType::FOLLOW);
    addComponent<AnimatedMovement>(true);
    addComponent<Inventory>();
    LevelManager::Instance()->setPlayer(this);
}

/************************************************************************
 * FUNCTION :       Player::handleInput
 *
 * DESCRIPTION :
 *       Handle mouse input
 *
 *  INPUTS:  sf::Mouse::Button button | button pressed
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.09 	    JCB     Documentation Start
 *
 ************************************************************************/

void Player::handleInput(sf::Mouse::Button button)
{
    Item* itm = getComponent<Inventory>().item(getComponent<Inventory>().activeItem());
    if (itm->type() == Item_Tool)
        itm->activate();

    Entity::handleInput(button);
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
    return getComponent<AnimatedSprite>().getSprite()->getGlobalBounds();
}