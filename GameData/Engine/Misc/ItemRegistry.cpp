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
}

Item* ItemRegistry::getItem(const uint16_t id)
{
    auto &itemMap = sInstance->items;
    auto pairFound = itemMap.find(id);

    if (pairFound != itemMap.end())
        return pairFound->second;
    else
        return nullptr;
}