#include "Item.h"

/*
 *  Item Base Class
 *
 *
 */

Item::Item(std::string name, std::string description, std::string sprite, uint16_t value)
{
    i_name = name;
    i_desc = description;
    i_value = value;
    addComponent<Sprite>(sprite);
}