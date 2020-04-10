#include "Inventory.h"
#include "../../../Data/Items.h"

//TODO: Test this and stacks etc.

void Inventory::initialize()
{
    this->add(ItemRegistry::Instance()->getItem(ITEM_ID_TOMATO));

    for(uint8_t i = 0; i < INVENTORY_SIZE; i++)
    {
        inv_items[i]   = nullptr;
        inv_amounts[i] = 0;
    }

}

uint8_t Inventory::nextEmptySlot()
{
    //iterate array and return next empty slot
    for(uint8_t i; i < INVENTORY_SIZE; i++)
        if (inv_amounts[i] == 0)
            return i;

    return INVENTORY_FULL;
}

bool Inventory::add(Item* item)
{
    if (item == nullptr) return false;

    //check if value exists
    //this does not allow for more than two stacks, replace itemExists
    //with for loops for each one found?
    int16_t itemExists = -1;
    for(uint8_t i; i < INVENTORY_SIZE; i++)
    {
        //this does not allow for more than two stacks
        if (inv_items[i]->id() == item->id())
        {
            itemExists = true;
            break;
        }
    }

    if (itemExists < 0)
    {
        //item not found
        uint8_t slot = nextEmptySlot();
        if (slot == INVENTORY_FULL) return false;

        inv_items[slot]   = item;
        inv_amounts[slot] = 1;
    }
    else
    {
        //item exists in inventory
        if (inv_amounts[itemExists] < inv_items[itemExists]->stackSize())
            inv_amounts[itemExists]++;

        else
        {
            //create new stack
            uint8_t slot = nextEmptySlot();
            if (slot == INVENTORY_FULL) return false;

            inv_items[slot]   = item;
            inv_amounts[slot] = 1;
        }
    }
    return true;
}