#include "Item.h"

/*
 *   Item
 *
 *   Description: All item related functionality goes here
 *
 */

//TODO: Deal with ids
//TODO: Make item creation macros

Item::Item(string_t name, string_t description, string_t icon, ItemEffect *effect)
{
    this->i_name   = name;
    this->i_desc   = description;
    this->i_icon   = icon;
    this->i_effect = effect;
}

void Item::activate()
{
    if (i_effect != nullptr)
        i_effect->onUse();
}

ItemEffect::ItemEffect(Item *it)
{
    this->item = it;
}

void ItemEffect::onUse() { /* overridden */ }