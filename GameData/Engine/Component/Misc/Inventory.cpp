#include "Inventory.h"
#include "../../../Data/Items.h"

void Inventory::initialize()
{
    this->add(ItemRegistry::Instance()->getItem(ITEM_ID_TOMATO));
}

void Inventory::add(Item* item)
{
    if (item == nullptr) return;

    //TODO | check if item is in inventory
    //TODO | if not, add it ; otherwise check if should be stacked
    //TODO | or begin new stack

    if (inv_items.size() >= INVENTORY_SIZE)
    {
        dbg_err("Inventory Overflow")
        return;
    }

    inv_items.insert(std::make_pair(inv_items.size(), item));
}