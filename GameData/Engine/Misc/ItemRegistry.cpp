#include "ItemRegistry.h"

ItemRegistry* ItemRegistry::m_Instance = nullptr;

ItemRegistry* ItemRegistry::Instance()
{
    if (m_Instance == nullptr)
        m_Instance = new ItemRegistry();

    return m_Instance;
}

void ItemRegistry::createItem(Item* i)
{
    assert(i);
    assert(m_Instance);
    dbg_log("Item Registry: Creating item '" << i->name() << "'");
    auto &itemMap = m_Instance->items;
    itemMap.insert(std::make_pair(i->id(), *i));
}

Item* ItemRegistry::getItem(uint16_t id)
{
    assert(m_Instance);
    auto &itemMap = m_Instance->items;

    auto pairFound = itemMap.find(id);

    if (pairFound != itemMap.end())
        return &pairFound->second;
    else
        return nullptr;
}
