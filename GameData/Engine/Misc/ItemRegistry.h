#ifndef ENFUSION___ITEMREGISTRY_H
#define ENFUSION___ITEMREGISTRY_H

#include "../Core/Engine.h"
#include "Item.h"
#include <map>

//TODO: Convert this entire thing to use templates

class ItemRegistry {

public:
    static ItemRegistry* Instance();
    void createItem(Item* i);

    template <typename It>
    Item* getItem(uint16_t id)
    {
        assert(m_Instance);
        auto &itemMap = m_Instance->items;

        auto pairFound = itemMap.find(id);

        if (pairFound != itemMap.end())
            return static_cast<It*>(pairFound->second);
        else
            return nullptr;
    }

private:
    ItemRegistry() {};

    static ItemRegistry* m_Instance;


    std::map<uint16_t, Item*> items;
};


#endif //ENFUSION___ITEMREGISTRY_H
