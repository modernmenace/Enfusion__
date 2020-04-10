#ifndef ENFUSION___ITEMS_H
#define ENFUSION___ITEMS_H

#include "../Engine/Misc/Item.h"
#include "../Engine/Misc/ItemRegistry.h"

#define ITEM_ID_TOMATO 1

CREATE_ITEM(ITEM_ID_TOMATO, IT_1, "tomato",
            "A tasty fruit. Or is it a vegetable? A tasty vegetable.",
            "Objects/Consumables/tomato.png",
            {
                dbg_log("Used a tomato!")
            }, 16);


static void generateItemRegistry()
{
    REGISTRY_ADD(IT_1)

    dbg_log("Item Registry Generation Finished")
}

#endif //ENFUSION___ITEMS_H
