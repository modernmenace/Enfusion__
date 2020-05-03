#include "ItemPickup.h"
#include "../../Lvl/LevelManager.h"
#include "../../Component/Anim/AnimatedSprite.h"

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
}