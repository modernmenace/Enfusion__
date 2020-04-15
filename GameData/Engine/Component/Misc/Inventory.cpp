#include "Inventory.h"
#include "../../../Data/Items.h"

//TODO | Test this
//TODO | Cases: Multiple of same item, multiple stacks, etc.
//TODO | Anticipating errors with templates

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
    this->add(ItemRegistry::Instance()->getItem<ITEM_TEST>());
    this->add(ItemRegistry::Instance()->getItem<ITEM_TEST>());

    //testing below function
    dbg_log(contains<ITEM_TEST>());
}

//TODO: Implement this
bool Inventory::remove(Item* item, uint16_t amount)
{
    dbg_log("Inventory.cpp: remove() called!")
    return true;
}

int Inventory::nextEmptySlot()
{
    //iterate array and return next empty slot
    for(int i = 0; i < INVENTORY_SIZE; i++)
        if (inv_amounts[i] == 0)
            return i;

    return INVENTORY_FULL;
}
