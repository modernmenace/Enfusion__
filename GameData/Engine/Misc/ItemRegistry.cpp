#include "ItemRegistry.h"

ItemRegistry* ItemRegistry::sInstance = nullptr;

ItemRegistry::ItemRegistry()
{
    assert(sInstance == nullptr);
    sInstance = this;
}

void ItemRegistry::createItem(Item* i)
{
    auto &itemMap = sInstance->items;
    itemMap.insert(std::make_pair(i->id(), i));
    dbg_log("creating item " << i->id() << ", " << i->name())
}

Item* ItemRegistry::getItem(const uint16_t id)
{
    auto pairFound = items.find(id);

    if (pairFound != items.end())
        return pairFound->second;
    else
        return nullptr;
}