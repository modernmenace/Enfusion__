#ifndef ENFUSION___INVENTORY_H
#define ENFUSION___INVENTORY_H

#include "../Component.h"
#include "../../Misc/Item.h"

#define INVENTORY_SIZE 24

/*
 *  Inventory Component
 *
 *  Core of inventory system
 *
 *
 */

//TODO: convert this to class
struct Slot
{
    Item* item = nullptr;
    sf::Sprite sprite;
};

class Inventory : public Component {

public:
    Inventory();

};


#endif //ENFUSION___INVENTORY_H
