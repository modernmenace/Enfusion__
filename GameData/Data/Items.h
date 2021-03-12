#ifndef ENFUSION___ITEMS_H
#define ENFUSION___ITEMS_H

#include "../Engine/Item/Item.h"
#include "../Engine/Item/ItemRegistry.h"

CREATE_ITEM(ITEM_TOMATO, "Tomato",
            "A tasty fruit. Or is it a vegetable? A tasty vegetable.",
            "Objects/Consumables/tomato.png",
            {
                dbg_log("Used a tomato!");
            }, Item_Consumable, 16);

CREATE_ITEM(ITEM_AXE, "Axe", "Used for chopping",
            "Objects/Tools/Tool_Axe.png",
            {
                        dbg_log("Axe used!")
            }, Item_Weapon, 1);

CREATE_ITEM(ITEM_TOP001, "Top001", "Test Top",
            "Protagonist/Equipment/Top/top001_icon.png",
            {}, Item_Clothing_Top, 1);

static void generateItemRegistry()
{
    REGISTRY_ADD(ITEM_TOMATO)
    REGISTRY_ADD(ITEM_AXE)
    REGISTRY_ADD(ITEM_TOP001)

    LINKED_TEXTURE(ITEM_AXE, "Protagonist/Equipment/Weapon/axe.png")
    LINKED_TEXTURE(ITEM_TOP001,     "Protagonist/Equipment/Top/top001.png")

    //CLOTHING_STATS() //todo: add stats to clothing and weapons

    dbg_log("Item Registry Generation Finished")
}

#endif //ENFUSION___ITEMS_H
