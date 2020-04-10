#include "Inventory.h"
#include "../../../Data/Items.h"

//TODO: Test this and stacks etc.

void Inventory::initialize()
{
    this->add(ItemRegistry::Instance()->getItem(ITEM_ID_TOMATO));
}

void Inventory::add(Item* item)
{
    if (item == nullptr) return;

    if (inv_items.size() >= INVENTORY_SIZE)
    {
        dbg_err("Inventory Overflow")
        return;
    }

    //check if value exists
    int16_t itemExists = -1;
    for(auto it = inv_items.begin(); it != inv_items.end(); it++)
    {
        //this does not allow for more than two stacks
        if (it->second->id() == item->id())
        {
            itemExists = true;
            break;
        }
    }

    if (itemExists < 0)
    {
        //item not found
        inv_items.insert(std::make_pair(inv_items.size(), item));
        inv_amounts.insert(std::make_pair(inv_items.size(), 1));
    }
    else
    {
        //item exists in inventory
        if (inv_amounts.at(itemExists) < inv_items.at(itemExists)->stackSize())
            inv_amounts.at(itemExists)++;

        else
        {
            //create new stack
            inv_items.insert(std::make_pair(inv_items.size(), item));
            inv_amounts.insert(std::make_pair(inv_items.size(), 0));
        }
    }
}