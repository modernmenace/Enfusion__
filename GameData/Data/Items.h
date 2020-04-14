#ifndef ENFUSION___ITEMS_H
#define ENFUSION___ITEMS_H

#include "../Engine/Misc/Item.h"
#include "../Engine/Misc/ItemRegistry.h"


CREATE_ITEM(ITEM_TOMATO, "Tomato",
            "A tasty fruit. Or is it a vegetable? A tasty vegetable.",
            "Objects/Consumables/tomato.png",
            {
                dbg_log("Used a tomato!");
            }, 16);

CREATE_ITEM(ITEM_TEST, "Test Item", "Test Description",
            "Objects/Consumables/testitem.png",
            {
                        dbg_log("This Is A Test Item!");
                    }, 16);


static void generateItemRegistry()
{
    REGISTRY_ADD(ITEM_TOMATO)
    REGISTRY_ADD(ITEM_TEST)

    dbg_log("Item Registry Generation Finished")
}

#endif //ENFUSION___ITEMS_H
