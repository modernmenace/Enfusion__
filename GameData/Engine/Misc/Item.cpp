#include "Item.h"

/*
 *   Item
 *
 *   Description: All item related functionality goes here
 *
 */

Item::Item(uint16_t id, string_t name, string_t description, string_t icon)
{
    this->i_id     = id;
    this->i_name   = name;
    this->i_desc   = description;
    this->i_icon   = icon;
}

void Item::activate()
{
    //TODO: Implement this
}
