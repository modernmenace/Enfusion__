#include "Inventory.h"
#include "../../../Data/Items.h"

/*
 *  Inventory
 *  DESC: Handles item storage
 *
 *  REQUIRES: NONE
 *
 */

Inventory::Inventory()
{
    for(uint8_t i = 0; i < INVENTORY_SIZE; i++)
    {
        inv_items[i]   = nullptr;
        inv_amounts[i] = 0;
    }
}

void Inventory::initialize()
{
    this->add(ItemRegistry::Instance()->getItem<ITEM_TOMATO>());
    this->add(ItemRegistry::Instance()->getItem<ITEM_TEST>(), 16);
}

void Inventory::remove(Item* item, uint16_t amount)
{
    if (lastItemActivated >= 0)
    {
        inv_amounts[lastItemActivated] -=1;
        if (inv_amounts[lastItemActivated] == 0)
            inv_items[lastItemActivated] = nullptr;
    }
}

void Inventory::remove(uint16_t index)
{
    //TODO: this
}

int Inventory::nextEmptySlot()
{
    //iterate array and return next empty slot
    for(int i = 0; i < INVENTORY_SIZE; i++)
        if (inv_amounts[i] == 0)
            return i;

    return INVENTORY_FULL;
}
