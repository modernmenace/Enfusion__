#ifndef ENFUSION___INVENTORY_H
#define ENFUSION___INVENTORY_H

#include "../Component.h"
#include "../../Misc/Item.h"
#include <map>

#define INVENTORY_SIZE 24
#define INVENTORY_FULL 255

/*
 *  Inventory Component
 *
 *  Core of inventory system
 *
 *
 */

class Inventory : public Component {

private:
    Item*   inv_items  [INVENTORY_SIZE];
    int     inv_amounts[INVENTORY_SIZE];

    int nextEmptySlot();

public:
    Inventory();
    void initialize() override;

    template<class It>
    bool add(It* item)
    {
        if (item == nullptr) return false;

        //check if value exists
        //TODO | this does not allow for more than two stacks,
        //TODO | replace itemExists with for loops for each one found?
        int16_t itemExists = -1;
        for(uint8_t i = 0; i < INVENTORY_SIZE; i++)
        {
            //this does not allow for more than two stacks
            if (inv_items[i] != nullptr)
            {
                if (inv_items[i]->id() == item->id())
                {
                    itemExists = true;
                    break;
                }
            }
        }

        if (itemExists < 0)
        {
            //item not found
            int slot = nextEmptySlot();
            if (slot == INVENTORY_FULL) return false;
            inv_items[slot]   = item;
            inv_amounts[slot] = 1;
        }
        else
        {
            //item exists in inventory
            if (inv_amounts[itemExists] < inv_items[itemExists]->stackSize())
                inv_amounts[itemExists]++;

            else
            {
                //create new stack
                uint8_t slot = nextEmptySlot();
                if (slot == INVENTORY_FULL) return false;

                inv_items[slot]   = item;
                inv_amounts[slot] = 1;
            }
        }
        return true;
    }

    //returns amount of item in inventory
    template <class It>
    int contains()
    {
        int amt = 0;
        for(int i = 0; i < INVENTORY_SIZE; i++)
        {
            auto ptr2 = inv_items[i];
            if (dynamic_cast<It*>(ptr2)) amt += inv_amounts[i];
        }

        return amt;
    }

    //TODO: Remove Function
    template <class It>
    bool remove(uint16_t amount) { return true; }

    inline Item* item(uint8_t id) { return inv_items[id];   }
    inline int amount(uint8_t id) { return inv_amounts[id]; }
};


#endif //ENFUSION___INVENTORY_H
