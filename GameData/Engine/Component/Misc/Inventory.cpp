#include "Inventory.h"
#include "../../../Data/Items.h"

//TODO: Test this and stacks etc.

Inventory::Inventory()
{
    for(uint8_t i = 0; i < INVENTORY_SIZE; i++)
    {
        inv_items[i]   = nullptr;
        inv_amounts[i] = 0;
    }
};

void Inventory::initialize()
{
    //adding item not item1
    //this->add(new IT_1());
    //turn below into template to fix this?
    // but how do i get class type?
    this->add(ItemRegistry::Instance()->getItem<IT_1>(ITEM_ID_TOMATO));
}

int Inventory::nextEmptySlot()
{
    //iterate array and return next empty slot
    for(int i = 0; i < INVENTORY_SIZE; i++)
        if (inv_amounts[i] == 0)
            return i;

    return INVENTORY_FULL;
}
