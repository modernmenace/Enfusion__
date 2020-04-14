#ifndef ENFUSION___ITEMREGISTRY_H
#define ENFUSION___ITEMREGISTRY_H

#include "../Core/Engine.h"
#include "Item.h"
#include <map>

class ItemRegistry {

public:
    static ItemRegistry* Instance()
    {
        if (m_Instance == nullptr)
            m_Instance = new ItemRegistry();

        return m_Instance;
    }

    void createItem(Item* i)
    {
        assert(i);
        assert(m_Instance);
        dbg_log("Item Registry: Creating item '" << i->name() << "'");
        m_Instance->items.push_back(i);
    }

    template <typename It>
    Item* getItem()
    {
        assert(m_Instance);

        for(Item* i : items)
        {
            auto ptr2 = i;
            if (dynamic_cast<It*>(ptr2))
                return ptr2;
        }
        return nullptr;
    }

private:
    ItemRegistry() {};
    static ItemRegistry* m_Instance;
    std::vector<Item*> items;
};

#endif //ENFUSION___ITEMREGISTRY_H
