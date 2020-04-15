#include "Item.h"

/*
 *   Item
 *
 *   Description: All item related functionality goes here
 *
 */

Item::Item(string_t name, string_t description, string_t icon, uint16_t stackSize)
{
    static uint16_t id = 0;

    this->i_id     = id;
    this->i_name   = name;
    this->i_desc   = description;
    this->i_icon   = icon;
    this->i_max    = stackSize;

    id++;
}


void Item::activate()
{
    dbg_err("Default item activation triggered for item '"
    << i_id << "': '" << i_name << "'")
}
