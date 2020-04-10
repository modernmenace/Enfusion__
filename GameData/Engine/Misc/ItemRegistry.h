#ifndef ENFUSION___ITEMREGISTRY_H
#define ENFUSION___ITEMREGISTRY_H

#include "../Core/Engine.h"
#include "Item.h"
#include <map>


class ItemRegistry {

public:
    static ItemRegistry* Instance();
    void createItem(Item* i);
    Item* getItem(uint16_t id);

private:
    ItemRegistry() {};

    static ItemRegistry* m_Instance;
    std::map<uint16_t, Item> items;
};


#endif //ENFUSION___ITEMREGISTRY_H
