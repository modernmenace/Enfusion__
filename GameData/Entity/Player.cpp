#include "Player.h"
#include "../Engine/Component/Anim/AnimatedSprite.h"
#include "../Engine/Component/Base/Position.h"
#include "../Engine/Component/Motion/AnimatedMovement.h"
#include "../Engine/Component/Misc/Camera.h"
#include "../Component/Inventory.h"
#include "../Engine/Lvl/LevelManager.h"
#include "../Engine/Item/ItemRegistry.h"
#include "../Data/Items.h"

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
 * FUNCTION :       Player::initialize
 *
 * DESCRIPTION :
 *       Set starting equipment
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.13 	    JCB     Documentation Start
 *
 ************************************************************************/

void Player::initialize()
{
    equipItem(ItemRegistry::Instance()->getItem<ITEM_TOP001>());
    equipItem(ItemRegistry::Instance()->getItem<ITEM_BOTTOM001>());
    Inventory* inv = &getComponent<Inventory>();
    inv->add(ItemRegistry::Instance()->getItem<ITEM_AXE>());
    inv->add(ItemRegistry::Instance()->getItem<ITEM_TOMATO>(), 4);
    Entity::initialize();
}

/************************************************************************
 * FUNCTION :       Player::equipItem
 *
 * DESCRIPTION :
 *       Equip item, note that this is just visual as of now and weapons
 *       are not actually stored anywhere yet
 *
 *  INPUTS:  Item* itm   |  The item to be equipped
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.12 	    JCB     Documentation Start
 *
 ************************************************************************/

void Player::equipItem(Item* itm)
{
    switch (itm->type())
    {
        case Item_Weapon:
            getComponent<AnimatedSprite>().addLayer(itm->linkedTexture(), Layer_Type_WEAPON);
            p_equipment.weapon = itm;
            break;
        case Item_Clothing_Head:
            getComponent<AnimatedSprite>().addLayer(itm->linkedTexture(), Layer_Type_HEAD);
            p_equipment.head = itm;
            break;
        case Item_Clothing_Top:
            getComponent<AnimatedSprite>().addLayer(itm->linkedTexture(), Layer_Type_TOP);
            p_equipment.top = itm;
            break;
        case Item_Clothing_Bottom:
            getComponent<AnimatedSprite>().addLayer(itm->linkedTexture(), Layer_Type_BOTTOM);
            p_equipment.bottom = itm;
            break;
        default:
            break;
    }
}

/************************************************************************
 * FUNCTION :       Player::unequipItem
 *
 * DESCRIPTION :
 *       Unequip item, note that this is just visual as of now and weapons
 *       are not actually stored anywhere yet
 *
 *  INPUTS:  ItemType type   |  The type of item to be unequipped
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.12 	    JCB     Documentation Start
 *
 ************************************************************************/

void Player::unequipItem(ItemType type)
{
    switch (type)
    {
        case Item_Weapon:
            getComponent<AnimatedSprite>().removeLayer(Layer_Type_WEAPON);
            p_equipment.weapon = nullptr;
            break;
        case Item_Clothing_Head:
            getComponent<AnimatedSprite>().removeLayer(Layer_Type_HEAD);
            p_equipment.head = nullptr;
            break;
        case Item_Clothing_Top:
            getComponent<AnimatedSprite>().removeLayer(Layer_Type_TOP);
            p_equipment.top = nullptr;
            break;
        case Item_Clothing_Bottom:
            getComponent<AnimatedSprite>().removeLayer(Layer_Type_BOTTOM);
            p_equipment.bottom = nullptr;
            break;
        default:
            break;
    }
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
    if (itm->type() == Item_Weapon)
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