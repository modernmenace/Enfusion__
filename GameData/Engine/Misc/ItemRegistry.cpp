#include "ItemRegistry.h"

ItemRegistry* ItemRegistry::sInstance = nullptr;

ItemRegistry::ItemRegistry()
{
    assert(sInstance == nullptr);
    sInstance = this;
}

void ItemRegistry::createItem(Item i)
{
    //TODO: create this
}

Item* ItemRegistry::getItem(const uint16_t id)
{
    auto pairFound = items.find(id);

    if (pairFound != items.end())
        return &pairFound->second;
    else
        return nullptr;
}