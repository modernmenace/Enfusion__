#ifndef ENFUSION___INVENTORY_H
#define ENFUSION___INVENTORY_H

#include "../Component.h"
#include "../../Misc/Item.h"
#include <map>

#define INVENTORY_SIZE 24

/*
 *  Inventory Component
 *
 *  Core of inventory system
 *
 *
 */

class Inventory : public Component {

public:
    Inventory() {};
    void initialize() override;
    void add(Item* item);

private:
    std::map<uint8_t, Item*>   inv_items;
    std::map<uint8_t, uint8_t> inv_amounts;

};


#endif //ENFUSION___INVENTORY_H
