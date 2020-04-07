#include "ItemRegistry.h"

ItemRegistry* ItemRegistry::m_Instance = nullptr;

ItemRegistry* ItemRegistry::Instance()
{
    if (m_Instance == nullptr)
        m_Instance = new ItemRegistry();

    return m_Instance;
}

ItemRegistry::ItemRegistry()
{
    // do I need anything here with the new format?
}


void ItemRegistry::createItem(Item* i)
{
    assert(m_Instance != nullptr);
    //auto &itemMap = sInstance->items;
    //itemMap.insert(std::make_pair(i->id(), i));
}

Item* ItemRegistry::getItem(uint16_t id)
{
    assert(m_Instance != nullptr);
    //auto &itemMap = sInstance->items;
    // below line causes crashing
    // print also does, itemMap not created yet?

    //dbg_log(itemMap.size())
    //auto pairFound = itemMap.find(id);

    //if (pairFound != itemMap.end())
        //return pairFound->second;
    //else
        return nullptr;
}
