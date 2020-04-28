#ifndef ENFUSION___ITEMPICKUP_H
#define ENFUSION___ITEMPICKUP_H

#include "../Entity.h"
#include "../../Misc/Item.h"

class ItemPickup : Entity {

public:
    ItemPickup(Item* item);

private:
    void create();

    Item* p_item = nullptr;

};


#endif //ENFUSION___ITEMPICKUP_H
