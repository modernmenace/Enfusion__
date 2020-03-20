#ifndef ENFUSION___ITEMREGISTRY_H
#define ENFUSION___ITEMREGISTRY_H

#include "../Core/Engine.h"
#include "Item.h"
#include <map>

class ItemRegistry {

public:
    ItemRegistry();
    static Item* getItem(uint16_t id);
    static void createItem(Item* i);

private:
    void initialize();

    static ItemRegistry* sInstance;
    std::map<uint16_t, Item*> items;
};


#endif //ENFUSION___ITEMREGISTRY_H
