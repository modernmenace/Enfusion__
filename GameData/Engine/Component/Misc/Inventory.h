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
    Inventory();
    void initialize() override;
    bool add(Item* item);

    inline Item* item(uint8_t id) { return inv_items[id]; }

//private:
    Item*   inv_items  [INVENTORY_SIZE];
    int     inv_amounts[INVENTORY_SIZE];

    int nextEmptySlot();

};


#endif //ENFUSION___INVENTORY_H
