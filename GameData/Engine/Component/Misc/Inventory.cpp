#include "Inventory.h"
#include "../../../Data/Items.h"

Inventory::Inventory()
{
    dbg_log("got here")
    // this line below breaks things
    //this->add(ItemRegistry::getItem(ITEM_ID_TOMATO));
}

void Inventory::add(Item* item)
{
    if (inv_count >= INVENTORY_SIZE)
    {
        dbg_err("Inventory Overflow")
        return;
    }

    inv_items.insert(std::make_pair(inv_count+1, item));
    inv_count++;
}