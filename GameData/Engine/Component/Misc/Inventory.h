#ifndef ENFUSION___INVENTORY_H
#define ENFUSION___INVENTORY_H

#include "../Component.h"
#include "../../Misc/Item.h"
#include <map>

#define INVENTORY_SIZE 24
#define INVENTORY_FULL 255

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
    bool add(Item* item);

private:
    Item*   inv_items  [INVENTORY_SIZE];
    uint8_t inv_amounts[INVENTORY_SIZE];

    uint8_t nextEmptySlot();

};


#endif //ENFUSION___INVENTORY_H
