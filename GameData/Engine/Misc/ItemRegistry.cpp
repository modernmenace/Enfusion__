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
    auto &i_vec = m_Instance->items;
    i_vec.push_back(i);
}

