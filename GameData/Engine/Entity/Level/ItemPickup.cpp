#include "ItemPickup.h"

ItemPickup::ItemPickup(Item *item)
{
    p_item = item;
    create();
}

void ItemPickup::create()
{
    dbg_log("creating item pickup")
    
}