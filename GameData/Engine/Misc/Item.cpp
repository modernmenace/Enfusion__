#include "Item.h"

/*
 *   Item
 *
 *   Description: All item related functionality goes here
 *
 */

ItemEffect::ItemEffect(Item *it)
{
    this->item = it;
}

void ItemEffect::onUse() { /* overridden */ }

void IE_HealPlayer5::onUse()
{
    dbg_log("healing player 5")
}