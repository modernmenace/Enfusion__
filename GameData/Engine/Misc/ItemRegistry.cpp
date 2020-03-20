#include "ItemRegistry.h"

ItemRegistry* ItemRegistry::sInstance = nullptr;

ItemRegistry::ItemRegistry()
{
    assert(sInstance == nullptr);
    sInstance = this;
    dbg_log("generating registry")
}


void ItemRegistry::createItem(Item* i)
{
    assert(sInstance != nullptr);
    auto &itemMap = sInstance->items;
    itemMap.insert(std::make_pair(i->id(), i));
}

Item* ItemRegistry::getItem(uint16_t id)
{
    assert(sInstance != nullptr);
    auto &itemMap = sInstance->items;
    // below line causes crashing
    // print also does, itemMap not created yet?

    //dbg_log(itemMap.size())
    //auto pairFound = itemMap.find(id);

    //if (pairFound != itemMap.end())
        //return pairFound->second;
    //else
        return nullptr;
}