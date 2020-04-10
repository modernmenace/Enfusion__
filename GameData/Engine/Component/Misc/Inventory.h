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
    Inventory();
    void initialize() override;
    void add(Item* item);

private:
    std::map<uint8_t, Item*> inv_items;
    uint16_t                  inv_count = 0;

};


#endif //ENFUSION___INVENTORY_H
