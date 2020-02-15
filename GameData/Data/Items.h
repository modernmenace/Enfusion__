#ifndef ENFUSION___ITEMS_H
#define ENFUSION___ITEMS_H

#include "../Engine/Misc/Item.h"
#include "ItemEffects.h"
#include "../Engine/Misc/ItemRegistry.h"

CREATE_ITEM(1, IT_1, "tomato", "A tasty fruit. Or is it a vegetable? A tasty vegetable.",
            "Objects/Consumables/tomato.png",
            {
                dbg_log("Used a tomato!")
            });


static void generateItemRegistry()
{
    REGISTRY_ADD(IT_1)
}

#endif //ENFUSION___ITEMS_H
