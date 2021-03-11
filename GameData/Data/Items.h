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
            }, Item_Tool, 1);

static void generateItemRegistry()
{
    REGISTRY_ADD(ITEM_TOMATO)
    REGISTRY_ADD(ITEM_AXE)

    LINKED_TEXTURE(ITEM_AXE, "Protagonist/axe.png")

    dbg_log("Item Registry Generation Finished")
}

#endif //ENFUSION___ITEMS_H
