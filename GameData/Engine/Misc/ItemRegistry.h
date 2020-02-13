#ifndef ENFUSION___ITEMREGISTRY_H
#define ENFUSION___ITEMREGISTRY_H

#include "../Core/Engine.h"
#include "Item.h"
#include <map>

class ItemRegistry {

public:
    ItemRegistry();
    Item* getItem(const uint16_t id);
    void createItem(Item i);

private:
    static ItemRegistry* sInstance;
    std::map<uint16_t, Item> items;

};


#endif //ENFUSION___ITEMREGISTRY_H
