#include "ItemPickup.h"
#include <functional>
#include "../../Lvl/LevelManager.h"
#include "../../Component/Anim/AnimatedSprite.h"
#include "../../Component/Base/Collider.h"

//TODO: These are dynamically allocated, ensure they are properly deleted

ItemPickup::ItemPickup(Item *item)
{
    p_item = item;
    create();
}

void ItemPickup::create()
{
    dbg_log("creating item pickup")
    auto p_pos = LevelManager::Instance()->getCurrentLevel().player()->getComponent<Position>().getPosition();
    p_pos.x += LevelManager::Instance()->getCurrentLevel().player()->getComponent<AnimatedSprite>().bounds().width / 2;
    p_pos.y += LevelManager::Instance()->getCurrentLevel().player()->getComponent<AnimatedSprite>().bounds().height / 2;
    addComponent<Position>(p_pos);
    addComponent<Sprite>(p_item->icon());
    addComponent<Collider>(sf::FloatRect(p_pos.x, p_pos.y, 10, 10));
}

void ItemPickup::handleInput(sf::Keyboard::Key key)
{
    Entity::handleInput(key);

    if (key == 4)
        if (getComponent<Collider>().checkForCollision(LevelManager::Instance()->getCurrentLevel().player()))
            pickup( d);
}

void ItemPickup::pickup()
{
    dbg_log("Picking up item")
}