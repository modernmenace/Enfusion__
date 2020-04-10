#include "Inventory.h"
#include "../../../Data/Items.h"

Inventory::Inventory()
{

}

void Inventory::initialize()
{
    this->add(ItemRegistry::Instance()->getItem(ITEM_ID_TOMATO));

    dbg_log("Begin Display Inventory Items");
    dbg_log("Inv Size: " << inv_items.size() << ", " << inv_count);
    // below causes crashing, probably item is not permanently allocated
    /*
    for(int i = 0; i < inv_items.size(); i++)
    {
        dbg_log(inv_items[i]->name());
    }
     */
}

void Inventory::add(Item* item)
{
    dbg_log("Adding item");
    if (item == nullptr)
    {
        dbg_err("item is null");
        return;
    }
    if (inv_count >= INVENTORY_SIZE)
    {
        dbg_err("Inventory Overflow")
        return;
    }

    inv_items.insert(std::make_pair(inv_count+1, item));
    inv_count++;
}