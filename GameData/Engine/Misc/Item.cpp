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