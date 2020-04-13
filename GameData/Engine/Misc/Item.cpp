#include "Item.h"

/*
 *   Item
 *
 *   Description: All item related functionality goes here
 *
 */

Item::Item(uint16_t id, string_t name, string_t description, string_t icon, uint16_t stackSize)
{
    this->i_id     = id;
    this->i_name   = name;
    this->i_desc   = description;
    this->i_icon   = icon;
    this->i_max    = stackSize;
}


void Item::activate()
{
    dbg_log("Item '" << i_name << "' used default activation function");
}
