#include "ItemPickup.h"
#include "../../Engine/Lvl/LevelManager.h"
#include "../../Engine/Component/Anim/AnimatedSprite.h"
#include "../../Engine/Component/Base/Collider.h"

ItemPickup::ItemPickup(Item *item, uint8_t count)
{
    p_item = item;
    p_count = count;
    create();
}

void ItemPickup::create()
{
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
    {
        if (getComponent<Collider>().checkForCollision(LevelManager::Instance()->getCurrentLevel().player()))
            pickup();
    }
}

void ItemPickup::pickup()
{
    LevelManager::Instance()->getCurrentLevel().player()->getComponent<Inventory>().add(p_item, p_count);
    LevelManager::Instance()->getCurrentLevel().removeEntity(this);
    delete this;
}