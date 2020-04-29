#include "ItemPickup.h"
#include "../../Lvl/LevelManager.h"

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
    addComponent<Position>(p_pos);
    addComponent<Sprite>(p_item->icon());
}