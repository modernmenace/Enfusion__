#include "Inventory.h"
#include "../Data/Items.h"
#include "../Engine/Lvl/LevelManager.h"
#include "../Entity/Level/ItemPickup.h"

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

void Inventory::swapItem(uint16_t i1, uint16_t i2)
{
    auto i1_i = inv_items[i1];
    auto i1_a = inv_amounts[i1];
    inv_items[i1]   = inv_items[i2];
    inv_amounts[i1] = inv_amounts[i2];
    inv_items[i2]   = i1_i;
    inv_amounts[i2] = i1_a;
    changeFlag = true;
}

void Inventory::remove(Item* item, uint16_t amount)
{
    if (lastItemActivated >= 0)
    {
        inv_amounts[lastItemActivated] -=1;
        if (inv_amounts[lastItemActivated] == 0)
            inv_items[lastItemActivated] = nullptr;
        changeFlag = true;
    }
}

void Inventory::remove(uint16_t index)
{
    LevelManager::Instance()->getCurrentLevel().addEntity(new ItemPickup(inv_items[index], inv_amounts[index]));
    inv_items[index]   = nullptr;
    inv_amounts[index] = 0;
    changeFlag = true;
}

int Inventory::nextEmptySlot()
{
    //iterate array and return next empty slot
    for(int i = 0; i < INVENTORY_SIZE; i++)
        if (inv_amounts[i] == 0)
            return i;

    return INVENTORY_FULL;
}

bool Inventory::changePending()
{
    if (changeFlag)
    {
        changeFlag = false;
        return true;
    }
    return false;
}